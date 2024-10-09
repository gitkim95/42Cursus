/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typematch_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42.gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:12:19 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/10 02:11:48 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "../Libft/libft.h"

int	print_c_p(char arg, va_list ap)
{
	int		length;
	char	c;

	if (arg == '%')
		c = '%';
	else
		c = (char)va_arg(ap, int);
	length = ft_printchar(c);
	return (length);
}
int	print_s(char arg, va_list ap)
{
	int	length;
	char	*s;

	s = va_arg(ap, char *);
	length = ft_printstr(s);
	return (length);
}
int	print_p(char arg, va_list ap)
{
	int	length;

	length = 0;
}
int	print_d_i(char arg, va_list ap)
{
	int		length;
	int		nbr;
	char	*nbr_toa;

	nbr = va_arg(ap, int);
	nbr_toa = ft_itoa(nbr);
	length = ft_printstr(nbr_toa);
	return (length);
}
