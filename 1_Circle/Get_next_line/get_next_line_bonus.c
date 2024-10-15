/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:35:09 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/15 14:35:11 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_null(char **ff)
{
	free(*ff);
	*ff = NULL;
}

static char	*cut_lf(char **save_line)
{
	int		i;
	char	*read_line;
	char	*tmp;

	i = 0;
	while ((*save_line)[i] != '\n')
		i++;
	tmp = *save_line;
	read_line = ft_substr(tmp, 0, i + 1);
	*save_line = ft_strdup(tmp + i + 1);
	free(tmp);
	return (read_line);
}

static int	read_file(int fd, char **buf, char **save_line)
{
	int		n;
	char	*saved_text;

	n = 1;
	while (!ft_strchr(*save_line, '\n') && n)
	{
		n = read(fd, *buf, BUFFER_SIZE);
		if (n == -1)
			return (n);
		(*buf)[n] = '\0';
		saved_text = *save_line;
		*save_line = ft_strjoin(saved_text, *buf);
		free(saved_text);
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
	if (ft_strchr(*save_line, '\n'))
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
		save_line[fd] = ft_strdup(""); // free;
	read_line = take_a_line(fd, &buf, &save_line[fd]);
	free(buf);
	return (read_line);
}

#include <stdio.h>
#include <fcntl.h>

int main () {
	int fd;
	char *ln;

	fd = open("bb", O_RDONLY);
	ln = get_next_line(fd);
	printf("1: %s", ln);
	free(ln);
	ln = get_next_line(fd);
	printf("2: %s", ln);
	free(ln);
	ln = get_next_line(fd);
	printf("3: %s", ln);
	free(ln);
	ln = get_next_line(fd);
	printf("4: %s", ln);
	free(ln);
	ln = get_next_line(fd);
	printf("5: %s", ln);
	free(ln);
}