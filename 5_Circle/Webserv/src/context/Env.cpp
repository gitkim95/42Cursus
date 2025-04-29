/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:57:39 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/26 18:25:56 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <stdexcept>
#include <unistd.h>

#include "context/Env.hpp"

/* static */
std::string Env::emptyStr = "";

/* private */
Env::Env() {}

/* public */
Env &Env::getInstance()
{
	static Env instance;

	if (instance.empty())
	{
		for (int i = 0; environ[i]; ++i)
		{
			std::string envStr(environ[i]);
			size_t delim = envStr.find('=');
			if (delim != std::string::npos)
			{
				std::string key = envStr.substr(0, delim);
				std::string value = envStr.substr(delim + 1);
				instance.putenv(key, value);
			}
		}
	}
	return (instance);
}

std::string &Env::getenv(const std::string &key)
{
	if (this->env.find(key) == this->env.end())
		return (Env::emptyStr);
	return (Env::env[key]);
}

void Env::putenv(const std::string &key, const std::string &value)
{
	Env::env[key] = value;
}

bool Env::empty() { return (this->env.empty()); }

size_t Env::size() { return (this->env.size()); }

char **Env::toEnvArray()
{
	char **envArray = new char *[this->size() + 1];
	StringMap::iterator it = this->env.begin();

	for (size_t i = 0; i < this->size(); ++i)
	{
		std::string envStr = (it->first + "=" + it->second);
		envArray[i] = new char[envStr.length() + 1];
		std::strcpy(envArray[i], envStr.c_str());
		++it;
	}
	envArray[this->size()] = NULL;
	return (envArray);
}
