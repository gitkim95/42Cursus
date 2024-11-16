/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:06:20 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/16 12:50:04 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"
#include <mlx.h>
#include <math.h>

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = (unsigned int *)(fdf->addr + (y * fdf->line_len + x * (fdf->bpp / 8)));
	*dst = color;
}

void	init_fdf_struct(t_fdf	*fdf, char *file_path)
{
	char	*name;

	name = ft_strjoin("Output screen of ", file_path);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, name);
	free(name);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,\
		&fdf->line_len, &fdf->endian);
}

static t_bresenham	init_bresenham(t_point p1, t_point p2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;

	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
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
	// float	m;
	// int		x;
	// int		y;
	// float	dx;
	// float	dy;

	// x = p1.x;
	// y = p1.y;
	// dx = p2.x - p1.x;
	// dy = p2.y - p1.y;
	// m = dy / dx;
	// while (p1.x != p2.x || p1.y != p2.y)
	// {
	// 	my_mlx_pixel_put(fdf, p1.x, p1.y, p1.color);
	// 	if(dx > dy) {
	// 		if (p2.x > p1.x)
	// 			++(p1.x);
	// 		else
	// 			--(p1.x);
	// 		p1.y = m * (p1.x - x) + y;
	// 	}
	// 	else {
	// 		if (p2.y > p1.y)
	// 			++(p1.y);
	// 		else
	// 			--(p1.y);
	// 		p1.x = (p1.y - y) / m + x;
	// 	}
	// }
	// my_mlx_pixel_put(fdf, p1.x, p1.y, p1.color);
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
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,\
		&fdf->line_len, &fdf->endian);
	draw_horizen_line(fdf);
	draw_vertical_line(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (0);
}

int	main(int ac, char *av[])
{
	t_fdf		fdf;

	if (ac != 2)
	{
		//error
	}
	valid_fdf_file(av[1]);
	set_struct_zero(&fdf);
	set_map_struct(&fdf, av[1]);
	init_fdf_struct(&fdf, av[1]);
	// fdf_hook(&fdf);
	// fdf_draw(&fdf);

	

	mlx_loop_hook(fdf.mlx, refresh_image, &fdf); // 2번째 인자로 다 지우고 새로 그리기 넣기
	mlx_loop(fdf.mlx);
	return (0);
}

/*
.fdf 파일이 유효한지 확인
메인 구조체 초기화
fdf.map 구조체 세팅
*/
	// for(int i = 0; i < fdf.map.height; i++)
	// {
	// 	for (int j = 0; j < fdf.map.width; j++)
	// 	{
	// 		printf("%d ", fdf.map.map[i][j]);
	// 	}
	// 	printf("%c", '\n');
	// }