/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:18:52 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/13 22:12:03 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*read_line;
	char	buf[BUFFER_SIZE];
	int		line_size;
	int		n;

	n = 1;
	line_size = 0;
	while (n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (NULL);
		line_size += n;
	}

	return (read_line);
}