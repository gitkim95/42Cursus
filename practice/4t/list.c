/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:11:45 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/02 13:27:50 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "microshell.h"

void	init_list(t_list *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->pipe_idx = NULL;
	list->size = 0;
}

t_node	*make_node(char **av)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->cmd = av;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	addback(t_list *list, t_node *node)
{
	if (!list->head)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
	list->size++;
}

void	make_list(t_list *list, char **cmd)
{
	t_node	*node;
	int		idx1 = 0;
	int		idx2 = 0;
	int		pipenum = find_pipe(list, cmd);

	while (cmd[idx1])
	{
		node = make_node(sep_by_pipe(cmd, idx1, list->pipe_idx[idx2] - idx1));
		addback(list, node);
		if (idx2 < pipenum)
			idx1 = list->pipe_idx[idx2] + 1;
		else
			idx1 = list->pipe_idx[idx2];
		idx2++;
	}
	free(list->pipe_idx);
}