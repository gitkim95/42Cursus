/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:06:20 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/07 22:48:33 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"
#include <mlx.h>

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	dst = (unsigned int *)(fdf->addr + (y * fdf->line_len + x * (fdf->bpp / 8)));
	*dst = color;
}

int	main(int ac, char *av[])
{
	t_fdf		fdf;

	if (ac < 2)
	{
		//error
	}
	valid_fdf_file(av[1]);
	init_fdf_struct(&fdf);
	set_map_struct(&fdf, av[1]);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 500, 500, "Hello world!"); // 창 크기와 타이틀 설정
	fdf.img = mlx_new_image(fdf.mlx, 500, 500);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.line_len, &fdf.endian);
	my_mlx_pixel_put(&fdf, 5, 5, 0x0000FF00);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
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