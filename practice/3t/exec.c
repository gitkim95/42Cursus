/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:32:26 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/02 00:39:08 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "microshell.h"

void	ft_cd(char **cmd)
{
	int	i = 0;
	while (cmd[i])
		i++;
	if (i > 2 || i < 2 || (cmd[1] && !strcmp(cmd[1], "-")))
		ft_error("error: cd: bad arguments", NULL);
	if (chdir(cmd[1]) == -1)
		ft_error("error: cd: cannot change directory", cmd[1]);
}

void	child(t_node *node, t_list *list, char **envp)
{
	if (node->prev)
	{
		dup2(node->prev->pipefd[0], STDIN_FILENO);
		close(node->prev->pipefd[0]);
		close(node->prev->pipefd[1]);
	}
	if (node->next)
	{
		dup2(node->pipefd[1], STDOUT_FILENO);
		close(node->pipefd[1]);
		close(node->pipefd[0]);
	}
	if (execve(node->cmd[0], node->cmd, envp) == -1)
	{
		ft_error("error: cannot execute ", node->cmd[0]);
		free_list(list);
		exit(1);
	}
}

void	parents(pid_t *pid, t_list *list)
{
	int	idx = 0;

	while (idx < list->size)
	{
		waitpid(pid[idx], NULL, 0);
		idx++;
	}
	free_list(list);
}
void	ft_exec(char **cmd, char **envp)
{
	t_list	list;
	t_node	*node;
	pid_t	pid[BUFFER_SIZE];
	int		idx = 0;

	init_list(&list);
	make_list(&list, cmd);
	node = list.head;
	while (idx < list.size)
	{
		if (node->next)
			pipe(node->pipefd);
		pid[idx] = fork();
		if (pid[idx] == 0)
			child(node, &list, envp);
		if (node->prev)
		{
			close(node->prev->pipefd[0]);
			close(node->prev->pipefd[1]);
		}
		node = node->next;
		idx++;
	}
	parents(pid, &list);
}
