/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdUtils.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 04:38:49 by hwilkim           #+#    #+#             */
/*   Updated: 2025/04/23 20:58:53 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <stdexcept>

#include "utils/utils.hpp"

int epCtl(int epfd, int opt, int fd, uint32_t events)
{
	static struct epoll_event EV_EMPTY;
	struct epoll_event ev = EV_EMPTY;

	ev.events = events;
	ev.data.fd = fd;
	return (epoll_ctl(epfd, opt, fd, &ev));
}

void setFdNonBlock(int fd)
{
	int flags = fcntl(fd, F_GETFL, 0);

	if (flags == -1)
		throw std::runtime_error("fcntl F_GETFL fail");
	if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)
		throw std::runtime_error("fcntl F_SETFL fail");
}

void setFdNonBlock(int *pipeDes)
{
	setFdNonBlock(pipeDes[0]);
	setFdNonBlock(pipeDes[1]);
}

void closePipes(int *pipeDes)
{
	close(pipeDes[0]);
	close(pipeDes[1]);
}
