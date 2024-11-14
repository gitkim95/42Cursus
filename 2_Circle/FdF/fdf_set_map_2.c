/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:43:10 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/15 00:58:46 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"

void	set_coord_center(t_fdf *fdf)
{
	int		height;
	int		width;
	t_coord	**data;

	data = fdf->map.data;
	height = 0;
	while (height < fdf->map.height)
	{
		width = 0;
		while (width < fdf->map.width)
		{
			data[height][width].x -= fdf->map.width / 2;
			data[height][width].y -= fdf->map.height / 2;
			data[height][width].z -= (fdf->map.z_max + fdf->map.z_min) / 2;
			width++;
		}
		height++;
	}
}

void	set_min_max(t_fdf *fdf)
{
	int	height;
	int	width;

	height = 0;
	while (height < fdf->map.height)
	{
		width = 0;
		while (width < fdf->map.width)
		{
			if (fdf->map.z_max < fdf->map.data[height][width].z)
				fdf->map.z_max = fdf->map.data[height][width].z;
			if (fdf->map.z_min > fdf->map.data[height][width].z)
				fdf->map.z_min = fdf->map.data[height][width].z;
			width++;
		}
		height++;
	}
}

int	hex_to_int(char *hex)
{
	int	ret;
	int	idx;
	int	hex_idx;

	ret = 0;
	idx = 0;
	while (hex[idx])
	{
		hex_idx = 0;
		if (hex[idx] < 71)
		{
			while (UPPERHEX[hex_idx] != hex[idx])
				hex_idx++;
		}
		else
		{
			while (LOWERHEX[hex_idx] != hex[idx])
				hex_idx++;
		}
		ret = ret * 16 + hex_idx;
		idx++;
	}
	return (ret);
}

void	set_map_color(t_coord *coord, char *data)
{
	char *color;

	color = ft_strchr(data, ',');
	if (color)
	{
		color += 3;
		coord->color = hex_to_int(color);
	}
	else
	{
		coord->color = 0xFFFFFF;
	}
}
