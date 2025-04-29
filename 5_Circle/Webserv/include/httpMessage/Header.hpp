/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:35:44 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/29 03:25:49 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP

#include <map>
#include <string>
#include "statuscode/StatusCode.hpp"
#include "sys/types.hpp"

class Header
{
private:
	static const std::string EMPTY_HEADER;

	StatusCode statusCode;
	MultiStringMap attributes;

public:
	Header();
	Header(const StatusCode &statusCode);
	Header(const StatusCode &statusCode, const std::string &contentType);
	Header(const Header &header);

	const StatusCode &getStatusCode() const;
	const std::string &getAttributeValue(const std::string &key) const;
	const MultiStringMap &getAttribute() const;
	bool hasAttribute(std::string key) const;
	void setAttribute(const std::string &key, const std::string &value);
	void changeAttributeValue(const std::string &key, const std::string &value);

	Header &operator=(const Header &header);
};

#endif