/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_de_al.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42.gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:12:19 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/10 23:51:01 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int	print_s(va_list ap)
{
	int		length;
	char	*s;

	s = va_arg(ap, char *);
	length = ft_printstr(s);
	return (length);
}

int	print_d_i(va_list ap)
{
	int		length;
	int		nbr;
	char	*nbr_toa;

	nbr = va_arg(ap, int);
	nbr_toa = ft_itoa_ll(nbr);
	length = ft_printstr(nbr_toa);
	free(nbr_toa);
	return (length);
}

int	print_u(va_list ap)
{
	int				length;
	unsigned int	tmp_nbr;
	long long		nbr;
	char			*nbr_toa;

	tmp_nbr = va_arg(ap, unsigned int);
	nbr = (long long)tmp_nbr;
	nbr_toa = ft_itoa_ll(nbr);
	length = ft_printstr(nbr_toa);
	free(nbr_toa);
	return (length);
}
