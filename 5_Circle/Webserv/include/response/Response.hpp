/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:47:12 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/29 17:07:58 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>
#include <sys/types.h>
#include "httpMessage/Body.hpp"
#include "httpMessage/Header.hpp"
#include "server/Session.hpp"

class Request;

class Response
{
private:
	Header header;
	Body body;
	ssize_t sendIdx;

public:
	Response();
	Response(Header header, Body body);
	Response(const Response &response);

	static Response ok();
	static Response badRequest();
	static Response notFound();
	static Response internalServerError();
	static Response serverUnavailable();
	static Response gatewayTimeout();
	static Response makeResponse(const StatusCode &statusCode);
	Response &withHeader(const std::string &headerName, const std::string &value);
	Response &withBody(const CharVec &content);

	bool empty();

	void increaseSendIdx(const ssize_t &sendBytes);

	ssize_t getSendIdx(void) const;
	Header &getHeader(void);
	Body &getBody(void);

	void setHeader(const std::string &headerName, const std::string &value);
	void setSendIdx(const ssize_t &sendIdx);
	void setSessionBody(Session &session, Request &request);
	void setDefaultContentType();
	void parseHeader(const CharVec &httpMessage);

	bool isOK() const;
	CharVec toBinary(void) const;
	Response &operator=(const Response &response);
};

#endif