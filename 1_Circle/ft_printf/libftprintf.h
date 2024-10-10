/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42.gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:21:34 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/11 02:36:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h> // malloc, free
# include <unistd.h> // write
# include <stdarg.h> // va_start, va_copy, va_arg, va_end
# define TYPES "cspdiuxX%"
# define LOWCASE "0123456789abcdef"
# define UPCASE "0123456789ABCDEF"

int		ft_printchar(char c);
int		ft_printstr(char *s);
void	conv_hex(size_t nbr, int *cnt, char arg);
void	conv_addr(size_t nbr, int *cnt);
int		parsing_type(char arg, va_list ap);
int		ft_printf(const char *str, ...);
int		print_c_p(char arg, va_list ap);
int		print_s(va_list ap);
int		print_d_i(va_list ap);
int		print_u(va_list ap);
int		print_hex(char arg, va_list ap);
int		print_p(va_list ap);
char	*ft_itoa_ll(long long nbr);

char	*ft_strchr(const char *s, int c); // Makefile 수정 후 call 확인

#endif