/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusCode.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:34:32 by hwilkim           #+#    #+#             */
/*   Updated: 2025/03/07 18:38:52 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "statuscode/StatusCode.hpp"

/* private */
StatusCode::StatusCode() {}

/* public */
StatusCode::StatusCode(int code, std::string message)
{
	this->code = code;
	this->message = message;
}

StatusCode::StatusCode(const StatusCode &statusCode)
{
	this->code = statusCode.code;
	this->message = statusCode.message;
}

const int &StatusCode::getCode() const
{
	return (this->code);
}

const std::string &StatusCode::getMessage() const
{
	return (this->message);
}

StatusCode &StatusCode::operator=(const StatusCode &statusCode)
{
	if (this != &statusCode)
	{
		this->code = statusCode.code;
		this->message = statusCode.message;
	}
	return (*this);
}

bool StatusCode::operator==(const StatusCode &statusCode) const
{
	return (this->code == statusCode.code);
}