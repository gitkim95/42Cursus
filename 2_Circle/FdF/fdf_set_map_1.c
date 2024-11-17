/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:37:18 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/18 01:57:42 by gitkim           ###   ########.fr       */
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
			fdf->map.data[height][width].z = ft_atoi(node->list[width]);
			set_map_color(&fdf->map.data[height][width], node->list[width]);
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
			free_fdf_coord(fdf);
			terminator(4, *head, 0, "Allocation failed");
		}
		idx++;
	}
	set_coord_data(fdf, head);
	set_min_max(fdf);
	set_coord_center(fdf);
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
		buf = get_next_line(fd); // 내부 static buf free
		if (!buf || !(*buf))
			break ;
		buf_split = ft_split(buf, ' ');
		free(buf);
		if (!buf_split)
			terminator(1, NULL, 0, "Allocation failed");
		cal_width = get_map_width(buf_split);
		node = fdf_maplist_newnode(buf_split);
		fdf_maplist_addback(temp, node);
		if (!node)
			terminator(4, *temp, 0, "Allocation failed");
		if (fdf->map.width && fdf->map.width != cal_width)
			terminator(4, *temp, 0, "File data incorrect");
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
