/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cookie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:35:14 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/28 18:58:53 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <sstream>
#include <utils/utils.hpp>

#include "httpMessage/Cookie.hpp"

Cookie::Cookie() : maxAge(DEFAULT_MAX_AGE), httpOnly(false) {}

void Cookie::setCookies(const std::string &key, const std::string &value) { this->cookies[key] = value; }
void Cookie::setPath(const std::string &path) { this->path = path; }
void Cookie::setDomain(const std::string &domain) { this->domain = domain; }
void Cookie::setMaxAge(int seconds) { this->maxAge = seconds; }
void Cookie::setHttpOnly(bool httpOnly) { this->httpOnly = httpOnly; }

const StringMap &Cookie::getCookies() const { return (this->cookies); }

const std::string Cookie::getCookieValue(const std::string &key)
{
	if (this->hasCookie(key))
		return (this->cookies[key]);
	return ("");
}

bool Cookie::hasCookie(const std::string &key) const
{
	return (this->cookies.count(key) > 0);
}

StringSet Cookie::toSetCookieHeader() const
{
	StringSet cookieSet;

	StringMap::const_iterator it;
	for (it = this->cookies.begin(); it != this->cookies.end(); ++it)
	{
		std::stringstream stream;
		stream << it->first << "=" << it->second;
		if (!this->path.empty())
			stream << "; Path=" << this->path;
		if (!this->domain.empty())
			stream << "; Domain=" << this->domain;
		if (this->maxAge >= 0)
			stream << "; Max-Age=" << this->maxAge;
		if (this->httpOnly)
			stream << "; HttpOnly";
		cookieSet.insert(stream.str());
	}

	return (cookieSet);
}

std::string Cookie::generateUUID() const
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}

	char uuid[37];

	size_t pos = 0;
	for (size_t i = 0; i < 36; ++i)
	{
		if (i == 8 || i == 13 || i == 18 || i == 23)
		{
			uuid[pos] = '-';
			++pos;
		}
		else
		{
			int r = std::rand() % 16;
			uuid[pos] = HEX_DIGITS[r];
			++pos;
		}
	}
	uuid[pos] = '\0';

	return (std::string(uuid));
}
