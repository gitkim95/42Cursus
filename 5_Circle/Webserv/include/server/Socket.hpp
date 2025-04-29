/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:48:40 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/20 17:01:44 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <arpa/inet.h>
#include <ctime>

#define DEFAULT_TIMEOUT 30000 // 30seconds

class Socket
{
private:
	struct sockaddr_in addr;
	int sock;
	time_t actTime;
	time_t timeout;

public:
	Socket();
	Socket(int socketFd);
	Socket(int socketFd, struct sockaddr_in addr);
	Socket(sa_family_t family, uint32_t inAddr, uint16_t inPort, int type);
	Socket(const Socket &socket);
	~Socket();

	void act(void);

	const int &getFd(void) const;
	const struct sockaddr_in &getAddr(void) const;
	const time_t &getAct(void) const;
	const time_t &getTimeout(void) const;

	Socket &operator=(const Socket &socket);
};

#endif