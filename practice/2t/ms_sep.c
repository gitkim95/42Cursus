/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_sep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 02:07:54 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 03:39:02 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "microshell.h"

int	count_pipe(char **cmd)
{
	int	idx;
	int	cnt;

	cnt = 0;
	idx = 0;
	while (cmd[idx])
	{
		if (!strcmp(cmd[idx], "|"))
			cnt++;
		idx++;
	}
	return (cnt);
}

int	recode_pipe_idx(t_list *list, char **cmd)
{
	int	cnt_pipe;
	int	idx1;
	int	idx2;

	cnt_pipe = count_pipe(cmd);
	list->p_idx = (int *)malloc(sizeof(int) * (cnt_pipe + 1));
	idx1 = 0;
	idx2 = 0;
	while (cmd[idx1])
	{
		if (!strcmp(cmd[idx1], "|"))
		{
			list->p_idx[idx2] = idx1;
			idx2++;
		}
		idx1++;
	}
	list->p_idx[idx2] = idx1;
	return (idx2);
}

char	**sep_by_pipe(char **cmd, int cur_idx, int cmd_len)
{
	char	**sep_cmd;
	int		idx;

	sep_cmd = (char **)malloc(sizeof(char *) * (cmd_len + 1));
	idx = 0;
	while (idx < cmd_len)
	{
		sep_cmd[idx] = ft_strdup(cmd[cur_idx + idx]);
		idx++;
	}
	sep_cmd[idx] = NULL;
	return (sep_cmd);
}
