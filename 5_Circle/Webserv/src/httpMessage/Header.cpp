/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:36:23 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/29 03:26:27 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "utils/utils.hpp"

#include "httpMessage/Header.hpp"

/* private */
const std::string Header::EMPTY_HEADER = "";

/* public */
Header::Header() : statusCode(HttpStatus::NONE) {}

Header::Header(const StatusCode &statusCode) : statusCode(statusCode) {}

Header::Header(const Header &header) : statusCode(header.statusCode) { *this = header; }

const StatusCode &Header::getStatusCode() const
{
	return (this->statusCode);
}

const std::string &Header::getAttributeValue(const std::string &key) const
{
	MultiStringMap::const_iterator it = attributes.find(key);
	if (it != attributes.end())
		return (it->second);
	return (EMPTY_HEADER);
}

const MultiStringMap &Header::getAttribute() const
{
	return (attributes);
}

bool Header::hasAttribute(std::string key) const
{
	return (attributes.count(key) > 0);
}

void Header::setAttribute(const std::string &key, const std::string &value)
{
	attributes.insert(std::make_pair(key, value));
}

void Header::changeAttributeValue(const std::string &key, const std::string &value)
{
	MultiStringMap::iterator it = this->attributes.find(key);
	if (it != this->attributes.end())
		it->second = value;
}

Header &Header::operator=(const Header &header)
{
	if (this != &header)
	{
		this->statusCode = header.statusCode;
		this->attributes = header.attributes;
	}
	return (*this);
}