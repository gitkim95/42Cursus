/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:13:32 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/02 13:22:54 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "microshell.h"

int	count_pipe(char **cmd)
{
	int	i = 0;
	int	cnt = 0;

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
	int	idx1 = 0;
	int	idx2 = 0;
	int	pipenum = count_pipe(cmd);

	list->pipe_idx = (int *)malloc(sizeof(int) * (pipenum + 1));
	while (cmd[idx1])
	{
		if (!strcmp(cmd[idx1], "|"))
		{
			list->pipe_idx[idx2] = idx1;
			idx2++;
		}
		idx1++;
	}
	list->pipe_idx[idx2] = idx1;
	return (pipenum);
}

char	**sep_by_pipe(char **cmd, int cur_idx, int len)
{
	char	**sep_cmd;
	int		i = 0;

	sep_cmd = (char **)malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		sep_cmd[i] = ft_strdup(cmd[cur_idx + i]);
		i++;
	}
	sep_cmd[i] = NULL;
	return (sep_cmd);
}