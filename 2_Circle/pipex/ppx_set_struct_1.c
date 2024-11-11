/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_set_struct_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:44:49 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/12 01:33:59 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

t_data	*make_new_data_node(char **cmd, int idx)
{
	t_data	*new_data;

	new_data = (t_data *)malloc(sizeof(t_data));
	if (!new_data)
		return (NULL);
	new_data->cmd = cmd;
	new_data->cmd_idx = idx;
	new_data->next = NULL;
	return (new_data);
}

void	set_struct_data(t_pipex *cmd, int argc, char *argv[], int idx)
{
	t_data	*data_node;
	char	**cmd_split;
	int		i;

	i = 0;
	while (i < cmd->arg_size && idx + 1 < argc - 1)
	{
		cmd_split = ft_split(argv[idx + i], ' ');
		if (!cmd_split)
			terminator(1, cmd, errno, "allocate error");
		data_node = make_new_data_node(cmd_split, i);
		if (!data_node)
			terminator(1, cmd, errno, "allocate error");
		data_lst_addback(cmd, data_node);
		i++;
	}
}

char	*find_path(char *envp[], t_pipex *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
		{
			path = ft_strdup(envp[i] + 5);
			if (!path)
				terminator(1, cmd, errno, "allocate error");
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	**set_path(char *envp[], t_pipex *cmd)
{
	char	*path_arr;
	char	**path_split;

	path_arr = find_path(envp, cmd);
	if (!path_arr)
		terminator(1, cmd, errno, "PATH not found");
	path_split = ft_split(path_arr, ':');
	free(path_arr);
	if (!path_split)
		terminator(1, cmd, errno, "allocate error");
	return (path_split);
}

void	set_struct_pipex(t_pipex *cmd, int argc, char *argv[], char *envp[])
{
	cmd->arg_size = argc - 3;
	cmd->path = set_path(envp, cmd);
	cmd->head = NULL;
	cmd->tail = NULL;
	cmd->limiter = NULL;
	cmd->output_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->output_fd == -1)
		terminator(1, cmd, errno, argv[argc - 1]);
	cmd->input_fd = open(argv[1], O_RDONLY);
	if (cmd->input_fd == -1)
	{
		perror(argv[1]);
		cmd->input_fd = open("/dev/null", O_RDONLY);
		if (cmd->input_fd == -1)
			terminator(1, cmd, errno, "Error opening NULL");
	}
	set_struct_data(cmd, argc, argv, 2);
	set_cmd(cmd);
}
