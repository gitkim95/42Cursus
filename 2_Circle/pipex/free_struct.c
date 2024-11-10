/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:17:13 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/10 21:05:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"

void	free_split(char **c_split, int **i_split)
{
	int	i;

	i = 0;
	if (c_split)
	{
		while (c_split[i])
		{
			free(c_split[i]);
			i++;
		}
		free(c_split);
	}
	i = 0;
	if (i_split)
	{
		while (i_split[i])
		{
			free(i_split[i]);
			i++;
		}
		free(i_split);
	}
}

void	free_lst(t_pipex *cmd)
{
	t_data	*node;
	t_data	*tmp;

	node = cmd->head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free_split(tmp->cmd, NULL);
		free(tmp);
	}
}

void	free_pipex_struct(t_pipex *cmd)
{
	if (cmd->path)
		free_split(cmd->path, NULL);
	if (cmd->head)
		free_lst(cmd);
	if (cmd->input_fd > 0)
		close(cmd->input_fd);
	if (cmd->output_fd > 0)
		close(cmd->output_fd);
	if (cmd->pipe_fd)
		free_split(NULL, cmd->pipe_fd);
}

void	terminator(int flag, t_pipex *cmd, int errnum, char *msg)
{
	if (cmd)
		free_pipex_struct(cmd);
	if (flag)
	{
		if (errnum)
			perror(msg);
		else
			ft_putendl_fd(msg, 2);
		if (flag == 1)
			exit (flag);
		else if (flag == 2)
		{
			free(msg);// 안나오면 strdup로 보낸다.
			exit (flag);
		}
	}
	else
		exit (flag);
}
