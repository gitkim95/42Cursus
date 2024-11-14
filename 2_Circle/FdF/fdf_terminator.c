/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_terminator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:19:23 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/14 18:10:10 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"
#include "stdio.h"
#include "stdlib.h"

void	free_fdf_coord(t_fdf *fdf)
{
	int	y;
	t_coord	**temp;

	temp = fdf->map.data;
	y = 0;
	while (y < fdf->map.height)
	{
		free(temp[y]);
		y++;
	}
	free(temp);
}

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

void	free_fdf_maplist(t_map_list *node)
{
	t_map_list	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		free_split(tmp->list, NULL, 0);
		free(tmp);
	}
}

void	terminator(int flag, void *data, int errnum, char *msg)
{
	if (data && flag == 3)
		free_fdf_coord((t_fdf *)data);
	else if (data && flag == 4)
		free_fdf_maplist((t_map_list *)data);
	if (flag == 0)
		exit(flag);
	else if (flag == -1)
		return ;
	if (errnum)
		perror(msg);
	else
		ft_putendl_fd(msg, 2);
	if (flag == 2)
		free(msg);
	exit(flag);
}
