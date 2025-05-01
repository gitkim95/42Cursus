/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigData.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:01:05 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/30 21:36:49 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "request/Request.hpp"
#include "server/Server.hpp"
#include "utils/utils.hpp"

#include "config/ConfigData.hpp"

/* public */
ConfigData::ConfigData()
	: inPort(WEBSERV_PORT), isLocationData(false), isIndexPagesParsed(false), isAllowMethodsParsed(false), isDefaultServer(false),
	  turnOnAutoIndex(false), maxBodySize(1 * MB), keyName(DEFAULT_NAME), rootPath(ROOT_PATH), uploadPath(UPLOAD_PATH)
{
	setDefaultErrorPage();
	setDefaultAllowMethods();
	setDefalutIndexPage();
}

void ConfigData::setInPort(const uint16_t &port)
{
	this->inPort = port;
}

void ConfigData::setIsLocationData(const bool &isLocation)
{
	this->isLocationData = isLocation;
}

void ConfigData::setIsIndexPagesParsed(const bool &isParsed)
{
	this->isIndexPagesParsed = isParsed;
}

void ConfigData::setIsAllowMethodsParsed(const bool &isParsed)
{
	this->isAllowMethodsParsed = isParsed;
}

void ConfigData::setIsDefaultServer(const bool &isDefault)
{
	this->isDefaultServer = isDefault;
}

void ConfigData::setTurnOnAutoIndex(const bool &isTurnOn)
{
	this->turnOnAutoIndex = isTurnOn;
}

void ConfigData::setMaxBodySize(const size_t &bodySize)
{
	this->maxBodySize = bodySize;
}

void ConfigData::setKeyName(const std::string &name)
{
	this->keyName = name;
}

void ConfigData::setRootPath(const std::string &path)
{
	this->rootPath = path;
}

void ConfigData::setAliasPath(const std::string &aliasPath)
{
	this->aliasPath = aliasPath;
}

void ConfigData::setUploadPath(const std::string &uploadPath)
{
	this->uploadPath = uploadPath;
}

void ConfigData::setIndexPages(const std::string &indexPage)
{
	this->indexPages.insert(indexPage);
}

void ConfigData::setAllowMethods(const std::string &method, const bool &isEnabled)
{
	this->allowMethods[method] = isEnabled;
}

void ConfigData::setReturnPath(const int &returnCode, const std::string &returnPath)
{
	this->returnPath[returnCode] = returnPath;
}

void ConfigData::setErrorPage(const std::string &errorCode, const std::string &errorPath)
{
	this->errorPage[strToSize(errorCode)] = errorPath;
}

const uint16_t &ConfigData::getInPort() const
{
	return (this->inPort);
}

const bool &ConfigData::getIsLocationData() const
{
	return (this->isLocationData);
}

const bool &ConfigData::getIsIndexPagesParsed() const
{
	return (this->isIndexPagesParsed);
}

const bool &ConfigData::getIsAllowMethodsParsed() const
{
	return (this->isAllowMethodsParsed);
}

const bool &ConfigData::getIsDefaultServer() const
{
	return (this->isDefaultServer);
}

const bool &ConfigData::getTurnOnAutoIndex() const
{
	return (this->turnOnAutoIndex);
}

const size_t &ConfigData::getMaxBodySize() const
{
	return (this->maxBodySize);
}

const std::string &ConfigData::getKeyName() const
{
	return (this->keyName);
}

const std::string &ConfigData::getRootPath() const
{
	return (this->rootPath);
}

const std::string &ConfigData::getAliasPath() const
{
	return (this->aliasPath);
}

const std::string &ConfigData::getUploadPath() const
{
	return (this->uploadPath);
}

const StringSet &ConfigData::getIndexPages() const
{
	return (this->indexPages);
}

const std::map<std::string, bool> &ConfigData::getAllowMethods() const
{
	return (this->allowMethods);
}

const std::map<int, std::string> &ConfigData::getReturnPath() const
{
	return (this->returnPath);
}

const std::map<int, std::string> &ConfigData::getErrorPage() const
{
	return (this->errorPage);
}

void ConfigData::setDefaultErrorPage()
{
	this->errorPage[BAD_REQUEST] = ERROR_PATH + sizeToStr(BAD_REQUEST) + ".html";
	this->errorPage[FORBIDDEN] = ERROR_PATH + sizeToStr(FORBIDDEN) + ".html";
	this->errorPage[NOT_FOUND] = ERROR_PATH + sizeToStr(NOT_FOUND) + ".html";
	this->errorPage[METHOD_NOT_ALLOWED] = ERROR_PATH + sizeToStr(METHOD_NOT_ALLOWED) + ".html";
	this->errorPage[CONFLICT] = ERROR_PATH + sizeToStr(CONFLICT) + ".html";
	this->errorPage[PAYLOAD_TOO_LARGE] = ERROR_PATH + sizeToStr(PAYLOAD_TOO_LARGE) + ".html";
	this->errorPage[UNSUPPORTED_MEDIA_TYPE] = ERROR_PATH + sizeToStr(UNSUPPORTED_MEDIA_TYPE) + ".html";
	this->errorPage[UNPROCESSABLE_ENTITY] = ERROR_PATH + sizeToStr(UNPROCESSABLE_ENTITY) + ".html";
	this->errorPage[INTERNAL_SERVER_ERROR] = ERROR_PATH + sizeToStr(INTERNAL_SERVER_ERROR) + ".html";
	this->errorPage[SERVICE_UNAVAILABLE] = ERROR_PATH + sizeToStr(SERVICE_UNAVAILABLE) + ".html";
	this->errorPage[GATEWAY_TIMEOUT] = ERROR_PATH + sizeToStr(GATEWAY_TIMEOUT) + ".html";
}

void ConfigData::setDefaultAllowMethods()
{
	setAllowMethods(RequestMethod::GET, true);
	setAllowMethods(RequestMethod::POST, true);
	setAllowMethods(RequestMethod::DELETE, true);
	setAllowMethods(RequestMethod::PUT, true);
}

void ConfigData::setDefalutIndexPage()
{
	this->indexPages.clear();
	setIndexPages("index.html");
}

const std::string ConfigData::getAllowedMethods() const
{
	std::stringstream ss;
	std::map<std::string, bool>::const_iterator it;
	bool isFirst = true;

	for (it = allowMethods.begin(); it != allowMethods.end(); ++it)
	{
		if (it->second)
		{
			if (!isFirst)
				ss << ", ";
			ss << it->first;
			isFirst = false;
		}
	}
	return (ss.str());
}

ConfigData &ConfigData::operator=(const ConfigData &other)
{
	if (this != &other)
	{
		this->inPort = other.inPort;
		this->isLocationData = other.isLocationData;
		this->isIndexPagesParsed = other.isIndexPagesParsed;
		this->isAllowMethodsParsed = other.isAllowMethodsParsed;
		this->isDefaultServer = other.isDefaultServer;
		this->turnOnAutoIndex = other.turnOnAutoIndex;
		this->maxBodySize = other.maxBodySize;
		this->keyName = other.keyName;
		this->rootPath = other.rootPath;
		this->aliasPath = other.aliasPath;
		this->uploadPath = other.uploadPath;
		this->indexPages = other.indexPages;
		this->allowMethods = other.allowMethods;
		this->returnPath = other.returnPath;
		this->errorPage = other.errorPage;
	}
	return (*this);
}