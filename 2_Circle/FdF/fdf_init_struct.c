/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:33:10 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/08 18:20:50 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "fdf.h"
#include "./libft/libft.h"

void	set_struct_zero(t_fdf *fdf)
{
	ft_bzero(fdf, sizeof(t_fdf));
	fdf->map.z_max = INT_MIN;
	fdf->map.z_min = INT_MAX;
}
