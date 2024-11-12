/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:51:13 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/12 18:23:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

void	execve_cmd(t_pipex *cmd, int cmd_idx, char *envp[])
{
	t_data	*data_node;

	data_node = cmd->head;
	if (cmd->input_fd == -1)
		cmd_idx--;
	while (data_node)
	{
		if (data_node->cmd_idx == cmd_idx)
		{
			if (execve(data_node->cmd[0], data_node->cmd, envp) == -1)
				terminator(2, cmd, 0, ft_strdup(data_node->cmd[0]));
		}
		data_node = data_node->next;
	}
}

void	pipe_connect_process(t_pipex *cmd, int cmd_idx)
{
	if (cmd_idx == 0)
	{
		dup2(cmd->input_fd, STDIN_FILENO);
		dup2(cmd->pipe_fd[cmd_idx][1], STDOUT_FILENO);
		close_child_first(cmd);
	}
	else if (cmd_idx == cmd->arg_size - 1)
	{
		dup2(cmd->pipe_fd[cmd_idx - 1][0], STDIN_FILENO);
		dup2(cmd->output_fd, STDOUT_FILENO);
		close_child_last(cmd, cmd_idx);
	}
	else
	{
		dup2(cmd->pipe_fd[cmd_idx - 1][0], STDIN_FILENO);
		dup2(cmd->pipe_fd[cmd_idx][1], STDOUT_FILENO);
		close_child_middle(cmd, cmd_idx);
	}
}

void	fork_loop(t_pipex *cmd, int cmd_idx, char *envp[])
{
	while (cmd_idx < cmd->arg_size)
	{
		cmd->pid[cmd_idx] = fork();
		if (cmd->pid[cmd_idx] == -1)
			terminator(1, cmd, errno, "Fork Failed");
		else if (cmd->pid[cmd_idx] == 0)
		{
			pipe_connect_process(cmd, cmd_idx);
			execve_cmd(cmd, cmd_idx, envp);
		}
		cmd_idx++;
	}
}

void	pipe_logic(t_pipex *cmd, char *envp[])
{
	int		cmd_idx;

	alloc_pipe_fd(cmd);
	init_pipe_fd(cmd);
	fork_loop(cmd, 0, envp);
	close_all_fd(cmd, 0);
	cmd_idx = 0;
	while (cmd_idx < cmd->arg_size)
	{
		waitpid(cmd->pid[cmd_idx], NULL, 0);
		cmd_idx++;
	}
}
