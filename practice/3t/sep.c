/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:42:02 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/02 00:32:06 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "microshell.h"

int	count_pipe(char **cmd)
{
	int	cnt = 0;
	int	i = 0;

	while (cmd[i])
	{
		if (!strcmp(cmd[i], "|"))
			cnt++;
		i++;
	}
	return (cnt);
}

int	find_pipe(t_list *list, char **cmd)
{
	int	pipenum = count_pipe(cmd);
	int	idx1 = 0;
	int	idx2 = 0;

	list->pipe_loc = (int *)malloc(sizeof(int) * (pipenum + 1));
	while (cmd[idx1])
	{
		if (!strcmp(cmd[idx1], "|"))
		{
			list->pipe_loc[idx2] = idx1;
			idx2++;
		}
		idx1++;
	}
	list->pipe_loc[idx2] = idx1;
	return (pipenum);
}

char	**sep_by_pipe(char **cmd, int s_idx, int len)
{
	char	**av;
	int		i = 0;

	av = (char **)malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		av[i] = ft_strdup(cmd[s_idx + i]);
		i++;
	}
	av[len] = '\0';
	return (av);
}