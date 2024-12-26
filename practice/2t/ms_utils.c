/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 01:48:20 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 03:09:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "microshell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(int fd, char *str)
{
	if (str)
		write(fd, str, ft_strlen(str));
}

void	ft_error(char *msg, char *obj)
{
	ft_putstr(2, msg);
	ft_putstr(2, obj);
	ft_putstr(2, "\n");
	// kill(0, SIGINT);
}

void 	ft_strcat(char *dst, char *src)
{
	int	i;
	int	j;

	j = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
}

char	*ft_strdup(char *str)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	new_str[0] = '\0';
	ft_strcat(new_str, str);
	return (new_str);
}

void	free_all(t_list *list)
{
	t_node	*node;
	t_node	*temp;
	int		idx;

	node = list->head;
	while (node)
	{
		idx = 0;
		while (node->cmd[idx])
		{
			free(node->cmd[idx]);
			idx++;
		}
		free(node->cmd);
		temp = node->next;
		free(node);
		node = temp;
	}
}