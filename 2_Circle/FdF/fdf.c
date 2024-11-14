/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:06:20 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/15 01:23:54 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"
#include <mlx.h>

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

t_point	isomatric_projection(t_coord coord)
{
	t_point	new_point;
	
	new_point.x = ??;
	new_point.y = ??;
	new_point.color = coord.color;
	coord.x;
	coord.y;
	coord.z;

	return (new_point);
}

int	redrawing(t_fdf *fdf)
{
	t_point p;
	
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,\
		&fdf->line_len, &fdf->endian);
	for (int i = 0; i < fdf->map.height; i++)
	{
		for (int j = 0; j < fdf->map.width; j++)
		{
			//2차원 투영법 공식함수(3차원)
			p = isomatric_projection(fdf->map.data[i][j]);
			p = isomatric_projection(fdf->map.data[i][j+1]);
			draw_line(p1, p2);
			p.x = p.x * fdf->scale + fdf->x_offset;
			p.y = p.y * fdf->scale+ fdf->y_offset;
			my_mlx_pixel_put(fdf, p.x, p.y, p.color);
		}
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

	

	mlx_loop_hook(fdf.mlx, redrawing, &fdf); // 2번째 인자로 다 지우고 새로 그리기 넣기
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