/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:06:20 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/20 15:41:33 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"
#include <mlx.h>
#include <math.h>

int	main(int ac, char *av[])
{
	t_fdf		fdf;

	if (ac != 2)
		terminator(1, NULL, 0, "Incorrect number of arguments");
	valid_fdf_file(av[1]);
	set_struct_zero(&fdf);
	set_map_struct(&fdf, av[1]);
	init_fdf_struct(&fdf, av[1]);
	mlx_hook(fdf.win, 17, 0, close_win2, &fdf);
	mlx_hook(fdf.win, 2, 1L << 0, close_win1, &fdf);
	mlx_loop_hook(fdf.mlx, refresh_image, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
