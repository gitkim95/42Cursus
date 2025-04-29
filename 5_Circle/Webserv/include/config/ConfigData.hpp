/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:58:30 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/28 18:56:37 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_DATA_HPP
#define CONFIG_DATA_HPP

#define ROOT_PATH "./resources/"
#define ERROR_PATH "/errors/"
#define UPLOAD_PATH "/upload/"
#define DEFAULT_NAME "localhost"
#define KB 1024L
#define MB (KB * KB)

#include <arpa/inet.h>
#include "sys/types.hpp"

class ConfigData
{
private:
	uint16_t inPort;
	bool isLocationData;
	bool isIndexPagesParsed;
	bool isAllowMethodsParsed;
	bool isDefaultServer;
	bool turnOnAutoIndex;
	size_t maxBodySize;
	std::string keyName;
	std::string rootPath;
	std::string aliasPath;
	std::string uploadPath;
	StringSet indexPages;
	std::map<std::string, bool> allowMethods;
	std::map<int, std::string> returnPath;
	std::map<int, std::string> errorPage;

public:
	ConfigData(void);

	void setInPort(const uint16_t &port);
	void setIsLocationData(const bool &isLocation);
	void setIsIndexPagesParsed(const bool &isParsed);
	void setIsAllowMethodsParsed(const bool &isParsed);
	void setIsDefaultServer(const bool &isDefault);
	void setTurnOnAutoIndex(const bool &isTurnOn);
	void setMaxBodySize(const size_t &bodySize);
	void setKeyName(const std::string &name);
	void setRootPath(const std::string &path);
	void setAliasPath(const std::string &aliasPath);
	void setUploadPath(const std::string &uploadPath);
	void setIndexPages(const std::string &indexPage);
	void setAllowMethods(const std::string &method, const bool &isEnabled);
	void setReturnPath(const int &returnCode, const std::string &returnPath);
	void setErrorPage(const std::string &errorCode, const std::string &errorPath);

	const uint16_t &getInPort() const;
	const bool &getIsLocationData() const;
	const bool &getIsIndexPagesParsed() const;
	const bool &getIsAllowMethodsParsed() const;
	const bool &getIsDefaultServer() const;
	const bool &getTurnOnAutoIndex() const;
	const size_t &getMaxBodySize() const;
	const std::string &getKeyName() const;
	const std::string &getRootPath() const;
	const std::string &getAliasPath() const;
	const std::string &getUploadPath() const;
	const StringSet &getIndexPages() const;
	const std::map<std::string, bool> &getAllowMethods() const;
	const std::map<int, std::string> &getReturnPath() const;
	const std::map<int, std::string> &getErrorPage() const;

	void setDefaultErrorPage();
	void setDefaultAllowMethods();
	void setDefalutIndexPage();

	const std::string getAllowedMethods() const;

	ConfigData &operator=(const ConfigData &other);
};

#endif