/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:51:13 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/11 02:21:28 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_cmd(t_pipex *cmd, char *envp[], int cmd_idx)
{
	t_data	*data_node;

	data_node = cmd->head;
	while (data_node)
	{
		if (data_node->cmd_idx == cmd_idx)
		{
			if (execve(data_node->cmd[0], data_node->cmd, envp) == -1)
				terminator(1, cmd, errno, "Execve failed");
		}
		data_node = data_node->next;
	}
}

void	fork_process(t_pipex *cmd, int cmd_idx)
{
	// int	idx;

	if (cmd_idx == 0)
	{
		dup2(cmd->input_fd, STDIN_FILENO);
		dup2(cmd->pipe_fd[cmd_idx][1], STDOUT_FILENO);
	}
	else if (cmd_idx < cmd->arg_size - 1)
	{
		dup2(cmd->pipe_fd[cmd_idx - 1][0], STDIN_FILENO);
		dup2(cmd->pipe_fd[cmd_idx][1], STDOUT_FILENO);
	}
	else
	{
		dup2(cmd->pipe_fd[cmd_idx - 1][0], STDIN_FILENO);
		dup2(cmd->output_fd, STDOUT_FILENO);
	}
	for (int i = 0; i < cmd->arg_size - 1; i++)
	{
		if (i != cmd_idx)
		{
			close(cmd->pipe_fd[i][0]);
			close(cmd->pipe_fd[i][1]);
		}
	}
}

void	init_pipe_fd(t_pipex *cmd)
{
	int	idx;

	idx = 0;
	while (idx < cmd->arg_size - 1)
	{
		if (pipe(cmd->pipe_fd[idx]) == -1)
			terminator(1, cmd, errno, "Pipe failed");
		idx++;
	}
}

void	alloc_pipe_fd(t_pipex *cmd)
{
	int	idx;

	cmd->pipe_fd = (int **)malloc(sizeof(int *) * (cmd->arg_size - 1));
	if (!cmd->pipe_fd)
		terminator(1, cmd, errno, "allocate error");
	idx = 0;
	while (idx < cmd->arg_size - 1)
	{
		cmd->pipe_fd[idx] = (int *)malloc(sizeof(int) * 2);
		if (!cmd->pipe_fd[idx])
			terminator(1, cmd, errno, "allocate error");
		idx++;
	}
}

void	pipe_logic(t_pipex *cmd, char *envp[])
{
	pid_t	*pid;
	int		cmd_idx;

	pid = (pid_t *)malloc(sizeof(pid_t) * cmd->arg_size);
	alloc_pipe_fd(cmd);
	init_pipe_fd(cmd);
	cmd_idx = 0;
	while (cmd_idx < cmd->arg_size)
	{
		pid[cmd_idx] = fork();
		if (pid[cmd_idx] == 0)
		{
			fork_process(cmd, cmd_idx);
			execve_cmd(cmd, envp, cmd_idx);
		}
		cmd_idx++;
	}
	close_pipes(cmd, 0);
	cmd_idx = 0;
	while (cmd_idx < cmd->arg_size)
	{
		waitpid(pid[cmd_idx], NULL, 0);
		cmd_idx++;
	}
	free(pid);
}
