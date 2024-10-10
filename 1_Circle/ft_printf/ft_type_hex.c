/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:12:19 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/10 19:20:00 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "../Libft/libft.h"

int	print_hex(char arg, va_list ap)
{
	int		length;
	int		nbr;

	length = 0;
	nbr = va_arg(ap, int);
	if (arg == 'x')
		conv_shex((unsigned int)nbr, &length);
	else
		conv_bhex(nbr, &length);
	return (length);
}

int	print_p(char arg, va_list ap)
{
	int		length;
	size_t	tmp;

	tmp = (size_t)va_arg(ap, void *);
	length = 0;
	conv_addr(tmp, &length);
}
