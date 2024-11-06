/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:06:20 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/06 22:11:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "./libft/libft.h"

int	get_map_width(char **buf_split)
{
	int	idx;

	idx = 0;
	while (buf_split[idx] != '\n' || buf_split[idx] != '\0')
		idx++;
	return (idx);
}

int	get_map_height
{

}

void	set_map_size(t_fdf *fdf, int fd)
{
	char	*buf;
	char	**buf_split;
	int		cal_width

	while (1)
	{
		buf = get_next_line(fd);
		if (!buf || !(*buf))
			break ;
		buf_split = ft_split(buf, ' ');
		if (!buf_split)
			terminator(1, buf, NULL, NULL);
		free(buf);
		cal_width = get_map_width(buf_split);
		if (fdf->map->width && fdf->map->width != get_map_width(buf_split))
			terminator(1, NULL, NULL, fdf);
		fdf->map->width = get_map_width(buf_split);
		free_split(buf_split);
		fdf->map->height++;
	}
}

void	valid_fdf_file(char *file_path)
{
	char	**file_path_split;
	int		idx;

	file_path_split = ft_split(file_path, '.');
	if (!file_path_split)
		terminator(1, NULL, NULL, NULL);
	idx = 0;
	while (file_path_split[idx])
		idx++;
	if (!ft_strncmp(file_path_split[idx - 1], "fdf", 4))
	{
		free_split(file_path_split);
		return ;
	}
	else
		terminator(1, NULL, file_path_split, NULL);
}

void	check_valid_file(char *file_path)
{
	int	fd;
	int	idx;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		terminator(1, NULL, NULL, NULL);
	
}

void	init_fdf_struct(t_fdf *fdf)
{
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->data_addr = NULL;
	fdf->bpp = 0;
	fdf->size_line = 0;
	fdf->endian = 0;
	fdf->color = 0;
	fdf->map = NULL;
}

int	main(int ac, char *av[])
{
	t_fdf	fdf;
	int		fd;

	init_fdf_struct(&fdf);
	if (av)
	fd = open(av[1], O_RDONLY);

	close(fd);
	return (0);
}
