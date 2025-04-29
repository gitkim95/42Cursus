/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MetaConfig.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:03:10 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/26 18:32:16 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef META_CONFIG_HPP
#define META_CONFIG_HPP

#include "Config.hpp"

class MetaConfig
{
private:
	std::map<uint16_t, Config> defaultConfig;
	std::map<std::string, Config> configMap;

	StringVec getFileLines(const std::string &filePath);
	std::string getLocationTarget(const StringVec &block);
	
	std::vector<StringVec> getServerBlocks(const StringVec &lines);
	void matchData(const std::vector<StringVec> &serverBlocks);
	void parseServerBlock(const StringVec &block, Config &serverData);
	
	std::vector<StringVec> getLocationBlocks(const StringVec &lines);
	void matchLocationData(const std::vector<StringVec> &locationBlocks, Config &serverData);
	void parseLocationBlock(const StringVec &locationBlock, Config &locationData, Config &serverData);

public:
	MetaConfig();
	
	std::map<uint16_t, Config> &getDefaultConfig();
	std::map<std::string, Config> &getConfigMap();
	Config &getConfig(const std::string &host, const uint16_t &port);
	
	void setConfigMap(const std::string &key, const Config &value);
	void setDefaultConfig();
	void applyConfigFile(const std::string &configFile);
	
	static std::string generateConfigKey(const std::string &host, const uint16_t &port);
};

#endif