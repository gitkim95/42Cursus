/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cookie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:37:22 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/28 18:58:34 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COOKIE_HPP
#define COOKIE_HPP

#define VISITED_KEY "visited"
#define SESSION_KEY "session_id"
#define HEX_DIGITS "0123456789abcdef"
#define DEFAULT_MAX_AGE 86400

#include "sys/types.hpp"

class Cookie
{
private:
	StringMap cookies;
	std::string path;
	std::string domain;
	int maxAge;
	bool httpOnly;

public:
	Cookie();

	void setCookies(const std::string &key, const std::string &value);
	void setPath(const std::string &path);
	void setDomain(const std::string &domain);
	void setMaxAge(int seconds);
	void setHttpOnly(bool httpOnly);
	void setSecure(bool secure);

	const StringMap &getCookies() const;
	const std::string getCookieValue(const std::string &key);
	bool hasCookie(const std::string &key) const;

	StringSet toSetCookieHeader() const;
	std::string generateUUID() const;
};

#endif