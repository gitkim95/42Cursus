/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_valid_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:55:47 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/13 18:07:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"

void	valid_fdf_file(char *file_path)
{
	char	**file_path_split;
	int		idx;

	file_path_split = ft_split(file_path, '.');
	if (!file_path_split)
		terminator(1, NULL, 0, "Allocation Failed");
	idx = 0;
	while (file_path_split[idx])
		idx++;
	if (!ft_strncmp(file_path_split[idx - 1], "fdf", 4))
	{
		free_split(file_path_split, NULL, 0);
		return ;
	}
	else
	{
		free_split(file_path_split, NULL, 0);
		terminator(1, NULL, 0, "fdf file not found");
	}
}
