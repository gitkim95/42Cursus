/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:37:57 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/10 21:09:07 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"

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
	if (!path_split)
		terminator(1, cmd, errno, "allocate error");
	return (path_split);
}

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

void	data_lst_addback(t_pipex *cmd, t_data *new_node)
{
	if (!new_node)
		return ;
	if (cmd->head == NULL)
	{
		cmd->head = new_node;
		cmd->tail = new_node;
	}
	else
	{
		cmd->tail->next = new_node;
		cmd->tail = new_node;
	}
}

void	set_struct_data(t_pipex *cmd, char *argv[])
{
	t_data	*data_node;
	int		idx;
	char	**cmd_split;

	idx = 0;
	while (idx < cmd->arg_size)
	{
		cmd_split = ft_split(argv[idx + 2], ' ');
		if (!cmd_split)
			terminator(1, cmd, errno, "allocate error");
		data_node = make_new_data_node(cmd_split, idx);
		if (!data_node)
			terminator(1, cmd, errno, "allocate error");
		data_lst_addback(cmd, data_node);
		idx++;
	}
}

char	*check_cmd(t_pipex *data, char *cmd)
{
	int		i;
	char	*temp;
	char	*new_cmd;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	temp = ft_strjoin("/", cmd);
	if (!temp)
		terminator(1, data, errno, "allocate error");
	i = 0;
	while (data->path[i])
	{
		new_cmd = ft_strjoin(data->path[i], temp);
		if (!new_cmd)
			terminator(1, data, errno, "allocate error");
		if (access(new_cmd, X_OK) == 0)
		{
			free(temp);
			return (new_cmd);
		}
		free(new_cmd);
		i++;
	}
	free(temp);
	return (cmd);
}

void	set_cmd(t_pipex *cmd)
{
	t_data	*node;
	char	*temp_cmd;

	node = cmd->head;
	while (node)
	{
		temp_cmd = node->cmd[0];
		node->cmd[0] = check_cmd(cmd, node->cmd[0]);
		if (node->cmd[0] != temp_cmd)
			free(temp_cmd);
		node = node->next;
	}
}

void	alloc_pipe_fd(t_pipex *cmd)
{
	int	idx;

	cmd->pipe_fd = (int **)malloc(sizeof(int *) * cmd->arg_size);
	if (!cmd->pipe_fd)
		terminator(1, cmd, errno, "allocate error");
	idx = 0;
	while (idx < cmd->arg_size)
	{
		cmd->pipe_fd[idx] = (int *)malloc(sizeof(int) * 2);
		if (!cmd->pipe_fd[idx])
			terminator(1, cmd, errno, "allocate error");
		idx++;
	}
}

void	set_struct_pipex(t_pipex *cmd, int argc, char *argv[], char *envp[])
{
	cmd->arg_size = argc - 3;
	cmd->path = set_path(envp, cmd);
	cmd->head = NULL;
	cmd->tail = NULL;
	cmd->input_fd = open(argv[1], O_RDONLY);
	if (cmd->input_fd == -1)
		terminator(1, cmd, errno, argv[1]);
	cmd->output_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->output_fd == -1)
		terminator(1, cmd, errno, argv[argc - 1]);
	set_struct_data(cmd, argv);
	set_cmd(cmd);
}

void	fork_process(t_pipex *cmd, int cmd_idx)
{
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
	close(cmd->pipe_fd[cmd_idx][0]);
	close(cmd->pipe_fd[cmd_idx][1]);
    // if (cmd_idx != cmd->arg_size - 1)
    // {
    //     close(cmd->pipe_fd[cmd_idx + 1][0]);
    //     close(cmd->pipe_fd[cmd_idx + 1][1]);
    // }
}

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

void	init_pipe_fd(t_pipex *cmd)
{
	int	idx;

	idx = 0;
	while (idx < cmd->arg_size)
	{
		if (pipe(cmd->pipe_fd[idx]) == -1)
			terminator(1, cmd, errno, "Pipe failed");
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
	cmd_idx = 0;
	while (cmd_idx < cmd->arg_size)
	{	
		waitpid(pid[cmd_idx], NULL, 0);
		cmd_idx++;
	}
}

int main (int argc, char *argv[], char *envp[])
{
	t_pipex	cmd;

	if (argc < 5)
		terminator(1, NULL, 0, "Not enough argument");
	set_struct_pipex(&cmd, argc, argv, envp);
	pipe_logic(&cmd, envp);
	terminator(0, &cmd, 0, NULL);
}