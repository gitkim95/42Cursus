/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Session.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:36:53 by gitkim            #+#    #+#             */
/*   Updated: 2025/04/29 03:26:12 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SESSION_HPP
#define SESSION_HPP

#include <ctime>
#include "sys/types.hpp"

class Session
{
private:
	std::map<std::string, StringVec> connectionTimes;

public:
	const std::map<std::string, StringVec> &getConnectionTimes() const;
	const StringVec getConnectionTimes(const std::string &uuid);

	bool isSessionRequest(const std::string &filePath) const;

	void setConnectionTimes(const std::string &uuid, const std::string &currentConnectionTime);
	CharVec getSessionPage(const std::string &session_id, const std::string &filePath);
};

#endif