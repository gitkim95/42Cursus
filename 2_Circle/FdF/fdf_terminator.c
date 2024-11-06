/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_terminator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:19:23 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/06 23:04:36 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "./libft/libft.h"

void	free_split(char **split)
{
	int	idx;

	idx = 0;
	while (split[idx])
	{
		free(split[idx]);
		idx++;
	}
	free(split);
}

void	fdf_lstfree(t_fdf *fdf)
{
	free(fdf->map);
	free(fdf);
}

void	terminator(int type, void *addr_1, char **addr_2, t_fdf *fdf)
{
	if (addr_1)
		free(addr_1);
	if (addr_2)
		free_split(addr_2);
	if (fdf)
		fdf_lstfree(fdf);
	if (type == 0)
	{
		ft_putendl_fd("OK", 1);
		exit(0);
	}
	if (type == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	if (type == 2)
	{
		ft_putendl_fd("KO", 2);
		exit(1);
	}
}
