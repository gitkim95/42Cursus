/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:19:06 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/11 19:28:56 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <unistd.h> // read
# include <stdlib.h> // malloc, free

char	*get_next_line(int fd);

#endif

// 읽은 줄을 뱉거나 널을 리턴
// fd의 내용을 한 줄씩 읽고 반환하라
// 