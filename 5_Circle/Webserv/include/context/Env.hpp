/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:53:26 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/26 18:24:25 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_HPP
#define ENV_HPP

#include <string>
#include <map>
#include "sys/types.hpp"

class Env
{
private:
	static std::string emptyStr;

	StringMap env;

	Env();

public:
	static Env &getInstance();

	std::string &getenv(const std::string &key);
	void putenv(const std::string &key, const std::string &value);

	bool empty();
	size_t size();
	char **toEnvArray();
};

#endif