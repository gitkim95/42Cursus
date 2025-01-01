/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:05:08 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/01 21:47:10 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "microshell.h"

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(int fd, char *str)
{
	if (str)
		write(fd, str, ft_strlen(str));
}

void	ft_error(char *str, char *obj)
{
	ft_putstr(STDERR_FILENO, str);
	ft_putstr(STDERR_FILENO, obj);
	ft_putstr(STDERR_FILENO, "\n");
}

char	*ft_strdup(char *str)
{
	char	*new_str;
	int	i;

	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	ft_cd(char **cmd)
{
	int i;
	
	i = 0;
	while (cmd[i])
		i++;
	if (i > 2 || i < 2 || (cmd[1] && !strcmp(cmd[1], "-")))
		ft_error("error: cd: bad arguments", NULL);
	else if (chdir(cmd[1]) == -1)
		ft_putstr("error: cd: cannot change directory to ", cmd[1]);
}

int	count_pipe(char **cmd)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (cmd[i])
	{
		if (!strcmp(cmd[i], "|"))
			cnt++;
		i++;
	}
	return (cnt);
}

int	find_pipe_loc(t_list *list, char **cmd)
{
	int	idx1;
	int	idx2;
	int	pipe_num;

	pipe_num = count_pipe(cmd);
	list->pipe_loc = (int *)malloc(sizeof(int) * (pipe_num + 1));
	idx1 = 0;
	idx2 = 0;
	while (cmd[idx1])
	{
		if (!strcmp(cmd[idx1], "|"))
		{
			list->pipe_loc[idx2] = idx1;
			idx2++;
		}
		idx1++;
	}
	list->pipe_loc[idx2] = idx1;
	return (idx2);
}

void	init_list(t_list *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->pipe_loc = NULL;
	list->size = 0;
}

char	**sep_by_pipe(char **cmd, int loc, int len)
{
	char	**av;
	int		i;

	av = (char **)malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		av[i] = ft_strdup(cmd[loc + i]);
		i++;
	}
	av[len] = NULL;
	return (av);
}

t_node	*make_node(char	**av)
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
	int	idx1;
	int	idx2;
	int	pipe_num;
	t_node	*node;

	init_list(list);
	pipe_num = find_pipe_loc(list, cmd);
	idx1 = 0;
	idx2 = 0;
	while (cmd[idx1])
	{
		node = make_node(sep_by_pipe(cmd, idx1, list->pipe_loc[idx2] - idx1));
		addback(list, node);
		if (idx2 < pipe_num)
			idx1 = list->pipe_loc[idx2] + 1;
		else
			idx1 = list->pipe_loc[idx2];
		idx2++;
	}
}

void	ft_exec(char **cmd, char **envp)
{
	t_list	list;
	t_node	*node;
	pid_t	pid[BUFFER_SIZE];
	int		fd[2];

	make_list(&list, cmd);
	node = list.head;
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	c_i;

	if (ac < 2)
		return (0);
	i = 1;
	while (av[i])
	{
		if (!strcmp(av[i], ";"))
		{
			av[i] = NULL;
			i++;
		}
		else if (*av[i])
		{
			c_i = i;
			while (av[i] && strcmp(av[i], ";"))
				i++;
			while (av[i] && !strcmp(av[i], ";"))
			{
				av[i] = NULL;
				i++;
			}
			if (!strcmp(av[c_i], "cd"))
				ft_cd(av + c_i);
			else
				ft_exec(av + c_i, envp);
		}
		else
			i++;
	}

}