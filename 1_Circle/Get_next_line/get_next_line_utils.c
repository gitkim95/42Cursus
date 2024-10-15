/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:21:50 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/13 20:58:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

void	take_next_line(int fd, size_t start_idx)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (start_idx + 1));
	if (!buf)
		return ;
	if (fd)
		(void)fd;
	free(buf);
}

static char	*ft_strcat(char *dst, char const *src, size_t *offset)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[*offset] = src[i];
		(*offset)++;
		i++;
	}
	dst[*offset] = '\0';
	return (dst);
}

char	*ft_strnjoin(char *s1, char const *s2, size_t n)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (n > s2_len)
		n = s2_len;
	if (!s1 && !s2)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (s1_len + n + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	if (s1)
	{
		new_str = ft_strcat(new_str, s1, &i);
		free(s1);
	}
	if (s2)
		new_str = ft_strcat(new_str, s2, &i);
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}
