/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 04:53:47 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/27 00:50:20 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGI_HPP
#define CGI_HPP

#include <map>
#include <string>
#include "request/Request.hpp"

#define CGI_ERROR -1
#define EMPTY_RESPONSE ""
#define REQUEST_METHOD "REQUEST_METHOD"
#define PATH_INFO "PATH_INFO"
#define QUERY_STRING "QUERY_STRING"
#define REDIRECT_STATUS "REDIRECT_STATUS"
#define DOCUMENT_ROOT "DOCUMENT_ROOT"
#define SCRIPT_FILENAME "SCRIPT_FILENAME"
#define CONTENT_LENGTH "CONTENT_LENGTH"
#define CONTENT_TYPE "CONTENT_TYPE"

class CGI
{
private:
	static StringMap cgiPath;
	static StringMap initCgiPath();
	static const std::string getCgiPath(const std::string &requestUri);

	static char **generateCGIEnv(const Request &request);

	CGI();

public:
	static int execute(const Request &request, int *in, int *out);
	static void setPath(const std::string &extension, const std::string &path);
};

#endif