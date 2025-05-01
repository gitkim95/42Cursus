/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:44:20 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/30 20:39:43 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <map>
#include <queue>
#include <sys/epoll.h>
#include "config/MetaConfig.hpp"
#include "client/Client.hpp"
#include "Session.hpp"
#include "Socket.hpp"
#include "sys/types.hpp"

#define EVENT_MAX 1024
#define CLIENT_MAX 1024
#define WEBSERV_PORT 33775

class Server
{
private:
	int epfd;
	struct epoll_event events[EVENT_MAX];
	MetaConfig config;
	ServerMap servers;
	ClientMap clients;
	CGIInMap cgiIn;
	ClientMap cgiOut;
	Session session;
	std::queue<int> garbageCollector;

	void bindSocket(Socket *socket);
	void acceptClient(int servFd);

	void requestClient(int clntFd);
	void postFile(const Request &request);
	void deleteFile(const std::string &filePath);
	void runCGI(Client *client);
	void response(int clntFd);
	void writeToCGI(int pipeWrite);
	void readFromCGI(int pipeRead);

	void removeClient(int clntFd);
	void cleanupClient(void);

	void cleanupCgi(Client *client, int pipeRead);

	void processSessionAndCookies(Request &request, Response &response);

public:
	Server(void);
	Server(sa_family_t family, uint32_t inAddr, uint16_t inPort, int type);
	~Server(void);

	void appendSocket(sa_family_t family, uint32_t inAddr, uint16_t inPort, int type);
	void run(void);
	void stop(void);

	void openServerPort(void);

	void setMetaConfig(const MetaConfig &config);
	MetaConfig &getMetaConfig();
};

#endif