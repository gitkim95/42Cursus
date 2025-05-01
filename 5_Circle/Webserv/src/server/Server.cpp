/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:44:20 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/30 21:36:56 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <csignal>
#include <stdexcept>
#include <unistd.h>
#include "request/Request.hpp"
#include "response/Response.hpp"
#include "response/ResponseGenerator.hpp"
#include "server/CGI.hpp"
#include "utils/utils.hpp"

#include "server/Server.hpp"

/* private */
void Server::bindSocket(Socket *socket)
{
	int sockOpt = 1;

	if (setsockopt(socket->getFd(), SOL_SOCKET, SO_REUSEADDR, &sockOpt, sizeof(sockOpt)) < 0)
		throw std::runtime_error("setsockopt fail");
	setFdNonBlock(socket->getFd());
	if (bind(socket->getFd(), (struct sockaddr *)&socket->getAddr(), sizeof(socket->getAddr())) < 0)
		throw std::runtime_error("bind fail");
	if (listen(socket->getFd(), CLIENT_MAX) < 0)
		throw std::runtime_error("listen fail");
}

void Server::acceptClient(int servFd)
{
	int sock;
	struct sockaddr_in addr;
	socklen_t addrSize;

	addrSize = sizeof(addr);
	sock = accept(servFd, (struct sockaddr *)&addr, &addrSize);
	if (sock < 0)
		return;

	Client *client = new Client(servers[servFd], sock, addr);
	if (!client)
	{
		close(sock);
		return;
	}
	if (client->error() || (epCtl(this->epfd, EPOLL_CTL_ADD, sock, EPOLLIN | EPOLLOUT) < 0))
	{
		delete (client);
		return;
	}
	this->clients[sock] = client;
}

void Server::requestClient(int clntFd)
{
	Client *client = this->clients[clntFd];
	Request &request = client->getRequest();
	unsigned char buffer[BUFSIZ];
	ssize_t readBytes;

	readBytes = recv(clntFd, buffer, BUFSIZ, MSG_DONTWAIT);
	if (readBytes > 0)
	{
		std::cout << "client fd: " << client->getClntSocket().getFd() << " recv " << readBytes << " bytes" << std::endl;
		client->getReqBuffer().insert(client->getReqBuffer().end(), buffer, buffer + readBytes);
	}
	else if (readBytes == 0)
	{
		this->removeClient(clntFd);
		return;
	}

	if (request.getMethod().empty())
	{
		request.parseHeaderField(client, this->getMetaConfig());
		if (request.getMethod() == RequestMethod::POST)
			extractHeader(client->getReqBuffer());
		else
			client->setIsReqParsed(true);
	}
	if (client->isRequestValid())
	{
		request.parseBodyField(client);
		client->setIsReqParsed(true);
	}
	if (client->getIsReqParsed() == true)
	{
		client->setPathType(request.checkPathType(client));
		std::cout << "\nclient fd: " << client->getClntSocket().getFd() << std::endl;
		std::cout << request << std::endl;

		if (client->getPathType() == DYNAMIC_FILE)
		{
			this->runCGI(client);
			return;
		}
		else
		{
			std::string method = request.getMethod();
			if (method == RequestMethod::POST && client->getPathType() == CREATED)
				postFile(request);
			else if (method == RequestMethod::DELETE)
				deleteFile(request.getFilePath());
			CharVec fileData = ResponseGenerator::getFileData(client);
			client->setResponse(ResponseGenerator::getResponseData(client, fileData));
		}
		client->ready();
	}
}

void Server::postFile(const Request &request)
{
	std::map<std::string, CharVec>::const_iterator it;
	std::map<std::string, CharVec> fileData = request.getBody().getFileData();
	std::string filePath = request.getFilePath();

	for (it = fileData.begin(); it != fileData.end(); ++it)
	{
		std::string fullPath = filePath + "/" + it->first;
		std::ofstream ofs(fullPath.c_str(), std::ios::binary);
		ofs.write(reinterpret_cast<const char *>(&it->second[0]), it->second.size());
		ofs.close();
	}
}

void Server::deleteFile(const std::string &filePath)
{
	std::remove(filePath.c_str());
}

void Server::runCGI(Client *client)
{
	const Request &request = client->getRequest();
	int in[2];
	int out[2];

	client->getReqBuffer().clear();

	if (pipe(in) < 0)
		return;
	if (pipe(out) < 0)
	{
		closePipes(in);
		return;
	}
	setFdNonBlock(in);
	setFdNonBlock(out);

	if (CGI::execute(client, in, out) < 0)
		return;

	if (request.getMethod() != RequestMethod::POST)
		closePipes(in);
	else
	{
		close(in[0]);
		epCtl(this->epfd, EPOLL_CTL_ADD, in[1], EPOLLIN | EPOLLOUT);
		this->cgiIn[in[1]] = request.getBody().getContent();
	}
	close(out[1]);
	epCtl(this->epfd, EPOLL_CTL_ADD, out[0], EPOLLIN | EPOLLOUT);
	client->increaseRefCount();
	this->cgiOut[out[0]] = client;
}

void Server::response(int clntFd)
{
	Client *client = this->clients[clntFd];
	Request &request = client->getRequest();
	Response &response = client->getResponse();
	CharVec bin;

	if (!client->isReady())
		return;

	if (response.isOK())
	{
		if (this->session.isSessionRequest(request.getFilePath()))
			response.setSessionBody(this->session, request);
		this->processSessionAndCookies(request, response);
	}
	bin = response.toBinary();

	ssize_t sendBytes = send(clntFd, reinterpret_cast<const char *>(&bin[response.getSendIdx()]), bin.size(), MSG_DONTWAIT);
	if (sendBytes < 0)
		return;
	std::cout << "to clinet: " << client->getClntSocket().getFd() << ", send " << sendBytes << " bytes" << std::endl;
	response.increaseSendIdx(sendBytes);
	if (response.getSendIdx() < (ssize_t)bin.size())
		return;
	if (epCtl(this->epfd, EPOLL_CTL_DEL, clntFd, 0))
		std::cerr << clntFd << " ep fail" << std::endl;
	this->removeClient(clntFd);
}

void Server::writeToCGI(int pipeWrite)
{
	CharVec &content = this->cgiIn[pipeWrite];
	ssize_t sendBytes;

	std::cout << "write to " << pipeWrite << std::endl;
	sendBytes = write(pipeWrite, &content[0], content.size());
	if (sendBytes < 0)
		return;
	if (sendBytes != (ssize_t)content.size())
	{
		content.erase(content.begin(), content.begin() + sendBytes);
		return;
	}

	epCtl(this->epfd, EPOLL_CTL_DEL, pipeWrite, 0);
	close(pipeWrite);
	this->cgiIn.erase(pipeWrite);
}

void Server::readFromCGI(int pipeRead)
{
	Client *client = this->cgiOut[pipeRead];
	if (!client)
	{
		epCtl(this->epfd, EPOLL_CTL_DEL, pipeRead, 0);
		close(pipeRead);
		return;
	}

	std::cout << "read from " << pipeRead << std::endl;
	CharVec &httpMessage = client->getReqBuffer();
	char buffer[BUFSIZ];
	ssize_t readBytes;

	readBytes = read(pipeRead, buffer, BUFSIZ);
	if (readBytes > 0)
		httpMessage.insert(httpMessage.end(), buffer, buffer + readBytes);
	else if (readBytes == 0)
		client->setResponse(ResponseGenerator::errorResponse(INTERNAL_SERVER_ERROR, client));

	if (client->getResponse().getHeader().getStatusCode() == HttpStatus::NONE)
	{
		Response response;
		response = Response::ok();
		response.parseHeader(httpMessage);
		extractHeader(httpMessage);

		client->setResponse(response);
	}

	std::string length = client->getResponse().getHeader().getAttributeValue("Content-Length");
	if (length == "")
		client->getResponse().withBody(httpMessage);
	else if (httpMessage.size() == strToSize(length))
		client->getResponse().withBody(httpMessage);
	else
		return;

	if (std::strcmp((const char *)&httpMessage[0], "ERROR") == 0)
	{
		Response response = ResponseGenerator::errorResponse(INTERNAL_SERVER_ERROR, client);
		client->setResponse(response);
	}
	cleanupCgi(client, pipeRead);
}

void Server::removeClient(int clntFd)
{
	garbageCollector.push(clntFd);
}

void Server::cleanupClient(void)
{
	size_t size = this->garbageCollector.size();

	for (size_t i = 0; i < size; ++i)
	{
		int clntFd = garbageCollector.front();
		garbageCollector.pop();

		if (this->clients.count(clntFd) > 0)
		{
			Client *client = this->clients[clntFd];
			if (client->getRefCount() > 0)
			{
				this->garbageCollector.push(clntFd);
			}
			else
			{
				delete (this->clients[clntFd]);
				this->clients.erase(clntFd);
			}
		}
	}
}

void Server::cleanupCgi(Client *client, int pipeRead)
{
	epCtl(this->epfd, EPOLL_CTL_DEL, pipeRead, 0);
	close(pipeRead);
	client->ready();
	client->decreaseRefCount();
	this->cgiOut.erase(pipeRead);

	client->setCgiPid(0);
	client->setReadFd(0);
}

void Server::processSessionAndCookies(Request &request, Response &response)
{
	Cookie &cookie = request.getCookie();
	ResponseGenerator::setResponseCookie(response, cookie);

	std::string sessionId = cookie.getCookieValue(SESSION_KEY);
	std::string visitedTime = cookie.getCookieValue(VISITED_KEY);

	if (!sessionId.empty() && !visitedTime.empty())
		this->session.setConnectionTimes(sessionId, visitedTime);
}

/* public */
Server::Server()
{
	this->epfd = epoll_create(1);
	if (epfd < 0)
		throw std::runtime_error("epoll_error");
}

Server::Server(sa_family_t family, uint32_t inAddr, uint16_t inPort, int type)
{
	this->epfd = epoll_create(1);
	if (epfd < 0)
		throw std::runtime_error("epoll_error");
	appendSocket(family, inAddr, inPort, type);
}

Server::~Server()
{
	if (this->epfd)
		close(this->epfd);
	for (ServerMap::iterator it = this->servers.begin(); it != this->servers.end(); ++it)
		delete (it->second);
	for (ClientMap::iterator it = this->clients.begin(); it != this->clients.end(); ++it)
		delete (it->second);
	servers.clear();
	clients.clear();
	cgiIn.clear();
	cgiOut.clear();
}

void Server::appendSocket(sa_family_t family, uint32_t inAddr, uint16_t inPort, int type)
{
	Socket *socket = new Socket(family, inAddr, inPort, type);
	if (!socket)
		throw std::runtime_error("server: socket create fail");
	this->servers[socket->getFd()] = socket;
	bindSocket(socket);
	if (epCtl(this->epfd, EPOLL_CTL_ADD, socket->getFd(), EPOLLIN | EPOLLOUT) < 0)
		throw std::runtime_error("server: epoll ctl fail");
}

void Server::run()
{
	int en = 0;

	while (en >= 0)
	{
		time_t curTime = getCurrentTimeMillis();
		for (ClientMap::iterator it = this->clients.begin(); it != this->clients.end(); ++it)
		{
			Client *client = it->second;
			if (!client->isReady() && client->isTimeout(curTime))
			{
				if (client->getCgiPid() != 0)
				{
					kill(client->getCgiPid(), SIGINT);
					this->cleanupCgi(client, client->getReadFd());
				}
				client->setResponse(ResponseGenerator::errorResponse(GATEWAY_TIMEOUT, client));
				client->ready();
			}
		}

		en = epoll_wait(this->epfd, this->events, EVENT_MAX, 0);
		for (int i = 0; i < en; ++i)
		{
			int fd = events[i].data.fd;

			if (servers.count(fd) > 0)
			{
				if (events[i].events & EPOLLIN)
					this->acceptClient(fd);
			}
			else if (clients.count(fd) > 0)
			{
				if (events[i].events & EPOLLIN)
					this->requestClient(fd);
				if (events[i].events & EPOLLOUT)
					this->response(fd);
			}
			else
			{
				if (events[i].events & EPOLLIN)
					this->readFromCGI(fd);
				if (events[i].events & EPOLLOUT)
					this->writeToCGI(fd);
			}
		}

		cleanupClient();
	}
}

void Server::stop()
{
	close(this->epfd);
	this->epfd = 0;
}

void Server::openServerPort(void)
{
	std::map<std::string, Config> configMap = this->getMetaConfig().getConfigMap();
	std::map<std::string, Config>::iterator mapIt;
	std::set<uint16_t> inPorts;
	std::set<uint16_t>::iterator setIt;

	if (configMap.empty())
		inPorts.insert(WEBSERV_PORT);

	for (mapIt = configMap.begin(); mapIt != configMap.end(); ++mapIt)
	{
		inPorts.insert(mapIt->second.getData().getInPort());
	}

	for (setIt = inPorts.begin(); setIt != inPorts.end(); ++setIt)
	{
		this->appendSocket(AF_INET, INADDR_ANY, *setIt, SOCK_STREAM);
	}
}

void Server::setMetaConfig(const MetaConfig &config)
{
	this->config = config;
}

MetaConfig &Server::getMetaConfig()
{
	return (this->config);
}
