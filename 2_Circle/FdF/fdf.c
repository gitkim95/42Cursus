/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:06:20 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/15 21:14:12 by gitkim           ###   ########.fr       */
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

t_point	isomatric_projection(t_fdf *fdf, t_coord coord)
{
	t_point	new_point;
	
	new_point.x = ((coord.x - coord.y) * cos(0.52)) * fdf->scale;
	new_point.y = ((coord.x + coord.y) * sin(0.52) - coord.z) * fdf->scale;
	new_point.color = coord.color;
	new_point.x = new_point.x + fdf->x_offset;
	new_point.y = new_point.y + fdf->y_offset;

	return (new_point);
}

void	draw_line1(t_fdf *fdf, t_point p1, t_point p2)
{
	int	dx;
	int	dy;
	int	p;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	p = 2 * dy - dx;
	while (p1.x <= p2.x)
	{
		my_mlx_pixel_put(fdf, p1.x, p1.y, p1.color);
		if (p < 0)
			p += 2 * dy;
		else
		{
			p1.y++;
			p += 2 * (dy - dx);
		}
		p1.x++;
	}
}

void	draw_line2(t_fdf *fdf, t_point p1, t_point p2)
{
	int	dx;
	int	dy;
	int	p;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	p = 2 * dx - dy;
	while (p2.y <= p1.y)
	{
		my_mlx_pixel_put(fdf, p1.x, p1.y, p1.color);
		if (p < 0)
			p += 2 * dx;
		else
		{
			p1.x++;
			p += 2 * (dx - dy);
		}
		p1.y++;
	}
}

int	refresh_image(t_fdf *fdf)
{
	t_point	p1;
	t_point	p2;
	int		y;
	int		x;
	
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,\
		&fdf->line_len, &fdf->endian);
	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width - 1)
		{
			p1 = isomatric_projection(fdf, fdf->map.data[y][x]);
			p2 = isomatric_projection(fdf, fdf->map.data[y][x + 1]);
			draw_line1(fdf, p1, p2);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < fdf->map.height - 1)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			p1 = isomatric_projection(fdf, fdf->map.data[y][x]);
			p2 = isomatric_projection(fdf, fdf->map.data[y + 1][x]);
			draw_line2(fdf, p1, p2);
			x++;
		}
		y++;
	}
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