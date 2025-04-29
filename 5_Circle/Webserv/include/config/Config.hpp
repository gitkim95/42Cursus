/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:07:19 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/26 18:35:44 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <vector>
#include "ConfigData.hpp"
#include "sys/types.hpp"

class Config
{
private:
	ConfigData data;
	std::vector<ConfigData> locationData;

public:
	Config(void);

	ConfigData &getData();
	ConfigData &getLocationData(const std::string &key);

	void setLocationData(const ConfigData &value);
	void setIsLocation(const bool &isLocation);
	void resetAllowMethodConfig();
	void resetIndexPagesConfig();

	void parseListen(const std::string &value, ConfigData &data);
	void parseAutoIndex(const std::string &value, ConfigData &data);
	void parseMaxBodySize(const std::string &value, ConfigData &data);
	void parseServerName(const std::string &value, ConfigData &data);
	void parseRootPath(const std::string &value, ConfigData &data);
	void parseAliasPath(const std::string &value, ConfigData &data);
	void parseIndexPages(const std::string &value, ConfigData &data);
	void parseAllowMethods(const std::string &value, ConfigData &data);
	void parseReturnCode(const std::string &value, ConfigData &data);
	void parseErrorPage(const std::string &value, ConfigData &data);

	Config &operator=(const Config &other);
};

#endif
