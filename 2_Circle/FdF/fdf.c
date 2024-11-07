/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:06:20 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/07 17:35:32 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"

int	main(int ac, char *av[])
{
	t_fdf		fdf;
	t_map_list	*temp;

	if (ac < 2)
		//error
	valid_fdf_file(av[1]);// 인수 파일의 형식이 .fdf인지 확인
	init_fdf_struct(&fdf);// t_fdf 구조체 초기화
	set_map_struct(&fdf, &temp, av[1]);// t_map setting
	for(int i = 0; i < fdf.map.height; i++)
	{
		for (int j = 0; j < fdf.map.width; j++)
		{
			printf("%d ", fdf.map.map[i][j]);
		}
		printf("%c", '\n');
	}
	return (0);
}
