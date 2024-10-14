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
	char		*read_line;
	char		buf[BUFFER_SIZE];
	size_t		read_len;
	static int	start_idx;

	read_len = 1;
	read_line = NULL;
	while (read_len > 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len == -1)
			return (NULL);
		if (!ft_strchr(buf, '\n'))
		{
			read_line = ft_strnjoin(read_line, buf, read_len);
		}
		else
		{
			read_len = buf - ft_strchr(buf, '\n') + 1;
			read_line = ft_strnjoin(read_line, buf, read_len);
		}
	}

	return (read_line);
}
