/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponseGenerator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:17:12 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/30 21:36:39 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSEGENERATOR_HPP
#define RESPONSEGENERATOR_HPP

#include <string>
#include <vector>
#include <map>
#include "response/Response.hpp"
#include "request/Request.hpp"

class ResponseGenerator
{
private:
	static StringMap getDefaultMimeTypes();
	static StringMap loadMimeTypes();
	static StringVec listDirectory(const std::string &path);
	static CharVec generateHtmlList(const std::string &path, const StringVec &list);
	static CharVec generateHtmlPost(const std::string &fileUri);
	static const Config &getCurrentConfig(Client *client, MetaConfig &metaConfig);
	static const std::string getRedirectionURL(const ConfigData &data, const std::string &uri);
	static const std::string getErrorPath(Client *client, const PathType &status);
	static const std::string getIndexPath(Client *client, const std::string &path);

	ResponseGenerator();

public:
	static void setResponseCookie(Response &Response, Cookie &cookie);
	static std::string getMimeType(const std::string &path);
	static std::string getFileExtension(const std::string &path);
	static const CharVec getFileData(Client *client);
	static const Response getResponseData(Client *client, const CharVec &fileData);

	static Response errorResponse(PathType pathType, Client *client);
};

#endif