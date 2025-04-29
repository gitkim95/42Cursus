/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strUtils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:59:24 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/29 03:26:52 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <fstream>
#include <cctype>

#include "utils/utils.hpp"

static bool isBlank(char c);

StringVec strSplit(const std::string &str, char delim)
{
	StringVec split;
	std::stringstream stream;
	std::string token;

	stream.str(str);
	while (std::getline(stream, token, delim))
		if (!token.empty())
			split.push_back(token);
	return (split);
}

size_t strToSize(const std::string &str)
{
	size_t result = 0;
	size_t i = 0;

	while (i < str.size() && isBlank(str[i]))
		i++;
	while (i < str.size() && std::isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

std::string sizeToStr(size_t value)
{
	std::ostringstream oss;
	oss << value;
	return (oss.str());
}

std::string trimBlank(const std::string &str)
{
	size_t start = 0;

	while (start < str.length() && isBlank(str[start]))
		++start;

	if (start == str.length())
		return ("");

	size_t end = str.length() - 1;
	while (end > start && isBlank(str[end]))
		--end;

	return (str.substr(start, end - start + 1));
}

std::string extractValue(const std::string &line)
{
	std::string trimmed = trimBlank(line);
	size_t space = trimmed.find(' ');
	size_t semicolon = trimmed.find(';');
	return (trimBlank(trimmed.substr(space + 1, semicolon - space - 1)));
}

static bool isBlank(char c)
{
	return (c == ' ' || c == '\t');
}

bool isAllDigits(const std::string &str)
{
	if (str.empty())
		return (false);

	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

std::string stripPrefix(const std::string &uri, const std::string &keyName)
{
	size_t i = 0;
	while (i < uri.size() && i < keyName.size() && uri[i] == keyName[i])
		++i;

	return (uri.substr(i));
}

std::string stripQuotes(const std::string &str)
{
	if (str.size() >= 2 && str[0] == '"' && str[str.size() - 1] == '"')
		return (str.substr(1, str.size() - 2));
	return (str);
}

void stripCarriage(std::string &str)
{
	if (!str.empty() && str[str.size() - 1] == '\r')
		str.erase(str.size() - 1);
}

CharVec readFileData(const std::string &filePath)
{
	std::ifstream file(filePath.c_str(), std::ios::binary);
	if (!file)
		return (CharVec());

	file.seekg(0, std::ios::end);
	std::ifstream::pos_type fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	CharVec fileData(static_cast<size_t>(fileSize));
	file.read(reinterpret_cast<char *>(&fileData[0]), fileSize);

	return (fileData);
}

std::string normalizedPath(const std::string &path)
{
	StringVec stack;
	std::stringstream ss(path);
	std::string segment;

	bool hasTrailingSlash = (!path.empty() && path[path.size() - 1] == '/');
	bool isAbsolute = (!path.empty() && path[0] == '/');
	bool hasDotSlash = (path.size() > 1 && path.substr(0, 2) == "./");

	while (std::getline(ss, segment, '/'))
	{
		if (segment.empty() || segment == ".")
			continue;
		else if (segment == "..")
		{
			if (!stack.empty())
				stack.pop_back();
		}
		else
			stack.push_back(segment);
	}

	std::string result;
	if (isAbsolute)
		result = "/";
	else if (hasDotSlash)
		result = "./";
	else
		result = "";

	for (size_t i = 0; i < stack.size(); ++i)
	{
		result += stack[i];
		if (i != stack.size() - 1)
			result += "/";
	}

	if (result.empty())
	{
		if (isAbsolute)
			result = "/";
		else if (hasDotSlash)
			result = "./";
		else
			result = ".";
	}

	if (hasTrailingSlash && !result.empty() && result[result.size() - 1] != '/')
		result += '/';

	return (result);
}

std::string getVecLine(const CharVec &buffer, size_t &pos)
{
	std::string line;

	while (pos < buffer.size())
	{
		unsigned char c = buffer[pos++];
		if (c == '\r' && pos < buffer.size() && buffer[pos] == '\n')
		{
			++pos;
			break;
		}
		line += c;
	}
	return (line);
}

void extractHeader(CharVec &httpMessage)
{
	const std::string delimiter = "\r\n\r\n";
	if (httpMessage.size() < delimiter.size())
		return;

	CharVec::iterator it;

	for (it = httpMessage.begin(); it != httpMessage.end() - delimiter.size() + 1; ++it)
	{
		if (std::equal(delimiter.begin(), delimiter.end(), it))
		{
			httpMessage.erase(httpMessage.begin(), it + delimiter.size());
			return;
		}
	}
}
