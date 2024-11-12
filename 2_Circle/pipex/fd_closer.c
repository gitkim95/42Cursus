/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_closer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 03:39:44 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/12 16:56:07 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void	close_all_fd(t_pipex *cmd, int cmd_idx)
{
	while (cmd_idx < cmd->arg_size - 1)
	{
		close(cmd->pipe_fd[cmd_idx][0]);
		close(cmd->pipe_fd[cmd_idx][1]);
		cmd_idx++;
	}
	if (cmd->input_fd != -1)
		close(cmd->input_fd);
	close(cmd->output_fd);
}

void	close_child_last(t_pipex *cmd, int cmd_idx)
{
	int	i;

	close(cmd->pipe_fd[cmd_idx - 1][1]);
	if (cmd->input_fd != -1)
		close(cmd->input_fd);
	i = 0;
	while (i < cmd->arg_size - 1)
	{
		if (i != cmd_idx && i != cmd_idx - 1)
		{
			close(cmd->pipe_fd[i][0]);
			close(cmd->pipe_fd[i][1]);
		}
		i++;
	}
}

void	close_child_middle(t_pipex *cmd, int cmd_idx)
{
	int	i;

	close(cmd->pipe_fd[cmd_idx - 1][1]);
	close(cmd->pipe_fd[cmd_idx][0]);
	if (cmd->input_fd != -1)
		close(cmd->input_fd);
	close(cmd->output_fd);
	i = 0;
	while (i < cmd->arg_size - 1)
	{
		if (i != cmd_idx && i != cmd_idx - 1)
		{
			close(cmd->pipe_fd[i][0]);
			close(cmd->pipe_fd[i][1]);
		}
		i++;
	}
}

void	close_child_first(t_pipex *cmd)
{
	int	i;

	close(cmd->pipe_fd[0][0]);
	close(cmd->output_fd);
	i = 1;
	while (i < cmd->arg_size - 1)
	{
		close(cmd->pipe_fd[i][0]);
		close(cmd->pipe_fd[i][1]);
		i++;
	}
}
