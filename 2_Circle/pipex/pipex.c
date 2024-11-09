/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:37:57 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/09 22:48:01 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"

char	*find_path(char *envp[])
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
			{
					//error
			}
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	**set_path(char *envp[])
{
	char	*path_arr;
	char	**path_split;

	path_arr = find_path(envp);
	if (!path_arr)
	{
		//error
	}
	path_split = ft_split(path_arr, ':');
	if (!path_split)
	{
		//error
	}
	return (path_split);
}

char	*check_cmd(t_pipex *data, char *cmd)
{
	int		i;
	char	*temp;
	char	*new_cmd;

	if (access(cmd, X_OK) == 0);
		return (cmd);
	temp = ft_strjoin("/", cmd);
	if (!temp)
	{
			//error
	}
	i = 0;
	while (data->path[i])
	{
		new_cmd = ft_strjoin(data->path[i], temp);
		if (!new_cmd)
		{
			//error
		}
		if (access(new_cmd, X_OK) == 0);
		{
			free(temp);
			return (new_cmd);
		}
		free(new_cmd);
		i++;
	}
	free(temp);
	return (NULL);
}

char	*set_cmd(t_pipex *data, char *cmd)
{
	char	*temp_cmd;

	temp_cmd = cmd;
	cmd = check_cmd(data, cmd);
	if (cmd != temp_cmd)
	{
		free(temp_cmd);
		if (!cmd)
		{
			//error
		}	
	}
	return (cmd);
}

void	set_data(t_pipex *data, int argc, char *argv[], char *envp[])
{
	char	*temp_cmd;
	
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	data->path = set_path(envp);
	data->cmd_idx = argc - 3;
	data->cmd1[0] = set_cmd(data, data->cmd1[0]);
	data->cmd2[0] = set_cmd(data, data->cmd2[0]);
}

int main (int argc, char *argv[], char *envp[])
{
	t_pipex	data;

	if (argc != 5)
	{
		//error
	}
	set_data(&data, argc, argv, envp);
}