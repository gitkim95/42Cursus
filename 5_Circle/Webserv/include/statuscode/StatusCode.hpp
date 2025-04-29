/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusCode.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:34:32 by hwilkim           #+#    #+#             */
/*   Updated: 2025/03/07 18:51:20 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_CODE_HPP
#define STATUS_CODE_HPP

#include <string>

class StatusCode
{
private:
	int code;
	std::string message;

	StatusCode();

public:
	StatusCode(int code, std::string message);
	StatusCode(const StatusCode &statusCode);

	const int &getCode() const;
	const std::string &getMessage() const;

	StatusCode &operator=(const StatusCode &statusCode);
	bool operator==(const StatusCode &statusCode) const;
};

namespace HttpStatus
{
	const ::StatusCode OK(200, "OK");
	const ::StatusCode CREATED(201, "Created");
	const ::StatusCode NO_CONTENT(204, "No Content");
	const ::StatusCode MOVED_PERMANENTLY(301, "Moved Permanently");
	const ::StatusCode FOUND(302, "Found");
	const ::StatusCode NOT_MODIFIED(304, "Not Modified");
	const ::StatusCode BAD_REQUEST(400, "Bad Request");
	const ::StatusCode UNAUTHORIZED(401, "Unauthorized");
	const ::StatusCode FORBIDDEN(403, "Forbidden");
	const ::StatusCode NOT_FOUND(404, "Not Found");
	const ::StatusCode METHOD_NOT_ALLOWED(405, "Method Not Allowed");
	const ::StatusCode CONFLICT(409, "Conflict");
	const ::StatusCode PAYLOAD_TOO_LARGE(413, "Payload Too Large");
	const ::StatusCode UNSUPPORTED_MEDIA_TYPE(415, "Unsupported Media Type");
	const ::StatusCode UNPROCESSABLE_ENTITY(422, "Unprocessable Entity");
	const ::StatusCode INTERNAL_SERVER_ERROR(500, "Internal Server Error");
	const ::StatusCode SERVICE_UNAVAILABLE(503, "Service Unavailable");
	const ::StatusCode GATEWAY_TIMEOUT(504, "Gateway Timeout");

	const ::StatusCode NONE(-1, "");
};

#endif