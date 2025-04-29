/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:07:11 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/26 18:35:52 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include <vector>
#include "server/Server.hpp"
#include "utils/utils.hpp"

#include "config/Config.hpp"

Config::Config() {}

ConfigData &Config::getData()
{
	return (this->data);
}

ConfigData &Config::getLocationData(const std::string &key)
{
	for (size_t i = 0; i < locationData.size(); ++i)
	{
		if (key.find(locationData[i].getKeyName()) == 0)
			return (locationData[i]);
	}
	return (this->data);
}

void Config::setLocationData(const ConfigData &value)
{
	this->locationData.push_back(value);
}

void Config::setIsLocation(const bool &isLocation)
{
	this->data.setIsLocationData(isLocation);
}

void Config::resetAllowMethodConfig()
{
	this->data.setIsAllowMethodsParsed(false);
}

void Config::resetIndexPagesConfig()
{
	this->data.setIsIndexPagesParsed(false);
}

void Config::parseListen(const std::string &value, ConfigData &data)
{
	std::string port = value;
	if (port.find("default_server") != std::string::npos)
	{
		data.setIsDefaultServer(true);
		port.erase(port.find("default_server"), std::string("default_server").length());
	}
	data.setInPort(strToSize(port));
}

void Config::parseAutoIndex(const std::string &value, ConfigData &data)
{
	if (value.find("on") != std::string::npos)
		data.setTurnOnAutoIndex(true);
	else if (value.find("off") != std::string::npos)
		data.setTurnOnAutoIndex(false);
}

void Config::parseMaxBodySize(const std::string &value, ConfigData &data)
{
	std::string maxSize;
	size_t index;

	if ((index = value.find("M")) != std::string::npos && index == value.size() - 1)
	{
		maxSize = value.substr(0, index);
		if (isAllDigits(maxSize))
			data.setMaxBodySize(strToSize(maxSize) * MB);
	}
	else if ((index = value.find("K")) != std::string::npos && index == value.size() - 1)
	{
		maxSize = value.substr(0, index);
		if (isAllDigits(maxSize))
			data.setMaxBodySize(strToSize(maxSize) * KB);
	}
	else if (isAllDigits(value))
	{
		maxSize = value;
		data.setMaxBodySize(strToSize(maxSize));
	}
	else
		return;
}

void Config::parseServerName(const std::string &value, ConfigData &data)
{
	data.setKeyName(value);
}

void Config::parseRootPath(const std::string &value, ConfigData &data)
{
	data.setRootPath(ROOT_PATH + value);
}

void Config::parseAliasPath(const std::string &value, ConfigData &data)
{
	data.setAliasPath(ROOT_PATH + value);
}

void Config::parseIndexPages(const std::string &value, ConfigData &data)
{
	if (data.getIsIndexPagesParsed() == false)
	{
		data.setDefalutIndexPage();
		data.setIsIndexPagesParsed(true);
	}
	data.setIndexPages(value);
}

void Config::parseReturnCode(const std::string &value, ConfigData &data)
{
	StringVec splitData = strSplit(value, ' ');

	if (splitData.size() == 2)
		data.setReturnPath(strToSize(splitData[0]), splitData[1]);
}

void Config::parseAllowMethods(const std::string &value, ConfigData &data)
{
	StringVec methods = strSplit(value, ' ');

	if (data.getIsAllowMethodsParsed() == false)
	{
		data.setAllowMethods(RequestMethod::GET, false);
		data.setAllowMethods(RequestMethod::POST, false);
		data.setAllowMethods(RequestMethod::DELETE, false);
		data.setAllowMethods(RequestMethod::PUT, false);
		data.setIsAllowMethodsParsed(true);
	}
	for (size_t i = 0; i < methods.size(); ++i)
		data.setAllowMethods(methods[i], true);
}

void Config::parseErrorPage(const std::string &value, ConfigData &data)
{
	StringVec errorCodes = strSplit(value, ' ');
	if (errorCodes.size() < 2)
		return ;
	std::string errorPath = errorCodes[errorCodes.size() - 1];
	for (size_t i = 0; i < errorCodes.size() - 1; ++i)
	{
		if (!isAllDigits(errorCodes[i]))
			continue;
		data.setErrorPage(errorCodes[i], errorPath);
	}
}

Config &Config::operator=(const Config &other)
{
	if (this != &other)
	{
		data = other.data;
		locationData = other.locationData;
	}
	return (*this);
}
