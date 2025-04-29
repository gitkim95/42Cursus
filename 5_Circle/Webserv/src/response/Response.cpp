/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:52:43 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/29 17:08:05 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <sstream>
#include "request/Request.hpp"
#include "statuscode/StatusCode.hpp"
#include "utils/utils.hpp"

#include "response/Response.hpp"

/* private */

/* public */
Response::Response() : header(Header(HttpStatus::NONE)) { this->sendIdx = 0; }

Response::Response(Header header, Body body) : header(header), body(body) { this->sendIdx = 0; }

Response::Response(const Response &response) { *this = response; }

Response Response::ok()
{
	return Response(Header(HttpStatus::OK), Body());
}

Response Response::badRequest()
{
	return (Response(Header(HttpStatus::BAD_REQUEST), Body()));
}

Response Response::notFound()
{
	Response response(Header(HttpStatus::NOT_FOUND), (Body()));
	response.setDefaultContentType();
	return (response);
}

Response Response::internalServerError()
{
	return Response(Header(HttpStatus::INTERNAL_SERVER_ERROR), Body());
}

Response Response::serverUnavailable()
{
	return Response(Header(HttpStatus::SERVICE_UNAVAILABLE), Body());
}

Response Response::gatewayTimeout()
{
	Body body = Body();
	const char *html =
		"<!DOCTYPE html>\r\n"
		"<html>\r\n"
		"<head>\r\n"
		"<title>504 Gateway Timeout</title>\r\n"
		"</head>\r\n"
		"<body>\r\n"
		"<h1>504 Gateway Timeout</h1>\r\n"
		"<p>The server, while acting as a gateway or proxy, did not receive a timely response from the upstream server.</p>\r\n"
		"</body>\r\n"
		"</html>";
	body.setContent(CharVec(html, html + std::strlen(html)));

	Header header = Header(HttpStatus::GATEWAY_TIMEOUT);
	header.setAttribute("Content-Type", "text/html");
	header.setAttribute("Content-Length", sizeToStr(body.getContent().size()));
	header.setAttribute("Connection", "close");

	return Response(header, body);
}

Response Response::makeResponse(const StatusCode &statusCode)
{
	return Response(Header(statusCode), Body());
}

Response &Response::withHeader(const std::string &headerName, const std::string &value)
{
	this->header.setAttribute(headerName, value);
	return (*this);
}

Response &Response::withBody(const CharVec &content)
{
	this->body.setContent(content);
	this->setHeader("Content-Length", sizeToStr(content.size()));
	return (*this);
}

bool Response::empty()
{
	return (this->header.getStatusCode() == HttpStatus::NONE);
}

void Response::increaseSendIdx(const ssize_t &sendBytes) { this->sendIdx += sendBytes; }

ssize_t Response::getSendIdx(void) const { return (this->sendIdx); }
Header &Response::getHeader(void) { return (this->header); }
Body &Response::getBody(void) { return (this->body); }

void Response::setHeader(const std::string &headerName, const std::string &value)
{
	this->header.setAttribute(headerName, value);
}

void Response::setSendIdx(const ssize_t &sendIdx) { this->sendIdx = sendIdx; }

void Response::setSessionBody(Session &session, Request &request)
{
	std::string sessionId = request.getCookie().getCookieValue(SESSION_KEY);
	std::string filePath = request.getFilePath();
	CharVec sessionPage = session.getSessionPage(sessionId, filePath);

	this->header.changeAttributeValue("Content-Length", sizeToStr(sessionPage.size()));
	this->body.setContent(sessionPage);
}

void Response::setDefaultContentType()
{
	this->header.setAttribute("Content-Type", "text/html");
}

void Response::parseHeader(const CharVec &httpMessage)
{
	std::string repStr(httpMessage.begin(), httpMessage.end()), token;
	std::stringstream stream(repStr);
	std::getline(stream, token);

	while (std::getline(stream, token))
	{
		stripCarriage(token);
		if (token.empty())
			break;
		size_t idx = token.find(": ");
		if (idx != std::string::npos)
			this->setHeader(token.substr(0, idx), token.substr(idx + 2));
	}
}

bool Response::isOK() const
{
	return (this->header.getStatusCode().getCode() == 200);
}

CharVec Response::toBinary(void) const
{
	CharVec binaryData;

	std::string statusLine = "HTTP/1.1 " + sizeToStr(this->header.getStatusCode().getCode()) + " " + this->header.getStatusCode().getMessage() + "\r\n";
	binaryData.insert(binaryData.end(), statusLine.begin(), statusLine.end());

	const MultiStringMap &attributes = this->header.getAttribute();
	for (MultiStringMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it)
	{
		std::string attributeLine = it->first + ": " + it->second + "\r\n";
		binaryData.insert(binaryData.end(), attributeLine.begin(), attributeLine.end());
	}

	std::string headerEnd = "\r\n";
	binaryData.insert(binaryData.end(), headerEnd.begin(), headerEnd.end());

	const CharVec &content = this->body.getContent();
	binaryData.insert(binaryData.end(), content.begin(), content.end());

	return (binaryData);
}

Response &Response::operator=(const Response &response)
{
	if (this != &response)
	{
		this->header = response.header;
		this->body = response.body;
		this->sendIdx = 0;
	}
	return (*this);
}
