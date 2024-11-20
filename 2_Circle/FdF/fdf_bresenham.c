/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:33:45 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/20 15:51:44 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_bresenham	init_bresenham(t_point p1, t_point p2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;

	dx = fdf_abs(p2.x - p1.x);
	dy = fdf_abs(p2.y - p1.y);
	if (p1.x < p2.x)
		sx = 1;
	else
		sx = -1;
	if (p1.y < p2.y)
		sy = 1;
	else
		sy = -1;
	return ((t_bresenham){dx, dy, sx, sy});
}

void	draw_line_to_img(t_fdf *fdf, t_point p1, t_point p2)
{
	t_bresenham	bresenham;
	int			err;
	int			e2;

	bresenham = init_bresenham(p1, p2);
	err = bresenham.dx - bresenham.dy;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		e2 = err * 2;
		if (e2 > -bresenham.dy)
		{
			my_mlx_pixel_put(fdf, p1.x, p1.y, p1.color);
			err -= bresenham.dy;
			p1.x += bresenham.sx;
		}
		if (e2 < bresenham.dx)
		{
			my_mlx_pixel_put(fdf, p1.x, p1.y, p1.color);
			err += bresenham.dx;
			p1.y += bresenham.sy;
		}
	}
	my_mlx_pixel_put(fdf, p1.x, p1.y, p1.color);
}
