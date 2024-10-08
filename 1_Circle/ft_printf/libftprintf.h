/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:21:34 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/08 18:47:49 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h> // malloc, free
# include <unistd.h> // write
# include <stdarg.h> // va_start, va_copy, va_arg, va_end

#endif

// cspdiuxX% 를 각각 처리해야한다. %() 로 받아서 파싱
// Makefile, *.h, */*.h, *.c, */*.c

// 뽀나스
// 모든 변환에 대해 다음 플래그의 조합을 관리해야 합니다: -, 0, . (정밀도) 및 필드 최소 너비.
// 다음 모든 플래그를 관리해야 합니다: #, + (네, 그 중 하나는 공백입니다).