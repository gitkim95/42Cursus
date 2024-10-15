/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:18:52 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/16 05:27:42 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_null(char **ff)
{
	if(ff && *ff)
	{
		free(*ff);
		*ff = NULL;
	}
}

static char	*cut_lf(char **save_line)
{
	size_t	i;
	char	*read_line;
	char	*tmp;

	i = 0;
	while ((*save_line)[i] != '\n' && (*save_line)[i] != '\0')
		i++;
	tmp = *save_line;
	read_line = ft_substr(tmp, 0, i + 1);
	if (!read_line)
	{
		free(tmp);
		return (NULL);
	}
	if ((*save_line)[i] == '\0')
		*save_line = ft_strdup("");
	else
		*save_line = ft_strdup(tmp + i + 1);
	free(tmp);
	return (read_line);
}

static int	read_file(int fd, char **buf, char **save_line)
{
	int		n;
	char	*tmp;

	n = 1;
	while (!ft_strchr(*save_line, '\n') && n)
	{
		n = read(fd, *buf, BUFFER_SIZE);
		if (n == -1)
			return (n);
		(*buf)[n] = '\0';
		tmp = *save_line;
		*save_line = ft_strjoin(tmp, *buf);
		free(tmp);
		if (!*save_line)
			return (-1);
	}
	return (n);
}

static char	*take_a_line(int fd, char **buf, char **save_line)
{
	int		n;

	n = read_file(fd, buf, save_line);
	if (n == -1 || !(*save_line))
	{
		free_null(buf);
		return (NULL);
	}
	if (n == 0 && **save_line)
		return (cut_lf(save_line));
	else
		return (*save_line);
}

char	*get_next_line(int fd)
{
	static char		*save_line[1048577];
	char			*buf;
	char			*read_line;

	if (fd > 1048576 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!save_line[fd])
		save_line[fd] = ft_strdup("");
	read_line = take_a_line(fd, &buf, &save_line[fd]);
	free(buf);
	if (!*read_line || !read_line)
	{
		free_null(&save_line[fd]);
		return (NULL);
	}
	return (read_line);
}

#include <stdio.h>
#include <fcntl.h>

int main () {
	int fd_1;
	int fd_2;
	char *ln;


	fd_1 = open("bb", O_RDONLY);
	fd_2 = open("cc", O_RDONLY);
	ln = get_next_line(fd_1);
	printf("1: %s", ln);
	free(ln);
	ln = get_next_line(fd_2);
	printf("2: %s", ln);
	free(ln);
	ln = get_next_line(fd_1);
	printf("3: %s", ln);
	free(ln);
	ln = get_next_line(fd_2);
	printf("4: %s", ln);
	free(ln);
	ln = get_next_line(fd_1);
	printf("5: %s", ln);
	free(ln);
	ln = get_next_line(fd_2);
	printf("6: %s", ln);
	free(ln);
	ln = get_next_line(fd_1);
	printf("7: %s", ln);
	free(ln);
	ln = get_next_line(fd_2);
	printf("8: %s", ln);
	free(ln);
}