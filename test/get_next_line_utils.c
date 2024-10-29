/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:17:16 by hwilkim           #+#    #+#             */
/*   Updated: 2024/10/29 02:33:47 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	idx;
	char			*sub;

	idx = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (idx < len && s[idx + start])
	{
		sub[idx] = s[idx + start];
		++idx;
	}
	sub[idx] = '\0';
	return (sub);
}

char	*ft_strcat(char *dest, char const *src)
{
	int	dest_idx;
	int	src_idx;

	dest_idx = 0;
	src_idx = 0;
	while (dest[dest_idx] != '\0')
	{
		++dest_idx;
	}
	while (src[src_idx] != '\0')
	{
		dest[dest_idx++] = src[src_idx++];
	}
	dest[dest_idx] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strcat(join, s1);
	ft_strcat(join + s1_len, s2);
	return (join);
}

void	leak_handle(t_gnl_list *fd_list)
{
	t_gnl_node *head;
	t_gnl_node *temp;

	head = fd_list->head;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->buf);
		free(temp);
	}
	fd_list->head = NULL;
}
