/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_set_struct_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:48:36 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/10 22:50:23 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
