/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:17:13 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/11 05:23:28 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	free_split(char **c_split, int **i_split, int i_size)
{
	int	i;

	i = 0;
	if (c_split)
	{
		while (c_split[i])
		{
			free(c_split[i]);
			i++;
		}
		free(c_split);
	}
	i = 0;
	if (i_split)
	{
		while (i < i_size - 1)
		{
			free(i_split[i]);
			i++;
		}
		free(i_split);
	}
}

void	free_lst(t_pipex *cmd)
{
	t_data	*node;
	t_data	*tmp;

	node = cmd->head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free_split(tmp->cmd, NULL, 0);
		free(tmp);
	}
}

void	free_pipex_struct(t_pipex *cmd)
{
	if (cmd->path)
		free_split(cmd->path, NULL, 0);
	if (cmd->head)
		free_lst(cmd);
	if (cmd->input_fd > 0)
		close(cmd->input_fd);
	if (cmd->output_fd > 0)
		close(cmd->output_fd);
	if (cmd->pipe_fd)
		free_split(NULL, cmd->pipe_fd, cmd->arg_size);
	if (cmd->limiter)
		free(cmd->limiter);
}

void	terminator(int flag, t_pipex *cmd, int errnum, char *msg)
{
	if (cmd)
		free_pipex_struct(cmd);
	if (flag)
	{
		if (errnum)
			perror(msg);
		else
			ft_putendl_fd(msg, 2);
		if (flag == 1)
			exit (flag);
		else if (flag == 2)
		{
			free(msg);
			exit (flag);
		}
	}
	else
		exit (flag);
}
