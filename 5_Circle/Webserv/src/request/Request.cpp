/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:06:10 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/30 20:40:00 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include "client/Client.hpp"
#include "utils/utils.hpp"
#include "response/ResponseGenerator.hpp"

#include "request/Request.hpp"

/* public */
const std::string Request::dynamicExtensions[] = {"php", "py", "cgi", "pl", "rb", "jsp", "bla"};

Request::Request() : cookie(), statCalled(false), statResult(-1) {}

Request::Request(const Request &request) { *this = request; }

bool Request::empty() { return (!this->statCalled); }

const std::string &Request::getMethod() const { return (this->method); }
const std::string &Request::getRequestUri() const { return (this->requestUri); }
const std::string &Request::getHttpVersion() const { return (this->httpVersion); }
const std::string &Request::getHost() const { return (this->header.getAttributeValue("Host")); }
const std::string &Request::getFilePath() const { return (this->filePath); }
const std::string &Request::getContentType() const { return (this->header.getAttributeValue("Content-Type")); }
const std::string &Request::getContentLength() const { return (this->header.getAttributeValue("Content-Length")); }
const Header &Request::getHeader() const { return (this->header); }
const Body &Request::getBody() const { return (this->body); }
Cookie &Request::getCookie() { return (this->cookie); }

void Request::setMethod(const std::string &method) { this->method = method; }
void Request::setRequestUri(const std::string &requestUri) { this->requestUri = requestUri; }
void Request::setHttpVersion(const std::string &httpVersion) { this->httpVersion = httpVersion; }
void Request::setHost(const std::string &host) { this->header.setAttribute("Host", host); }
void Request::setContentType(const std::string &contentType) { this->header.setAttribute("Content-Type", contentType); }
void Request::setContentLength(const std::string &contentLength) { this->header.setAttribute("Content-Length", contentLength); }
void Request::setHeader(const std::string &key, const std::string &value) { this->header.setAttribute(key, value); }
void Request::setHeader(const Header &header) { this->header = header; }
void Request::setBody(const Body &body) { this->body = body; }
void Request::setCookie(const Cookie &cookie) { this->cookie = cookie; }
void Request::setFilePath(const std::string &uri)
{
	std::string cutPath = uri;
	cutPath = removeQueryString(cutPath);
	cutPath = removePathAfterExtension(cutPath);
	this->filePath = cutPath;
}

void Request::parseHeaderField(Client *client, MetaConfig &metaConfig)
{
	std::string reqStr(client->getReqBuffer().begin(), client->getReqBuffer().end());
	std::stringstream stream(reqStr);

	parseRequestLine(stream);
	parseHeader(stream);

	client->setMatchedConfig(this->getCurrentConfig(client, metaConfig));
	this->updateUriAndConfig(client);
}

void Request::parseRequestLine(std::stringstream &stream)
{
	std::string token;
	std::getline(stream, token);
	StringVec split = strSplit(token, ' ');

	if (split.size() == 3)
	{
		this->setMethod(split[0]);
		this->setRequestUri(normalizedPath(split[1]));
		this->setHttpVersion(split[2]);
	}
}

void Request::parseHeader(std::stringstream &stream)
{
	std::string token, key, value;

	while (std::getline(stream, token))
	{
		stripCarriage(token);
		if (token.empty())
			break;
		size_t idx = token.find(": ");
		if (idx != std::string::npos)
		{
			key = token.substr(0, idx);
			value = token.substr(idx + 2);
			if (key == "Content-Type")
			{
				size_t boundaryIdx = value.find("boundary=");
				if (boundaryIdx != std::string::npos)
				{
					std::string contentType = value.substr(0, boundaryIdx - 2);
					std::string boundary = value.substr(boundaryIdx + 9);
					this->setHeader(key, contentType);
					this->setHeader("boundary", boundary);
				}
				else
					this->setHeader(key, value);
			}
			else if (key == "Host")
			{
				size_t idx = value.find(":");
				this->setHost(value.substr(0, idx));
			}
			else if (key == "Cookie")
			{
				this->parseCookie(value);
				this->setHeader(key, value);
			}
			else
				this->setHeader(key, value);
		}
	}
}

void Request::parseCookie(const std::string &cookieLine)
{
	StringVec cookies = strSplit(cookieLine, ';');

	for (size_t i = 0; i < cookies.size(); ++i)
	{
		std::string token, key, value;
		token = cookies[i];

		size_t equal = token.find("=");
		if (equal == std::string::npos)
			continue;
		key = token.substr(0, equal);
		value = token.substr(equal + 1);

		key = trimBlank(key);
		value = trimBlank(value);
		this->cookie.setCookies(key, value);
	}
}

void Request::parseBodyField(Client *client)
{
	Header header = client->getRequest().getHeader();
	long contentLength = strToSize(client->getRequest().getContentLength());

	if (header.getAttributeValue("Transfer-Encoding") == "chunked")
		this->parseChunked(client->getReqBuffer());
	else if (contentLength > 0)
	{
		if (header.getAttributeValue("Content-Type") == "multipart/form-data")
			this->parseMultipart(client->getReqBuffer());
		this->body.setContent(client->getReqBuffer());
	}

	if (!this->body.getContent().empty() && this->body.getFileData().empty())
		this->body.setFileData(sizeToStr(getCurrentTimeMillis()), this->body.getContent());
}

void Request::parseChunked(const CharVec &buffer)
{
	CharVec content;
	size_t pos = 0;

	while (pos < buffer.size())
	{
		std::string lengthLine = getVecLine(buffer, pos);
		size_t length = 0;
		std::stringstream hexStream(lengthLine);
		hexStream >> std::hex >> length;
		if (length == 0)
			break;

		for (size_t i = 0; i < length && pos < buffer.size(); ++i)
		{
			content.push_back(buffer[pos]);
			++pos;
		}

		if (pos + 1 < buffer.size() && buffer[pos] == '\r' && buffer[pos + 1] == '\n')
			pos += 2;
		else
			break;
	}
	this->setBody(Body(content));
}

void Request::parseMultipart(const CharVec &buffer)
{
	std::string boundaryMarker = "--" + this->header.getAttributeValue("boundary");
	std::string boundaryEnd = boundaryMarker + "--";
	size_t pos = 0;

	while (pos < buffer.size())
	{
		std::string line = getVecLine(buffer, pos);
		if (line != boundaryMarker)
			continue;

		std::string contentDisposition, fileName;
		CharVec fileBody;

		line.clear();
		line = getVecLine(buffer, pos);
		contentDisposition = line;

		size_t fileNameIdx = contentDisposition.find("filename=");
		if (fileNameIdx != std::string::npos)
			fileName = stripQuotes(contentDisposition.substr(fileNameIdx + 9));

		line.clear();
		line = getVecLine(buffer, pos);
		if (!line.empty() && line.find("Content-Type:") != std::string::npos)
		{
			line.clear();
			line = getVecLine(buffer, pos);
		}

		while (pos < buffer.size())
		{
			size_t lineStart = pos;
			std::string nextLine;
			nextLine = getVecLine(buffer, pos);

			if (nextLine == boundaryMarker || nextLine == boundaryEnd)
			{
				if (fileBody.size() >= 2 && fileBody[fileBody.size() - 2] == '\r' && fileBody[fileBody.size() - 1] == '\n')
					fileBody.erase(fileBody.end() - 2, fileBody.end());
				this->body.setFileData(fileName, fileBody);
				if (nextLine == boundaryEnd)
					return;
				break;
			}
			else
				fileBody.insert(fileBody.end(), buffer.begin() + lineStart, buffer.begin() + pos);
		}
	}
}

PathType Request::checkPathType(Client *client) const
{
	ConfigData matchedData = client->getMatchedData();
	Request request = client->getRequest();

	if (!isAllowedMethod(client))
		return (METHOD_NOT_ALLOWED);
	if (isOverBodySize(client))
		return (PAYLOAD_TOO_LARGE);
	if (matchedData.getReturnPath().size() > 0)
		return (MOVED_PERMANENTLY);

	std::string currentMethod = request.getMethod();
	if (currentMethod == RequestMethod::POST)
	{
		if (isFile() && isDynamicFile())
			return (DYNAMIC_FILE);
		if (!isCorrectPostRequest(request))
			return (BAD_REQUEST);
		if (!isDirectory() || !isWritable() || !isExecutable())
			return (FORBIDDEN);
		else if (isConflictFileName())
			return (CONFLICT);
		else
			return (CREATED);
	}
	else if (currentMethod == RequestMethod::DELETE)
	{
		if (!isExists())
			return (NOT_FOUND);
		else
		{
			if (isFile())
			{
				if (isWritable())
					return (NO_CONTENT);
			}
			else
				return (FORBIDDEN);
		}
	}
	else if (currentMethod == RequestMethod::GET || currentMethod == RequestMethod::HEAD)
	{
		if (!isExists())
			return (NOT_FOUND);
		if (isFile())
		{
			if (!isReadable())
				return (FORBIDDEN);
			if (isDynamicFile())
				return (DYNAMIC_FILE);
			return (FILE_TYPE);
		}
		else if (isDirectory())
		{
			if (!endsWithSlash())
				return (MOVED_PERMANENTLY);
			if (!isExecutable())
				return (FORBIDDEN);
			if (!isIndexAvailable(matchedData))
			{
				if (matchedData.getTurnOnAutoIndex())
					return (LISTING);
				else
					return (FORBIDDEN);
			}
			return (DIRECTORY);
		}
	}
	return (BAD_REQUEST);
}

bool Request::isAllowedMethod(Client *client) const
{
	std::string method = this->getMethod();
	std::map<std::string, bool> allowMethods = client->getMatchedData().getAllowMethods();

	return (allowMethods[method]);
}

bool Request::isOverBodySize(Client *client) const
{
	return (this->header.hasAttribute("Content-Length") &&
			strToSize(this->header.getAttributeValue("Content-Length")) > client->getMatchedData().getMaxBodySize());
}

bool Request::fetchStat() const
{
	if (!statCalled)
	{
		statResult = stat(filePath.c_str(), &statBuf);
		statCalled = true;
	}
	return (statResult == 0);
}

bool Request::isExists() const
{
	return (fetchStat());
}

bool Request::isExists(const std::string &filePath) const
{
	struct stat stats;
	return (stat(filePath.c_str(), &stats) == 0);
}

bool Request::isFile() const
{
	return (fetchStat() && S_ISREG(statBuf.st_mode));
}

bool Request::isDirectory() const
{
	return (fetchStat() && S_ISDIR(statBuf.st_mode));
}

bool Request::isReadable() const
{
	return (isExists() && access(filePath.c_str(), R_OK) == 0);
}

bool Request::isWritable() const
{
	return (isExists() && access(filePath.c_str(), W_OK) == 0);
}

bool Request::isExecutable() const
{
	return (isExists() && access(filePath.c_str(), X_OK) == 0);
}

bool Request::isCorrectPostRequest(const Request &request) const
{
	std::string contentType = request.getHeader().getAttributeValue("Content-Type");
	std::string boundary = request.getHeader().getAttributeValue("boundary");
	if (request.getBody().getContent().empty())
		return (false);
	if (contentType == "multipart/form-data")
	{
		if (boundary.empty())
			return (false);
	}
	return (true);
}

bool Request::isConflictFileName() const
{
	std::map<std::string, CharVec>::const_iterator it;
	std::map<std::string, CharVec> fileData = body.getFileData();

	for (it = fileData.begin(); it != fileData.end(); ++it)
	{
		if (isExists(filePath + "/" + it->first))
			return (true);
	}
	return (false);
}

bool Request::isDynamicExtension(const std::string &ext) const
{
	static const std::size_t extCount = sizeof(dynamicExtensions) / sizeof(dynamicExtensions[0]);

	for (std::size_t i = 0; i < extCount; i++)
	{
		if (ext == dynamicExtensions[i])
			return (true);
	}
	return (false);
}

bool Request::isDynamicFile() const
{
	std::string ext = ResponseGenerator::getFileExtension(requestUri);
	std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
	return (isDynamicExtension(ext));
}

bool Request::isIndexAvailable(const ConfigData &configData) const
{
	StringSet::const_iterator it;
	for (it = configData.getIndexPages().begin(); it != configData.getIndexPages().end(); ++it)
	{
		std::string indexPath = filePath + *it;
		struct stat indexStat;
		if (stat(indexPath.c_str(), &indexStat) == 0 && S_ISREG(indexStat.st_mode))
			return (true);
	}
	return (false);
}

bool Request::endsWithSlash() const
{
	return (!filePath.empty() && filePath[filePath.length() - 1] == '/');
}

std::string Request::removeQueryString(const std::string &uri) const
{
	std::size_t pos = uri.find('?');
	if (pos != std::string::npos)
		return (uri.substr(0, pos));
	return (uri);
}

std::string Request::removePathAfterExtension(const std::string &uri) const
{
	std::size_t slashBeforeDot = uri.rfind('/');
	std::size_t dotPos = uri.rfind('.');

	if (dotPos == std::string::npos || (slashBeforeDot != std::string::npos && dotPos < slashBeforeDot))
		return (uri);

	std::size_t slashAfterExt = uri.find('/', dotPos);
	if (slashAfterExt != std::string::npos)
		return (uri.substr(0, slashAfterExt));

	return (uri);
}

void Request::updateUriAndConfig(Client *client)
{
	client->setMatchedData(this->getLocationConfig(client->getMatchedConfig()));
	applyParsedConfig(client->getMatchedData());
}

const Config &Request::getCurrentConfig(Client *client, MetaConfig &metaConfig)
{
	uint16_t requestPort = ntohs(client->getServSocket().getAddr().sin_port);

	return (metaConfig.getConfig(this->getHost(), requestPort));
}

const ConfigData &Request::getLocationConfig(Config &currentConfig)
{
	return (currentConfig.getLocationData(requestUri));
}

void Request::applyParsedConfig(const ConfigData &matchedData)
{
	std::string fullPath;

	if (matchedData.getAliasPath().empty())
		fullPath = matchedData.getRootPath() + "/" + this->requestUri;
	else
	{
		std::string strippedUri = stripPrefix(this->requestUri, matchedData.getKeyName());
		fullPath = matchedData.getAliasPath() + "/" + strippedUri;
	}

	if (!this->isDynamicFile() && this->method == "POST")
		fullPath = fullPath + "/" + matchedData.getUploadPath();

	this->setFilePath(normalizedPath(fullPath));
}

Request &Request::operator=(const Request &request)
{
	if (this != &request)
	{
		this->method = request.method;
		this->requestUri = request.requestUri;
		this->httpVersion = request.httpVersion;

		this->filePath = request.filePath;
		this->header = request.header;
		this->body = request.body;

		this->statCalled = request.statCalled;
		this->statBuf = request.statBuf;
		this->statResult = request.statResult;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Request &request)
{
	stream << request.getMethod() << " " << request.getRequestUri() << " " << request.getHttpVersion() << std::endl;

	MultiStringMap header = request.getHeader().getAttribute();
	for (MultiStringMap::const_iterator it = header.begin(); it != header.end(); ++it)
		stream << it->first.c_str() << ": " << it->second.c_str() << "\n";
	return (stream);
}
