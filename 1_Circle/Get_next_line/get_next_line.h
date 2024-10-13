/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:19:06 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/13 21:34:15 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h> // read
# include <stdlib.h> // malloc, free

char	*get_next_line(int fd);
void	ft_output(char *str);

#endif

// 읽은 줄을 뱉거나 널을 리턴
// fd의 내용을 한 줄씩 읽고 반환하라
// 함수는 한 줄을 읽었으면 읽은걸 반환, 못 읽으면 널리턴
// 표준입력과 파일을 읽은게 차이가 없는지 확인해라
// 반환된 행에는 종료 개행문자가 포함되어야 하지만 마지막은 제외(없는 경우)
// 헬퍼함수는 utils.c에 포함시켜라
// 파일 크기를 읽기 위해 "-D BUFFER_SIZE=n" 옵션을 추가,
// 이는 read()의 버퍼 크기를 정의, 테스트 시 수정 가능
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c 이런식으로
// 이진파일을 읽을 때와 fd가 호출 이후 변경 시 비정상동작으로 간주
// 가능한 적게 읽게끔 해라, 새 줄을 만나면 현재 줄을 반환해야한다.

// 뽀나스
// 하나의 정적변수로 빌드
// 동시에 여러 fd를 읽고 관리할 수 있어야 한다