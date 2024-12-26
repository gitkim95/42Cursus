/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 02:26:49 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 03:42:33 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "microshell.h"

void	add_back(t_list *list, t_node *node)
{
	if (!list->head)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	list->size++;
}

t_node	*make_node(char **cmd)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->cmd = cmd;
	node->next = NULL;
	return (node);
}

void	init_list(t_list *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->p_fd = NULL;
	list->p_idx = NULL;
}

void	make_list(t_list *list, char **cmd)
{
	t_node	*node;
	int		idx1;
	int		idx2;	
	int		cmd_num;

	init_list(list);
	cmd_num = recode_pipe_idx(list, cmd);
	idx1 = 0;
	idx2 = 0;
	while (cmd[idx1])
	{
		node = make_node(sep_by_pipe(cmd, idx1, list->p_idx[idx2] - idx1));
		add_back(list, node);
		if (idx2 < cmd_num)
			idx1 = list->p_idx[idx2] + 1;
		else
			idx1 = list->p_idx[idx2];
		idx2++;
	}
	free(list->p_idx);
}

