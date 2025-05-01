/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 04:53:47 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/30 20:40:16 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <map>
#include <unistd.h>
#include <sys/wait.h>
#include "context/Context.hpp"
#include "response/ResponseGenerator.hpp"
#include "utils/utils.hpp"

#include "server/CGI.hpp"

/* private */
StringMap CGI::cgiPath = CGI::initCgiPath();

StringMap CGI::initCgiPath()
{
	StringMap cgiPath;

	std::ifstream file("cgi.types");
	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty() || line[0] == '#')
			continue;
		std::istringstream iss(line);
		std::string path, ext;
		iss >> path;
		while (iss >> ext)
			cgiPath[ext] = path;
	}
	return (cgiPath);
}

const std::string CGI::getCgiPath(const std::string &requestUri)
{
	std::string fileExtension = ResponseGenerator::getFileExtension(requestUri);

	if (CGI::cgiPath.count(fileExtension) > 0)
		return (CGI::cgiPath[fileExtension]);
	return ("");
}

CGI::CGI() {}

char **CGI::generateCGIEnv(const Request &request)
{
	std::string requestUri = request.getRequestUri();
	std::string extension = ResponseGenerator::getFileExtension(requestUri);
	size_t offset = extension.size() + 1;

	Context::env.putenv(REQUEST_METHOD, request.getMethod());
	Context::env.putenv(REDIRECT_STATUS, "200");
	Context::env.putenv(SCRIPT_FILENAME, const_cast<char *>(request.getFilePath().c_str()));

	size_t queryString = requestUri.find('?');
	if (RequestMethod::GET == request.getMethod())
	{
		if (queryString != std::string::npos)
			Context::env.putenv(QUERY_STRING, requestUri.substr(queryString + 1));
	}
	else if (RequestMethod::POST == request.getMethod())
	{
		Context::env.putenv(CONTENT_LENGTH, request.getHeader().getAttributeValue("Content-Length"));
		Context::env.putenv(CONTENT_TYPE, request.getHeader().getAttributeValue("Content-Type"));
	}

	size_t ext = requestUri.find(extension) - 1;
	if (ext != std::string::npos)
	{
		if (queryString != std::string::npos)
			Context::env.putenv(PATH_INFO, requestUri.substr(ext + offset, queryString - (ext + offset)));
		else if (ext + offset != requestUri.length())
			Context::env.putenv(PATH_INFO, requestUri.substr(ext + offset));
	}

	return (Context::env.toEnvArray());
}

/* public */
int CGI::execute(Client *client, int *in, int *out)
{
	pid_t pid;
	const Request &request = client->getRequest();

	pid = fork();
	if (pid < 0)
	{
		closePipes(in);
		closePipes(out);
		return (CGI_ERROR);
	}
	if (pid == 0)
	{
		std::string currentCgiPath = CGI::getCgiPath(request.getRequestUri());
		char *argv[3] = {const_cast<char *>(currentCgiPath.c_str()), const_cast<char *>(request.getFilePath().c_str()), NULL};
		char **cgiEnv = generateCGIEnv(request);

		if (request.getMethod() == RequestMethod::POST)
			dup2(in[0], STDIN_FILENO);
		dup2(out[1], STDOUT_FILENO);
		closePipes(in);
		closePipes(out);
		if (execve(argv[0], argv, cgiEnv) < 0)
		{
			freeSplit(cgiEnv);
			write(STDOUT_FILENO, "ERROR", 6);
			throw std::runtime_error("CGI: execve failed");
		}
	}
	client->setCgiPid(pid);
	client->setReadFd(out[0]);
	return (1);
}

void CGI::setPath(const std::string &extension, const std::string &path)
{
	CGI::cgiPath[extension] = path;
}
