/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:20 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/20 15:51:11 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"
#include <mlx.h>

int	fdf_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = (unsigned int *)(fdf->addr
			+ (y * fdf->line_len + x * (fdf->bpp / 8)));
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
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->line_len, &fdf->endian);
}
