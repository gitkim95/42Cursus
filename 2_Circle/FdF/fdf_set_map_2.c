/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:43:10 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/13 22:16:24 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"

void	set_min_max(t_fdf *fdf)
{
	int	height;
	int	width;

	height = 0;
	while (height < fdf->map.height)
	{
		width = 0;
		while (width < fdf->map.width)
		{
			if (fdf->map.z_max < fdf->map.map[height][width])
				fdf->map.z_max = fdf->map.map[height][width];
			if (fdf->map.z_min > fdf->map.map[height][width])
				fdf->map.z_min = fdf->map.map[height][width];
			width++;
		}
		height++;
	}
}

void	set_map(t_fdf *fdf, t_map_list **head)
{
	t_map_list	*node;
	int			width;
	int			height;

	node = *head;
	height = 0;
	while (height < fdf->map.height)
	{
		width = 0;
		while (width < fdf->map.width)
		{
			fdf->map.map[height][width] = ft_atoi(node->list[width]);
			width++;
		}
		node = node->next;
		height++;
	}
	fdf_maplist_free(*head);
}

void	set_integer_map(t_fdf *fdf, t_map_list **head)
{
	int			idx;

	if (fdf->map.height <= 0 || fdf->map.width <= 0)
		terminator(4, *head, 0, "File data incorrect");
	fdf->map.data = (t_coord **)malloc(sizeof(t_coord *) * fdf->map.height);
	if (!(fdf->map.data))
	{
		//error// 여기까지 함
		
	}
	idx = 0;
	while (idx < fdf->map.height)
	{
		fdf->map.map[idx] = (int *)malloc(sizeof(int) * fdf->map.width);
		if (!(fdf->map.map[idx]))
		{
			//error
		}
		idx++;
	}
	set_map(fdf, head);
}

int	get_map_width(char **buf_split)
{
	int	idx;

	idx = 0;
	while (buf_split[idx] && !(*buf_split[idx] == '\n'))
		idx++;
	return (idx);
}
