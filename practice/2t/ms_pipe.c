/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 02:48:42 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 03:14:41 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "microshell.h"

void	make_pipe(t_list *list)
{
	int	idx;

	list->p_fd = (int **)malloc(sizeof(int *) * list->size - 1);
	idx = 0;
	while (idx < list->size - 1)
	{
		list->p_fd[idx] = (int *)malloc(sizeof(int) * 2);
		pipe(list->p_fd[idx]);
		idx++;
	}
}

void	close_all(t_list *list)
{
	int	idx;

	idx = 0;
	while (idx < list->size - 1)
	{
		close(list->p_fd[idx][0]);
		close(list->p_fd[idx][1]);
		free(list->p_fd[idx]);
		idx++;
	}
	free(list->p_fd);
}

void	set_pipe(t_list *list, int idx)
{
	if (idx != 0)
		dup2(list->p_fd[idx - 1][0], STDIN_FILENO);
	if (idx != list->size - 1)
		dup2(list->p_fd[idx][1], STDOUT_FILENO);
	close_all(list);
}
