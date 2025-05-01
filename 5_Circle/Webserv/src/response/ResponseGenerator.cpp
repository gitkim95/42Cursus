/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseGenerator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:50:28 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/30 21:39:02 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "utils/utils.hpp"
#include "server/Server.hpp"

#include "response/ResponseGenerator.hpp"

ResponseGenerator::ResponseGenerator() {}

const Response ResponseGenerator::getResponseData(Client *client, const CharVec &fileData)
{
	Request &request = client->getRequest();
	ConfigData currentData = client->getMatchedData();
	std::string filePath = request.getFilePath();
	std::string contentType;

	switch (client->getPathType())
	{
	case FILE_TYPE:
	{
		Response response = Response::ok();
		if (request.getMethod() == "GET")
			response.withBody(fileData);
		contentType = getMimeType(filePath);
		response.setHeader("Content-Type", contentType);
		response.setHeader("Connection", "keep-alive");
		return (response);
	}
	case DIRECTORY:
	{
		Response response = Response::ok();
		if (request.getMethod() == "GET")
			response.withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Connection", "keep-alive");
		return (response);
	}
	case LISTING:
	{
		Response response = Response::ok();
		if (request.getMethod() == "GET")
			response.withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Connection", "keep-alive");
		return (response);
	}
	case CREATED:
	{
		Response response = Response::makeResponse(HttpStatus::CREATED).withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Connection", "keep-alive");
		return (response);
	}
	case NO_CONTENT:
	{
		Response response = Response::makeResponse(HttpStatus::NO_CONTENT);
		response.setHeader("Connection", "keep-alive");
		return (response);
	}
	case MOVED_PERMANENTLY:
	{
		std::string redirectionURL = getRedirectionURL(currentData, request.getRequestUri());
		Response response = Response::makeResponse(HttpStatus::MOVED_PERMANENTLY);
		response.setHeader("Location", redirectionURL);
		response.setHeader("Connection", "keep-alive");
		return (response);
	}
	case BAD_REQUEST:
	{
		Response response = Response::makeResponse(HttpStatus::BAD_REQUEST).withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Connection", "close");
		return (response);
	}
	case FORBIDDEN:
	{
		Response response = Response::makeResponse(HttpStatus::FORBIDDEN).withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Connection", "close");
		return (response);
	}
	case METHOD_NOT_ALLOWED:
	{
		Response response = Response::makeResponse(HttpStatus::METHOD_NOT_ALLOWED).withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Allow", currentData.getAllowedMethods());
		response.setHeader("Connection", "keep-alive");
		return (response);
	}
	case CONFLICT:
	{
		Response response = Response::makeResponse(HttpStatus::CONFLICT).withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Connection", "close");
		return (response);
	}
	case PAYLOAD_TOO_LARGE:
	{
		Response response = Response::makeResponse(HttpStatus::PAYLOAD_TOO_LARGE).withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Connection", "close");
		return (response);
	}
	case UNSUPPORTED_MEDIA_TYPE:
	{
		Response response = Response::makeResponse(HttpStatus::UNSUPPORTED_MEDIA_TYPE).withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Connection", "keep-alive");
		return (response);
	}
	case INTERNAL_SERVER_ERROR:
	{
		Response response = Response::makeResponse(HttpStatus::INTERNAL_SERVER_ERROR).withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Connection", "close");
		return (response);
	}
	case SERVICE_UNAVAILABLE:
	{
		Response response = Response::makeResponse(HttpStatus::SERVICE_UNAVAILABLE).withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Connection", "close");
		return (response);
	}
	case GATEWAY_TIMEOUT:
	{
		Response response = Response::makeResponse(HttpStatus::GATEWAY_TIMEOUT).withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Connection", "close");
		return (response);
	}
	default:
	{
		Response response = Response::notFound().withBody(fileData);
		response.setDefaultContentType();
		response.setHeader("Connection", "keep-alive");
		return (response);
	}
	}
}

void ResponseGenerator::setResponseCookie(Response &response, Cookie &cookie)
{
	if (!cookie.hasCookie(SESSION_KEY))
	{
		std::string uuid = cookie.generateUUID();
		cookie.setCookies(SESSION_KEY, uuid);
	}
	cookie.setCookies(VISITED_KEY, sizeToStr(getCurrentTimeMillis()));

	StringSet cookieSet = cookie.toSetCookieHeader();
	StringSet::const_iterator it;
	for (it = cookieSet.begin(); it != cookieSet.end(); ++it)
		response.setHeader("Set-Cookie", *it);
}

const std::string ResponseGenerator::getRedirectionURL(const ConfigData &data, const std::string &uri)
{
	std::map<int, std::string>::const_iterator it = data.getReturnPath().find(301);
	if (it != data.getReturnPath().end())
	{
		return (it->second);
	}
	else
	{
		return (uri + "/");
	}
}

StringVec ResponseGenerator::listDirectory(const std::string &path)
{
	StringVec list;
	DIR *dir = opendir(path.c_str());
	if (!dir)
		return (list);
	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL)
	{
		std::string name = entry->d_name;
		if (name != "." && name != "..")
			list.push_back(name);
	}
	closedir(dir);
	return (list);
}

CharVec ResponseGenerator::generateHtmlList(const std::string &path, const StringVec &list)
{
	CharVec vecHtml;

	std::string html =
		"<!DOCTYPE html>\n"
		"<html lang=\"ko\">\n"
		"<head>\n"
		"    <meta charset=\"UTF-8\">\n"
		"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
		"    <title>Index of " +
		path + "</title>\n"
			   "    <style>\n"
			   "        body {\n"
			   "            font-family: Arial, sans-serif;\n"
			   "            text-align: center;\n"
			   "            padding: 50px;\n"
			   "            background-color: #f9f9f9;\n"
			   "        }\n"
			   "        h1 {\n"
			   "            font-size: 40px;\n"
			   "            color: #333;\n"
			   "        }\n"
			   "        ul {\n"
			   "            list-style-type: none;\n"
			   "            padding: 0;\n"
			   "        }\n"
			   "        li {\n"
			   "            margin: 10px 0;\n"
			   "        }\n"
			   "        a {\n"
			   "            text-decoration: none;\n"
			   "            color: #007BFF;\n"
			   "            font-size: 18px;\n"
			   "        }\n"
			   "        a:hover {\n"
			   "            text-decoration: underline;\n"
			   "        }\n"
			   "    </style>\n"
			   "</head>\n"
			   "<body>\n"
			   "    <h1>Index of " +
		path + "</h1>\n"
			   "    <ul>\n";

	for (size_t i = 0; i < list.size(); ++i)
		html += "        <li><a href=\"" + list[i] + "\">" + list[i] + "</a></li>\n";

	html +=
		"    </ul>\n"
		"</body>\n"
		"</html>\n";

	vecHtml.insert(vecHtml.end(), html.begin(), html.end());

	return (vecHtml);
}

CharVec ResponseGenerator::generateHtmlPost(const std::string &fileUri)
{
	CharVec vecHtml;

	std::string html =
		"<!DOCTYPE html>\n"
		"<html lang=\"ko\">\n"
		"<head>\n"
		"    <meta charset=\"UTF-8\">\n"
		"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
		"    <title>201 - 파일 업로드 성공</title>\n"
		"    <style>\n"
		"        body {\n"
		"            font-family: Arial, sans-serif;\n"
		"            text-align: center;\n"
		"            padding: 50px;\n"
		"        }\n"
		"        h1 {\n"
		"            font-size: 50px;\n"
		"            color: #28a745;\n"
		"        }\n"
		"        p {\n"
		"            font-size: 20px;\n"
		"        }\n"
		"        a {\n"
		"            text-decoration: none;\n"
		"            color: #007BFF;\n"
		"        }\n"
		"    </style>\n"
		"</head>\n"
		"<body>\n"
		"    <h1>201</h1>\n"
		"    <p>파일이 성공적으로 업로드되었습니다.</p>\n"
		"    <p><a href=\"" +
		fileUri + "\">업로드한 파일 보기</a></p>\n"
				  "</body>\n"
				  "</html>\n";

	vecHtml.insert(vecHtml.end(), html.begin(), html.end());

	return (vecHtml);
}

std::string ResponseGenerator::getFileExtension(const std::string &path)
{
	std::string tempPath = path;

	std::size_t queryIdx = path.find('?');
	if (queryIdx != std::string::npos)
		tempPath = tempPath.substr(0, queryIdx);

	while (!tempPath.empty())
	{
		std::size_t dotIdx = tempPath.find_last_of('.');
		if (dotIdx == std::string::npos)
			break;

		std::size_t slashAfterDot = tempPath.find('/', dotIdx);
		if (slashAfterDot == std::string::npos)
		{
			std::string ext = tempPath.substr(dotIdx + 1);
			if (!ext.empty())
				return (ext);
			break;
		}

		std::size_t lastSlashIdx = tempPath.find_last_of('/');
		if (lastSlashIdx == std::string::npos)
			break;

		tempPath = tempPath.substr(0, lastSlashIdx);
	}
	return ("");
}

StringMap ResponseGenerator::loadMimeTypes()
{
	StringMap mimeTypes;

	std::ifstream file("mime.types");
	if (!file.is_open())
		return (getDefaultMimeTypes());

	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty() || line[0] == '#')
			continue;
		std::istringstream iss(line);
		std::string mime, ext;
		iss >> mime;
		while (iss >> ext)
			mimeTypes[ext] = mime;
	}
	return (mimeTypes);
}

std::string ResponseGenerator::getMimeType(const std::string &path)
{
	static StringMap mimeTypes = loadMimeTypes();
	std::string extension = getFileExtension(path);

	StringMap::iterator it = mimeTypes.find(extension);
	if (it != mimeTypes.end())
		return (it->second);
	return ("application/octet-stream");
}

StringMap ResponseGenerator::getDefaultMimeTypes()
{
	StringMap mimeTypes;

	mimeTypes["html"] = "text/html";
	mimeTypes["htm"] = "text/html";
	mimeTypes["css"] = "text/css";
	mimeTypes["js"] = "application/javascript";
	mimeTypes["json"] = "application/json";
	mimeTypes["png"] = "image/png";
	mimeTypes["jpg"] = "image/jpeg";
	mimeTypes["jpeg"] = "image/jpeg";
	mimeTypes["gif"] = "image/gif";
	mimeTypes["txt"] = "text/plain";

	mimeTypes["php"] = "application/x-httpd-php";
	mimeTypes["py"] = "application/x-python";
	mimeTypes["cgi"] = "application/x-cgi";
	mimeTypes["pl"] = "application/x-perl";
	mimeTypes["rb"] = "application/x-ruby";
	mimeTypes["jsp"] = "application/x-java-jsp";
	mimeTypes["asp"] = "application/x-aspx";

	return (mimeTypes);
}

const CharVec ResponseGenerator::getFileData(Client *client)
{
	PathType pathType = client->getPathType();
	std::string path = client->getRequest().getFilePath();

	switch (pathType)
	{
	case FILE_TYPE:
	{
		return (readFileData(path));
	}
	case DIRECTORY:
	{
		return (readFileData(getIndexPath(client, path)));
	}
	case LISTING:
	{
		StringVec list = listDirectory(path);
		return (generateHtmlList(path, list));
	}
	case CREATED:
	{
		return (generateHtmlPost(path));
	}
	case BAD_REQUEST:
	{
		return (readFileData(getErrorPath(client, BAD_REQUEST)));
	}
	case FORBIDDEN:
	{
		return (readFileData(getErrorPath(client, FORBIDDEN)));
	}
	case NOT_FOUND:
	{
		return (readFileData(getErrorPath(client, NOT_FOUND)));
	}
	case METHOD_NOT_ALLOWED:
	{
		return (readFileData(getErrorPath(client, METHOD_NOT_ALLOWED)));
	}
	case CONFLICT:
	{
		return (readFileData(getErrorPath(client, CONFLICT)));
	}
	case PAYLOAD_TOO_LARGE:
	{
		return (readFileData(getErrorPath(client, PAYLOAD_TOO_LARGE)));
	}
	case UNSUPPORTED_MEDIA_TYPE:
	{
		return (readFileData(getErrorPath(client, UNSUPPORTED_MEDIA_TYPE)));
	}
	case INTERNAL_SERVER_ERROR:
	{
		return (readFileData(getErrorPath(client, INTERNAL_SERVER_ERROR)));
	}
	case SERVICE_UNAVAILABLE:
	{
		return (readFileData(getErrorPath(client, SERVICE_UNAVAILABLE)));
	}
	case GATEWAY_TIMEOUT:
	{
		return (readFileData(getErrorPath(client, GATEWAY_TIMEOUT)));
	}
	default:
	{
		return (CharVec());
	}
	}
}

const std::string ResponseGenerator::getErrorPath(Client *client, const PathType &status)
{
	std::map<int, std::string> errorPages = client->getMatchedData().getErrorPage();
	client->getRequest().setRequestUri(errorPages[status]);
	client->getRequest().updateUriAndConfig(client);
	return (client->getRequest().getFilePath());
}

const std::string ResponseGenerator::getIndexPath(Client *client, const std::string &path)
{
	StringSet::const_iterator it;
	StringSet indexPages = client->getMatchedData().getIndexPages();

	for (it = indexPages.begin(); it != indexPages.end(); ++it)
	{
		std::string indexPath = path + *it;
		struct stat indexStat;
		if (stat(indexPath.c_str(), &indexStat) == 0 && S_ISREG(indexStat.st_mode))
			return (indexPath);
	}
	return ("");
}

Response ResponseGenerator::errorResponse(PathType pathType, Client *client)
{
	client->setPathType(pathType);
	CharVec fileData = ResponseGenerator::getFileData(client);
	return (ResponseGenerator::getResponseData(client, fileData));
}
