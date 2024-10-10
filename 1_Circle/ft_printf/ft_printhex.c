/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:04:37 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/10 19:20:01 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "../Libft/libft.h"

void	conv_shex(int nbr, int *cnt)
{
	if (nbr > 16)
		conv_shex(nbr / 16, cnt);
	ft_printchar(LOWCASE[nbr / 16]);
	*cnt += 1;
}

void	conv_bhex(int nbr, int *cnt)
{
	if (nbr < 0)
	{
		ft_printchar('-');
		*cnt += 1;
		nbr *= -1;
	}
	if (nbr > 16)
		conv_bhex(nbr / 16, cnt);
	ft_printchar(UPCASE[nbr / 16]);
	*cnt += 1;
}
char	*conv_addr(int nbr)
{
	
}