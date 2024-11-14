/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:37:18 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/14 17:56:42 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <errno.h>

void	set_coord_data(t_fdf *fdf, t_map_list **head)
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
			fdf->map.data[height][width].x = width;
			fdf->map.data[height][width].y = height;
			fdf->map.data[height][width].z = ft_atoi(node->list[0]);
			set_map_color(&fdf->map.data[height][width], node);
			width++;
		}
		node = node->next;
		height++;
	}
	free_fdf_maplist(*head);
}

void	set_coord_map(t_fdf *fdf, t_map_list **head)
{
	int			idx;

	if (fdf->map.height <= 0 || fdf->map.width <= 0)
		terminator(4, *head, 0, "File data incorrect");
	fdf->map.data = (t_coord **)malloc(sizeof(t_coord *) * fdf->map.height);
	if (!(fdf->map.data))
		terminator(4, *head, 0, "Allocation failed");
	idx = 0;
	while (idx < fdf->map.height)
	{
		fdf->map.data[idx] = (t_coord *)malloc(sizeof(t_coord) * fdf->map.width);
		if (!(fdf->map.data[idx]))
		{
			free_coord_split(fdf->map.data, idx);
			terminator(4, *head, 0, "Allocation failed");
		}
		idx++;
	}
	set_coord_data(fdf, head);
	set_min_max(fdf);
}


int	get_map_width(char **buf_split)
{
	int	idx;

	idx = 0;
	while (buf_split[idx] && !(*buf_split[idx] == '\n'))
		idx++;
	return (idx);
}

void	set_map_size_n_list(t_fdf *fdf, t_map_list **temp, int fd)
{
	t_map_list	*node;
	char		*buf;
	char		**buf_split;
	int			cal_width;

	while (1)
	{
		buf = get_next_line(fd);
		if (!buf || !(*buf))
			break ;
		buf_split = ft_split(buf, ' ');
		free(buf);
		if (!buf_split)
			terminator(1, NULL, 0, "Allocation failed");
		cal_width = get_map_width(buf_split);
		node = fdf_maplist_newnode(buf_split);
		free_split(buf_split, NULL, 0);
		if (!node)
			terminator(4, *temp, 0, "Allocation failed");
		if (fdf->map.width && fdf->map.width != cal_width)
			terminator(4, *temp, 0, "File data incorrect");
		fdf_maplist_addback(temp, node);
		fdf->map.width = cal_width;
		fdf->map.height++;
	}
}

void	set_map_struct(t_fdf *fdf, char *file_path)
{
	t_map_list	*temp;
	int			fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		terminator(1, NULL, errno, "File open failed");
	temp = NULL;
	set_map_size_n_list(fdf, &temp, fd);
	close(fd);
	set_coord_map(fdf, &temp);
}
