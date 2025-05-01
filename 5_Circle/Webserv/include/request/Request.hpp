/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:05:37 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/30 21:36:34 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <ostream>
#include <sstream>
#include <sys/stat.h>
#include "config/MetaConfig.hpp"
#include "httpMessage/Body.hpp"
#include "httpMessage/Cookie.hpp"
#include "response/Response.hpp"

enum PathType
{
	FILE_TYPE = 200,
	DIRECTORY = 2,
	LISTING = 3,
	DYNAMIC_FILE = 4,
	CREATED = 201,
	NO_CONTENT = 204,
	MOVED_PERMANENTLY = 301,
	BAD_REQUEST = 400,
	FORBIDDEN = 403,
	NOT_FOUND = 404,
	METHOD_NOT_ALLOWED = 405,
	CONFLICT = 409,
	PAYLOAD_TOO_LARGE = 413,
	UNSUPPORTED_MEDIA_TYPE = 415,
	UNPROCESSABLE_ENTITY = 422,
	INTERNAL_SERVER_ERROR = 500,
	SERVICE_UNAVAILABLE = 503,
	GATEWAY_TIMEOUT = 504,
};

class Client;

class Request
{
private:
	std::string method;
	std::string requestUri;
	std::string httpVersion;

	std::string filePath;
	Header header;
	Body body;
	Cookie cookie;

	mutable bool statCalled;
	mutable struct stat statBuf;
	mutable int statResult;

	static const std::string dynamicExtensions[];

	bool isAllowedMethod(Client *client) const;
	bool isOverBodySize(Client *client) const;
	bool fetchStat() const;
	bool isFile() const;
	bool isDirectory() const;
	bool isExists() const;
	bool isExists(const std::string &filePath) const;
	bool isReadable() const;
	bool isWritable() const;
	bool isExecutable() const;
	bool isCorrectPostRequest(const Request &request) const;
	bool isConflictFileName() const;
	bool isDynamicExtension(const std::string &ext) const;
	bool isDynamicFile() const;
	bool isIndexAvailable(const ConfigData &configData) const;
	bool endsWithSlash() const;
	std::string removeQueryString(const std::string &uri) const;
	std::string removePathAfterExtension(const std::string &uri) const;

	void parseRequestLine(std::stringstream &stream);
	void parseHeader(std::stringstream &stream);
	void parseCookie(const std::string &cookieLine);
	void parseChunked(const CharVec &buffer);
	void parseMultipart(const CharVec &buffer);

	const Config &getCurrentConfig(Client *client, MetaConfig &metaConfig);
	const ConfigData &getLocationConfig(Config &currentConfig);
	void applyParsedConfig(const ConfigData &matchedData);

public:
	Request();
	Request(const Request &request);

	bool empty();

	const std::string &getMethod() const;
	const std::string &getRequestUri() const;
	const std::string &getHttpVersion() const;
	const std::string &getHost() const;
	const std::string &getFilePath() const;
	const std::string &getContentType() const;
	const std::string &getContentLength() const;
	const Header &getHeader() const;
	const Body &getBody() const;
	Cookie &getCookie();

	void setMethod(const std::string &method);
	void setRequestUri(const std::string &requestUri);
	void setHttpVersion(const std::string &httpVersion);
	void setHost(const std::string &host);
	void setFilePath(const std::string &uri);
	void setContentType(const std::string &contentType);
	void setContentLength(const std::string &contentLength);
	void setHeader(const std::string &key, const std::string &value);
	void setHeader(const Header &header);
	void setBody(const Body &body);
	void setCookie(const Cookie &cookie);

	void parseHeaderField(Client *client, MetaConfig &metaConfig);
	void parseBodyField(Client *client);
	void updateUriAndConfig(Client *client);
	PathType checkPathType(Client *client) const;

	Request &operator=(const Request &request);
};

std::ostream &operator<<(std::ostream &stream, const Request &request);

namespace RequestMethod
{
	const std::string GET = "GET";
	const std::string HEAD = "HEAD";
	const std::string POST = "POST";
	const std::string PUT = "PUT";
	const std::string DELETE = "DELETE";
};

#endif