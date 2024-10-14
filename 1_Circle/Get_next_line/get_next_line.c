/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:18:52 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/15 02:36:52 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*read_line;
	char			buf[BUFFER_SIZE + 1];
	int				read_len;
	static size_t	start_idx;

	read_len = 1;
	read_line = NULL;
	if (start_idx)
		take_next_line(fd, start_idx);
	while (read_len > 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len <= 0)
			return (NULL);
		buf[read_len] = 0;
		if (!(ft_strchr(buf, 10)))
			read_line = ft_strnjoin(read_line, buf, read_len);
		else
		{
			read_len = buf - ft_strchr(buf, 10) + 1;
			read_line = ft_strnjoin(read_line, buf, read_len);
			break ;
		}
	}
	start_idx += ft_strlen(read_line);
	return (read_line);
}

#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd;

	fd = open("aa", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
