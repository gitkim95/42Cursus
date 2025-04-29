/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:51:00 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/20 16:55:38 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <stdexcept>
#include "utils/utils.hpp"

#include "server/Socket.hpp"

/* private */

/* public */
Socket::Socket() { this->sock = 0; }

Socket::Socket(int socketFd)
{
	this->sock = socketFd;
	this->act();
}

Socket::Socket(int socketFd, struct sockaddr_in addr)
{
	this->sock = socketFd;
	this->addr = addr;
	this->act();
}

Socket::Socket(sa_family_t family, uint32_t inAddr, uint16_t inPort, int type)
{
	std::memset(&this->addr, 0, sizeof(this->addr));
	this->addr.sin_family = family;
	this->addr.sin_addr.s_addr = htonl(inAddr);
	this->addr.sin_port = htons(inPort);

	this->sock = socket(family, type, 0);
	this->act();
}

Socket::Socket(const Socket &socket)
{
	*this = socket;
}

Socket::~Socket()
{
	if (this->sock)
		close(this->sock);
}

void Socket::act(void)
{
	this->actTime = getCurrentTimeMillis();
	this->timeout = this->actTime + DEFAULT_TIMEOUT;
}

const int &Socket::getFd(void) const { return (this->sock); }

const struct sockaddr_in &Socket::getAddr(void) const { return (this->addr); }

const time_t &Socket::getAct(void) const { return (this->actTime); }

const time_t &Socket::getTimeout(void) const { return (this->timeout); }

Socket &Socket::operator=(const Socket &socket)
{
	if (this != &socket)
	{
		this->addr = socket.addr;
		this->sock = socket.sock;
		this->actTime = socket.actTime;
		this->timeout = socket.timeout;
	}
	return (*this);
}
