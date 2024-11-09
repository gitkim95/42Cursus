/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:17:13 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/10 02:26:06 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	terminator(int flag, t_pipex *data, int errnum, char *msg)
{
	if (data)
	{
		if (data->cmd1)
			free_split(data->cmd1);
		if (data->cmd2)
			free_split(data->cmd2);
		if (data->path)
			free_split(data->path);
	}
	if (errnum)
		perror(msg);
	else
		ft_putendl_fd(msg, 2);
	if (flag == 2)
	{
		free(msg);
		exit (flag);
	}
	else
		exit (flag);
}
