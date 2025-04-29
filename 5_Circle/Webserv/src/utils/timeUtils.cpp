/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:31:01 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/29 03:26:55 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <cstdio>
#include <ctime>

#include "utils/utils.hpp"

time_t getCurrentTimeMillis(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

std::string formatMillisToDateTime(const std::string &millisStr)
{
	std::time_t seconds = static_cast<std::time_t>(strToSize(millisStr) / 1000);

	std::tm *tm_info = std::localtime(&seconds);
	if (!tm_info)
		return ("Invalid Time");

	char buffer[20];
	std::sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d",
				 tm_info->tm_year + 1900,
				 tm_info->tm_mon + 1,
				 tm_info->tm_mday,
				 tm_info->tm_hour,
				 tm_info->tm_min,
				 tm_info->tm_sec);

	return (std::string(buffer));
}
