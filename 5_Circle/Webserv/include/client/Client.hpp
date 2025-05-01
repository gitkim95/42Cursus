/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:22:17 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/30 20:39:38 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "server/Socket.hpp"
#include "request/Request.hpp"
#include "response/Response.hpp"

enum ClientState
{
	REQUEST = 0,
	RESPONSE = 1,
	ERROR = 2,
};

class Client
{
private:
	Socket *serv;
	Socket clnt;
	Request request;
	Response response;
	Config matchedConfig;
	ConfigData matchedData;
	pid_t cgiPid;
	int readFd;

	PathType pathType;
	int refCount;
	ClientState state;
	CharVec reqBuffer;
	bool isReqParsed;

public:
	Client();
	Client(Socket *serv, int clntSock, sockaddr_in addr);
	Client(const Client &client);

	bool isTimeout(const time_t &curTime) const;
	bool isTimeout(void) const;

	bool isReady(void) const;
	bool error(void) const;
	void ready();

	void increaseRefCount(void);
	void decreaseRefCount(void);

	bool isRequestValid() const;

	const Socket &getServSocket(void) const;
	const Socket &getClntSocket(void) const;
	Request &getRequest(void);
	Response &getResponse(void);
	Config &getMatchedConfig();
	ConfigData &getMatchedData();
	const PathType &getPathType() const;
	const int &getRefCount(void) const;
	CharVec &getReqBuffer();
	const bool &getIsReqParsed() const;
	const pid_t &getCgiPid() const;
	const int &getReadFd() const;

	void setRequest(const Request &request);
	void setResponse(const Response &response);
	void setMatchedConfig(const Config &config);
	void setMatchedData(const ConfigData &data);
	void setPathType(const PathType &type);
	void setReqBuffer(const CharVec &str);
	void setIsReqParsed(const bool &isParsed);
	void setCgiPid(const pid_t &pid);
	void setReadFd(const int &fd);

	Client &operator=(const Client &client);
};

#endif