/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:17:13 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/13 17:49:20 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	free_split(char **c_split, int **i_split, int i_size)
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
		while (i < i_size - 1)
		{
			free(i_split[i]);
			i++;
		}
		free(i_split);
	}
}

void	free_lst(t_fdf *fdf)
{
	t_map_list	*node;
	t_map_list	*tmp;

	node = fdf->head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free_split(tmp->fdf, NULL, 0);
		free(tmp);
	}
}

void	free_fdf_struct(t_fdf *fdf)
{
	if (fdf->path)
		free_split(fdf->path, NULL, 0);
	if (fdf->head)
		free_lst(fdf);
	if (fdf->input_fd > 0)
		close(fdf->input_fd);
	if (fdf->output_fd > 0)
		close(fdf->output_fd);
	if (fdf->pipe_fd)
		free_split(NULL, fdf->pipe_fd, fdf->arg_size);
	if (fdf->limiter)
		free(fdf->limiter);
	if (fdf->pid)
		free(fdf->pid);
}

void	terminator(int flag, t_fdf *fdf, int errnum, char *msg)
{
	if (fdf)
		free_fdf_struct(fdf);
	if (flag == 1 || flag == 2)
	{
		if (errnum)
			perror(msg);
		else
			ft_putendl_fd(msg, 2);
		if (flag == 1)
			exit (flag);
		else if (flag == 2)
		{
			free(msg);
			exit (flag);
		}
	}
	else if (flag == 0)
		exit (flag);
	else if (flag == 3)
		return ;
}
