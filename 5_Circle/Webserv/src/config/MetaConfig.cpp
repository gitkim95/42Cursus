/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MetaConfig.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:04:22 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/29 18:00:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include "server/Server.hpp"
#include "utils/utils.hpp"

#include "config/MetaConfig.hpp"

static bool isEnterBlock(const std::string &line);
static bool isExitBlock(const int &braceCount);
static bool isLocationBlock(const std::string &line);

MetaConfig::MetaConfig() {}

void MetaConfig::applyConfigFile(const std::string &configFile)
{
	StringVec lines = getFileLines(configFile);
	std::vector<StringVec> serverBlocks = getServerBlocks(lines);
	matchData(serverBlocks);
}

StringVec MetaConfig::getFileLines(const std::string &filePath)
{
	StringVec lines;
	std::ifstream file(filePath.c_str());
	std::string line;

	if (file.is_open())
	{
		while (std::getline(file, line))
			lines.push_back(line);
		file.close();
	}
	return (lines);
}

std::vector<StringVec> MetaConfig::getServerBlocks(const StringVec &lines)
{
	std::vector<StringVec> serverBlocks;
	serverBlocks.clear();

	bool inBlock = false;
	int braceCount = 0;
	StringVec currentBlock;

	for (size_t i = 0; i < lines.size(); ++i)
	{
		std::string trimmed = trimBlank(lines[i]);

		if (!inBlock && isEnterBlock(trimmed))
		{
			inBlock = true;
			braceCount = 1;
			currentBlock.clear();
			currentBlock.push_back(trimmed);
		}
		else if (inBlock)
		{
			for (size_t j = 0; j < trimmed.size(); ++j)
			{
				if (trimmed[j] == '{')
					braceCount++;
				else if (trimmed[j] == '}')
					braceCount--;
			}
			currentBlock.push_back(trimmed);
			if (isExitBlock(braceCount))
			{
				inBlock = false;
				serverBlocks.push_back(currentBlock);
			}
		}
	}
	return (serverBlocks);
}

void MetaConfig::matchData(const std::vector<StringVec> &serverBlocks)
{
	for (size_t i = 0; i < serverBlocks.size(); ++i)
	{
		StringVec block = serverBlocks[i];
		Config serverData;
		parseServerBlock(block, serverData);

		std::vector<StringVec> locationBlocks = getLocationBlocks(block);
		matchLocationData(locationBlocks, serverData);

		std::string key = generateConfigKey(serverData.getData().getKeyName(), serverData.getData().getInPort());
		setConfigMap(key, serverData);
	}
}

void MetaConfig::parseServerBlock(const StringVec &block, Config &serverData)
{
	for (size_t i = 0; i < block.size(); ++i)
	{
		std::string line = block[i];

		if (line.find("listen") == 0)
			serverData.parseListen(extractValue(line), serverData.getData());
		else if (line.find("autoindex") == 0)
			serverData.parseAutoIndex(extractValue(line), serverData.getData());
		else if (line.find("client_max_body_size") == 0)
			serverData.parseMaxBodySize(extractValue(line), serverData.getData());
		else if (line.find("server_name") == 0)
			serverData.parseServerName(extractValue(line), serverData.getData());
		else if (line.find("root") == 0)
			serverData.parseRootPath(extractValue(line), serverData.getData());
		else if (line.find("index") == 0)
			serverData.parseIndexPages(extractValue(line), serverData.getData());
		else if (line.find("allow_methods") == 0)
			serverData.parseAllowMethods(extractValue(line), serverData.getData());
		else if (line.find("return") == 0)
			serverData.parseReturnCode(extractValue(line), serverData.getData());
		else if (line.find("error_page") == 0)
			serverData.parseErrorPage(extractValue(line), serverData.getData());
		else if (line.find("location") == 0)
		{
			while (block[i].find("}") == std::string::npos)
				i++;
		}
	}
}

std::vector<StringVec> MetaConfig::getLocationBlocks(const StringVec &lines)
{
	std::vector<StringVec> locationBlocks;
	locationBlocks.clear();

	bool inLocationBlock = false;
	int braceCount = 0;
	StringVec currentBlock;

	for (size_t i = 0; i < lines.size(); ++i)
	{
		std::string trimmed = trimBlank(lines[i]);

		if (!inLocationBlock && isLocationBlock(trimmed))
		{
			inLocationBlock = true;
			braceCount = 1;
			currentBlock.clear();
			currentBlock.push_back(trimmed);
		}
		else if (inLocationBlock)
		{
			for (size_t j = 0; j < trimmed.size(); ++j)
			{
				if (trimmed[j] == '{')
					braceCount++;
				else if (trimmed[j] == '}')
					braceCount--;
			}
			currentBlock.push_back(trimmed);
			if (isExitBlock(braceCount))
			{
				inLocationBlock = false;
				locationBlocks.push_back(currentBlock);
			}
		}
	}
	return (locationBlocks);
}

void MetaConfig::matchLocationData(const std::vector<StringVec> &locationBlocks, Config &serverData)
{
	for (size_t i = 0; i < locationBlocks.size(); ++i)
	{
		StringVec block = locationBlocks[i];
		Config locationData = serverData;
		locationData.setIsLocation(true);
		locationData.resetIndexPagesConfig();
		locationData.resetAllowMethodConfig();
		parseLocationBlock(block, locationData, serverData);
	}
}

void MetaConfig::parseLocationBlock(const StringVec &locationBlock, Config &locationData, Config &serverData)
{
	for (size_t i = 0; i < locationBlock.size(); ++i)
	{
		std::string line = locationBlock[i];

		if (line.find("autoindex") == 0)
			locationData.parseAutoIndex(extractValue(line), locationData.getData());
		else if (line.find("client_max_body_size") == 0)
			locationData.parseMaxBodySize(extractValue(line), locationData.getData());
		else if (line.find("root") == 0)
			locationData.parseRootPath(extractValue(line), locationData.getData());
		else if (line.find("alias") == 0)
			locationData.parseAliasPath(extractValue(line), locationData.getData());
		else if (line.find("index") == 0)
			locationData.parseIndexPages(extractValue(line), locationData.getData());
		else if (line.find("allow_methods") == 0)
			locationData.parseAllowMethods(extractValue(line), locationData.getData());
		else if (line.find("return") == 0)
			locationData.parseReturnCode(extractValue(line), locationData.getData());
	}
	locationData.parseServerName(getLocationTarget(locationBlock), locationData.getData());
	serverData.setLocationData(locationData.getData());
}

std::string MetaConfig::getLocationTarget(const StringVec &block)
{
	StringVec firstLine = strSplit(block[0], ' ');

	if (firstLine.size() == 3)
		return (firstLine[1]);
	return ("_");
}

void MetaConfig::setConfigMap(const std::string &key, const Config &value)
{
	Config currentData = value;
	if (this->configMap.count(key) == 0)
		configMap[key] = value;
	else 
		throw std::runtime_error("Duplicate host:port configuration detected");
}

void MetaConfig::setDefaultConfig()
{
	std::map<std::string, Config>::iterator it;
	uint16_t port;
	bool isDefaultConfig;

	if (this->configMap.empty())
	{
		this->defaultConfig[WEBSERV_PORT] = Config();
	}
	for (it = this->configMap.begin(); it != this->configMap.end(); ++it)
	{
		port = it->second.getData().getInPort();
		isDefaultConfig = it->second.getData().getIsDefaultServer();

		if (this->defaultConfig.count(port) == 0)
			this->defaultConfig[port] = it->second;
		else if (isDefaultConfig && this->defaultConfig[port].getData().getIsDefaultServer() == false)
			this->defaultConfig[port] = it->second;
	}
}

std::map<uint16_t, Config> &MetaConfig::getDefaultConfig()
{
	return (this->defaultConfig);
}

std::map<std::string, Config> &MetaConfig::getConfigMap()
{
	return (this->configMap);
}

Config &MetaConfig::getConfig(const std::string &host, const uint16_t &port)
{
	std::string key = generateConfigKey(host, port);

	if (configMap.count(key) > 0)
		return (this->configMap[key]);
	return (this->defaultConfig[port]);
}

std::string MetaConfig::generateConfigKey(const std::string &host, const uint16_t &port)
{
	std::stringstream ss;

	ss << host << ":" << port;
	return (ss.str());
}

static bool isEnterBlock(const std::string &line)
{
	return (!line.find("server") && line.find("{") != std::string::npos);
}

static bool isExitBlock(const int &braceCount)
{
	return (braceCount == 0);
}

static bool isLocationBlock(const std::string &line)
{
	return (!line.find("location") && line.find("{") != std::string::npos);
}