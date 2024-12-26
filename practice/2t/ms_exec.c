/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 01:53:05 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 03:12:10 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "microshell.h"

void	ft_cd(char **cmd)
{
	int	i;

	while (cmd[i])
		i++;
	if (i > 2)
	{
		ft_error("error: cd: bad arguments", NULL);
		return ;
	}
	if (chdir(cmd[1]) == -1)
	{
		ft_error("error: cd: cannot change directory to ", cmd[1]);
		return ;
	}
}

void	child(t_node *cmd, int idx, char **envp, t_list *list)
{
	set_pipe(list, idx);
	if (execve(cmd->cmd[0], cmd->cmd, envp) == -1)
	{
		ft_error("error: cannot execute ", cmd->cmd[0]);
		free_all(list);
		exit(1);
	}
}

void	parent(t_list *list, pid_t *pid)
{
	int	idx;

	close_all(list);
	idx = 0;
	while (idx < list->size)
	{
		waitpid(pid[idx], NULL, 0);
		idx++;
	}
	free_all(list);
}

void	ft_exec(char **cmd, char **envp)
{
	t_list	list;
	t_node	*node;
	pid_t	pid[BUFFER_SIZE];
	int		idx;

	make_list(&list, cmd);
	make_pipe(&list);
	idx = 0;
	node = list.head;
	while (idx < list.size)
	{
		pid[idx] = fork();
		if (pid[idx] == 0)
			child(node, idx, envp, &list);
		idx++;
		node = node->next;
	}
	parent(&list, pid);
}
