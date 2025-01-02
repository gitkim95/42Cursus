/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:09:05 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/02 13:35:57 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "microshell.h"

void	ft_cd(char **cmd)
{
	int	i = 0;
	while (cmd[i])
		i++;
	if (i > 2 || i < 2 || (cmd[1] && !strcmp(cmd[1], "-")))
		ft_error("msg", NULL);
	else if (chdir(cmd[1]) == -1)
		ft_error("msg", cmd[1]);
}

void	child(t_node *node, char **envp, t_list *list)
{
	if (node->prev)
	{
		dup2(node->prev->pipe_fd[0], STDIN_FILENO);
		close(node->prev->pipe_fd[0]);
		close(node->prev->pipe_fd[1]);
	}
	if (node->next)
	{
		dup2(node->pipe_fd[1], STDOUT_FILENO);
		close(node->pipe_fd[0]);
		close(node->pipe_fd[1]);
	}
	if (execve(node->cmd[0], node->cmd, envp) == -1)
	{
		ft_error("msg", node->cmd[0]);
		free_list(list);
		exit(1);
	}
}

void	parents(pid_t	*pid, t_list *list)
{
	int	i = 0;

	while (i < list->size)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	free_list(list);
}

void	ft_exec(char **cmd, char **envp)
{
	t_list	list;
	t_node	*node;
	pid_t	pid[BUFFER_SIZE];
	int		i = 0;

	init_list(&list);
	make_list(&list, cmd);
	node = list.head;
	while (i < list.size)
	{
		if (node->next)
			pipe(node->pipe_fd);
		pid[i] = fork();
		if (pid[i] == 0)
			child(node, envp, &list);
		if (node->prev)
		{
			close(node->prev->pipe_fd[0]);
			close(node->prev->pipe_fd[1]);
		}
		node = node->next;
		i++;
	}
	parents(pid, &list);
}