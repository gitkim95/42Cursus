/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42.gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:12:19 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/10 23:50:59 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_hex(char arg, va_list ap)
{
	int		length;
	int		nbr;

	nbr = va_arg(ap, int);
	length = 0;
	conv_hex((size_t)nbr, &length, arg);
	return (length);
}

int	print_p(va_list ap)
{
	int		length;
	size_t	tmp;

	tmp = (size_t)va_arg(ap, void *);
	length = 0;
	conv_addr(tmp, &length);
	return (length);
}
