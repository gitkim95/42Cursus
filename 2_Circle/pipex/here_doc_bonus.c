/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 03:36:32 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/12 13:06:35 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

void	get_stdin(t_pipex *cmd)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_len;
	int		lim_len;

	lim_len = ft_strlen(cmd->limiter);
	read_len = 1;
	while (read_len)
	{
		read_len = read(STDIN_FILENO, buf, BUFFER_SIZE);
		if (read_len == -1)
			terminator(1, cmd, errno, "STDIN failed");
		buf[read_len] = '\0';
		if (!read_len || !ft_strncmp(buf, cmd->limiter, lim_len))
			terminator(0, cmd, 0, NULL);
		write(cmd->pipe_fd[0][1], buf, read_len);
	}
}

void	hd_pipe_logic(t_pipex *cmd, pid_t *pid)
{
	pid[0] = fork();
	if (pid[0] == -1)
		terminator(1, cmd, errno, "Fork Failed");
	else if (pid[0] == 0)
	{
		dup2(cmd->pipe_fd[0][1], STDOUT_FILENO);
		close_child_first(cmd);
		get_stdin(cmd);
	}
}

void	hd_make_pipe(t_pipex *cmd, char *envp[])
{
	pid_t	*pid;

	alloc_pipe_fd(cmd);
	init_pipe_fd(cmd);
	pid = (pid_t *)malloc(sizeof(pid_t) * 3);
	hd_pipe_logic(cmd, pid);
	fork_loop(cmd, pid, 1, envp);
	close_all_fd(cmd, 0);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	waitpid(pid[2], NULL, 0);
	free(pid);
}

void	handle_heredoc(t_pipex *cmd, int argc, char *argv[], char *envp[])
{
	cmd->arg_size = 3;
	cmd->path = set_path(envp, cmd);
	cmd->head = NULL;
	cmd->tail = NULL;
	cmd->limiter = ft_strdup(argv[2]);
	cmd->input_fd = -1;
	cmd->output_fd = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (cmd->output_fd == -1)
		terminator(1, cmd, errno, argv[argc - 1]);
	set_struct_data(cmd, argc, argv, 3);
	set_cmd(cmd);
	hd_make_pipe(cmd, envp);
}
