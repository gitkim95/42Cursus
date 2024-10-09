/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42.gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:21:34 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/10 02:22:28 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h> // malloc, free
# include <unistd.h> // write
# include <stdarg.h> // va_start, va_copy, va_arg, va_end

typedef struct s_check
{
	int		type;
	int		width;
	int		precision;
	char	flag;
}	t_check;

# define TYPES "cspdiuxX%"
# define LOWCASE "0123456789abcdef"
# define UPCASE "0123456789ABCDEF"

int	ft_printchar(char c);
int	ft_printstr(char *s); // printtext;

int	parsing_type(char arg, va_list ap); // printf;

int	print_c_p(char arg, va_list ap);
int	print_s(char arg, va_list ap);
int	print_p(char arg, va_list ap);
int	print_d_i(char arg, va_list ap);
int	print_shex(char arg, va_list ap);
int	print_bhex(char arg, va_list ap); // typematch


#endif

/* 	c > 문자 하나 출력 
	s > 문자열 출력
	p > 포인터 값을 16진수로 출력
	d > 부호 있는 10진 정수
	i > d와 동일
	u > 부호 없는 10진 정수
	x > 부호 없는 16진 정수 (소문자 사용)
	X > 부호 있는 16진 정수 (대문자 사용)
	% > % 문자 출력
	각각 처리해야한다. %() 로 받아서 파싱
// Makefile, *.h, *//*.h, *.c, *//*.c     */

// 뽀나스
/*	- > 왼쪽 정렬 + 필드폭(숫자)
	0 > 필드 폭 내부 빈 자리를 0으로 채움
	. > 정밀도, 정수부분은 총 자릿수, 소수 부분은 소수 출력 자릿수
	# > #o 또는 #x를 사용해서 각각 8진수, 16진수를 0, 0x를 표시하여 출력
	+ > 오른쪽 정렬 + 필드폭(숫자) , 양수에는 +, 음수에는 -를 붙여서 출력
	(네, 그 중 하나는 공백입니다). > '+' 기호 대신 공백 사용, ' +' 일 경우 + 출력

*/