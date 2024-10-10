/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42.gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:21:17 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/10 23:58:41 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

void	conv_hex(size_t nbr, int *cnt, char arg)
{
	if (nbr >= 16)
		conv_hex(nbr / 16, cnt, arg);
	if (arg == 'x')
		*cnt += ft_printchar(LOWCASE[nbr % 16]);
	else
		*cnt += ft_printchar(UPCASE[nbr % 16]);
}

void	conv_addr(size_t nbr, int *cnt)
{
	if (*cnt == 0)
		cnt += ft_printstr("0x");
	if (nbr >= 16)
		conv_addr(nbr / 16, cnt);
	*cnt += ft_printchar(LOWCASE[nbr % 16]);
}
