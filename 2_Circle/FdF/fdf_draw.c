/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:31:10 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/20 15:52:15 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

t_point	isomatric_projection(t_fdf *fdf, t_coord coord)
{
	t_point	new_point;

	new_point.x = ((coord.x - coord.y) * cos(0.5236)) * fdf->scale;
	new_point.y = ((coord.x + coord.y) * sin(0.5236) - coord.z) * fdf->scale;
	new_point.color = coord.color;
	new_point.x = new_point.x + fdf->x_offset;
	new_point.y = new_point.y + fdf->y_offset;
	return (new_point);
}

static void	draw_projection_line(t_fdf *fdf, t_coord prev_coord, t_coord coord)
{
	t_point		p1;
	t_point		p2;

	p1 = isomatric_projection(fdf, prev_coord);
	p2 = isomatric_projection(fdf, coord);
	draw_line_to_img(fdf, p1, p2);
}

static void	draw_vertical_line(t_fdf *fdf)
{
	int			x;
	int			y;
	t_coord		prev_coord;
	t_coord		coord;

	x = 0;
	while (x < fdf->map.width)
	{
		y = 1;
		while (y < fdf->map.height)
		{
			prev_coord = fdf->map.data[y - 1][x];
			coord = fdf->map.data[y][x];
			draw_projection_line(fdf, prev_coord, coord);
			++y;
		}
		++x;
	}
}

static void	draw_horizen_line(t_fdf *fdf)
{
	int			x;
	int			y;
	t_coord		prev_coord;
	t_coord		coord;

	y = 0;
	while (y < fdf->map.height)
	{
		x = 1;
		while (x < fdf->map.width)
		{
			prev_coord = fdf->map.data[y][x - 1];
			coord = fdf->map.data[y][x];
			draw_projection_line(fdf, prev_coord, coord);
			++x;
		}
		++y;
	}
}

int	refresh_image(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, \
		&fdf->line_len, &fdf->endian);
	draw_horizen_line(fdf);
	draw_vertical_line(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (0);
}
