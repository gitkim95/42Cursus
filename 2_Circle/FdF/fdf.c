/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:06:20 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/06 23:04:30 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "./libft/libft.h"
#include "limits.h"

// 개행이나 NULL문자 만나면 가로 줄 끝, 해당 길이를 반환
int	get_map_width(char **buf_split)
{
	int	idx;

	idx = 0;
	while (buf_split[idx] != '\n' || buf_split[idx] != '\0')
		idx++;
	return (idx);
}
// input .fdf file을 int 2중배열에 인입
void	set_integer_map(t_fdf *fdf)
{
	int	**map;
	int	idx;

	map = fdf->map->map;
	map = (int **)malloc(sizeof(int *) * fdf->map->height);
	idx = 0;
	while (idx < fdf->map->height)
	{
		map[idx] = (int *)malloc(sizeof(int) * fdf->map->width);
		idx++;
	}
	
}

// fdf->map->width, fdf->map->height setting
void	set_map_size(t_fdf *fdf, int fd)
{
	char	*buf;
	char	**buf_split;
	int		cal_width;

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
		free_split(buf_split);
		if (fdf->map->width && fdf->map->width != cal_width)
			terminator(1, NULL, NULL, fdf);
		fdf->map->width = cal_width;
		fdf->map->height++;
	}
	set_integer_map(fdf);
}
// 인수로 주어진 path의 파일 형식이 .fdf인지 확인
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
// 해당 file이 규칙에 맞는지 확인
void	check_valid_file(char *file_path)
{
	int	fd;
	int	idx;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		terminator(1, NULL, NULL, NULL);
	
}

void	init_map_struct(t_fdf *fdf)
{
	t_map	*map;

	map = fdf->map;
	map->height = 0;
	map->width = 0;
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	map->map = NULL;
}
// t_fdf 구조체 초기화
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
	fdf->map = (t_map *)malloc(sizeof(t_map));
	init_map_struct(fdf);
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
