/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:26:42 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/27 09:03:26 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "utils/utils.hpp"

#include "client/Client.hpp"

/* private */

/* public */
Client::Client()
{
	this->serv = NULL;
	this->refCount = 0;
	this->state = REQUEST;
	this->isReqParsed = false;
}

Client::Client(Socket *serv, int clntSock, sockaddr_in addr) : clnt(clntSock, addr)
{
	this->serv = serv;
	this->refCount = 0;
	this->state = REQUEST;
	this->isReqParsed = false;

	try
	{
		setFdNonBlock(this->clnt.getFd());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		this->setResponse(Response::internalServerError());
		this->state = ERROR;
	}
}

Client::Client(const Client &client) : serv(client.serv), clnt(client.clnt) { *this = client; }

bool Client::isTimeout(const time_t &curTime) const { return (curTime > this->clnt.getTimeout()); }
bool Client::isTimeout(void) const { return (getCurrentTimeMillis() > this->clnt.getTimeout()); }
bool Client::error(void) const { return (this->state == ERROR); }
bool Client::isReady(void) const { return (this->state > REQUEST); }
void Client::ready() { this->state = RESPONSE; }

void Client::increaseRefCount(void) { ++this->refCount; }
void Client::decreaseRefCount(void) { --this->refCount; }

bool Client::isRequestValid() const
{
	bool hasLength = true;
	Header header = this->request.getHeader();
	std::string contentLengthStr = header.getAttributeValue("Content-Length");
	size_t contentLength = strToSize(contentLengthStr);

	if (contentLengthStr.empty())
		hasLength = false;
	if (this->request.getMethod() != "POST")
		return (false);

	if (header.getAttributeValue("Transfer-Encoding") == "chunked")
	{
		const std::string expectedEnds = "0\r\n\r\n";
		if (reqBuffer.size() >= expectedEnds.size())
		{
			std::string bufferEnds(reqBuffer.end() - expectedEnds.size(), reqBuffer.end());
			if (bufferEnds == expectedEnds)
				return (true);
		}
	}
	else if (hasLength && contentLength == this->reqBuffer.size())
	{
		return (true);
	}
	return (false);
}

const Socket &Client::getServSocket(void) const { return (*this->serv); }
const Socket &Client::getClntSocket(void) const { return (this->clnt); }
Request &Client::getRequest(void) { return (this->request); }
Response &Client::getResponse(void) { return (this->response); }
Config &Client::getMatchedConfig() { return (this->matchedConfig); }
ConfigData &Client::getMatchedData() { return (this->matchedData); }
const PathType &Client::getPathType() const { return (this->pathType); }
const int &Client::getRefCount(void) const { return (this->refCount); }
CharVec &Client::getReqBuffer() { return (this->reqBuffer); }
const bool &Client::getIsReqParsed() const { return (this->isReqParsed); }

void Client::setRequest(const Request &request)
{
	this->request = request;
}

void Client::setResponse(const Response &response)
{
	this->response = response;
}

void Client::setMatchedConfig(const Config &config)
{
	this->matchedConfig = config;
}

void Client::setMatchedData(const ConfigData &data)
{
	this->matchedData = data;
}

void Client::setPathType(const PathType &type)
{
	this->pathType = type;
}

void Client::setReqBuffer(const CharVec &str)
{
	this->reqBuffer = str;
}

void Client::setIsReqParsed(const bool &isParsed)
{
	this->isReqParsed = isParsed;
}

Client &Client::operator=(const Client &client)
{
	if (this != &client)
	{
		this->serv = client.serv;
		this->clnt = client.clnt;
		this->request = client.request;
		this->response = client.response;

		this->matchedConfig = client.matchedConfig;
		this->matchedData = client.matchedData;
		this->pathType = client.pathType;

		this->refCount = client.refCount;
		this->state = client.state;
		this->reqBuffer = client.reqBuffer;
	}
	return (*this);
}
