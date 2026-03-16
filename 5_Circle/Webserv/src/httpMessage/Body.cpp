/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Body.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:03:07 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/27 17:35:11 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sys/types.hpp"
#include "utils/utils.hpp"

#include "httpMessage/Body.hpp"

/* public */
Body::Body() {}

Body::Body(const CharVec &content)
{
	this->content = content;
}

Body::Body(const Body &body) { *this = body; }

const CharVec &Body::getContent() const { return (this->content); }
const std::map<std::string, CharVec> &Body::getFileData() const { return (this->fileData); }

void Body::setContent(const CharVec &content) { this->content = content; }
void Body::setFileData(const std::string &fileName, const CharVec &fileBody) { this->fileData[fileName] = fileBody; }

const bool Body::isAlreadyExistKey(const std::string &filename) const
{
	return (this->fileData.count(filename) > 0);
}
const std::string Body::changeFileName(const std::string &filename) const
{
	StringVec nameSplit = strSplit(filename, '/');
	if (nameSplit.empty())
		return ("");
	std::string filteredName = nameSplit.back();
	std::string baseName = filteredName;
	std::string extension = "";

	size_t dotPos = filteredName.rfind('.');
	if (dotPos != std::string::npos && dotPos != 0)
	{
		baseName = filteredName.substr(0, dotPos);
		extension = filteredName.substr(dotPos);
	}

	std::string newFilename = filteredName;
	size_t idx = 2;
	while (this->isAlreadyExistKey(newFilename))
	{
		newFilename = baseName + "(" + sizeToStr(idx) + ")" + extension;
		idx++;
	}
	return (newFilename);
}

Body &Body::operator=(const Body &body)
{
	if (this != &body)
	{
		this->content = body.content;
		this->fileData = body.fileData;
	}
	return (*this);
}
