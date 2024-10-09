/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42.gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:05:18 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/10 02:19:12 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "../Libft/libft.h"

int	parsing_type(char arg, va_list ap)
{
	int	length;

	if (ft_strchr(TYPES, arg))
	{
		if (arg == 'c' || arg == '%')
			length = print_ch_pct(arg, ap);
		if (arg == 's')
			length = print_s(arg, ap);
		if (arg == 'u')
			length = print_u(arg, ap);
		if (arg == 'd' || arg == 'i')
			length = print_d_i(arg, ap);
		if (arg == 'X' || arg == 'x')
			length = print_x(arg, ap);
		if (arg == 'p')
			length = print_p(arg, ap);
	}
	else
		return (-1);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int		ret_len;
	int		tmp;

	va_start(ap, str);
	ret_len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1))
			{
				tmp = parsing_type((char)*(str + 1), ap);
				if (tmp == -1)
					return (-1);
				ret_len += tmp;
			}
		}
		else
			ret_len += ft_printchar(*str);
		str++;
	}
	va_end(ap);
	return (ret_len);
}
