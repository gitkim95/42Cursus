/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:16:39 by hwilkim           #+#    #+#             */
/*   Updated: 2024/10/29 02:43:49 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static t_gnl_node	*get_fd_state(t_gnl_list *fd_list)
{
	t_gnl_node	*node;

	node = fd_list->head;
	if (!node)
	{
		node = (t_gnl_node *)malloc(sizeof(t_gnl_node));
		if (!node)
			return (NULL);
		node->buf = ft_substr("", 0, 0);
		if (!(node->buf))
			return (NULL);
		fd_list->head = node;
	}
	return (node);
}

static void	set_fd_state(t_gnl_node	*fd_state, char *str)
{
	free(fd_state->buf);
	fd_state->buf = str;
}

static char	*check_fd_ln(t_gnl_node *fd_state, char *buf)
{
	char	*ln;

	ln = fd_state->buf;
	while (*ln)
	{
		if (*ln == '\n')
			return (ln + 1);
		++ln;
	}
	if (*buf == '\0')
		return (ln);
	return (NULL);
}

static char	*get_fd_line(t_gnl_node *fd_state, char *buf)
{
	char		*ln;
	char		*line;

	ln = check_fd_ln(fd_state, buf);
	if (!ln)
		return (NULL);
	line = ft_substr(fd_state->buf, 0, ln - fd_state->buf);
	set_fd_state(fd_state, ft_substr(ln, 0, ft_strlen(ln)));
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	fd_list;
	t_gnl_node			*fd_state;
	ssize_t				read_len;
	char				buf[BUFFER_SIZE + 1];
	char				*str;

	str = NULL;
	fd_state = get_fd_state(&fd_list);
	while (!str)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0 || !(*(fd_state->buf) || *buf))
		{
			leak_handle(&fd_list);
			return (NULL);
		}
		buf[read_len] = '\0';
		if (*buf != '\0')
			set_fd_state(fd_state, ft_strjoin(fd_state->buf, buf));
		str = get_fd_line(fd_state, buf);
	}
	return (str);
}
