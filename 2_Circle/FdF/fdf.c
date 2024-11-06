/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:06:20 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/07 03:35:16 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "./libft/libft.h"

int	main(int ac, char *av[])
{
	t_fdf		fdf;
	t_map_list	*temp;

	if (ac < 2)
		//error
	valid_fdf_file(av[1]);// 인수 파일의 형식이 .fdf인지 확인
	init_fdf_struct(&fdf);// t_fdf 구조체 초기화
	temp = NULL;
	set_map_struct(&fdf, &temp, av[1]);// t_map setting


	return (0);
}
