/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 02:36:10 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/15 02:43:23 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup[257]; // getconf OPEN_MAX + 1
	char		*buffer; // read()로 BUFFER_SIZE만큼 받아올 버퍼
	char		*result; // 결과값
	
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!backup[fd])// 해당 fd에 대한 읽은 값이 없다면 동적할당
		backup[fd] = ft_strdup("");
	result = get_line(fd, &buffer, &backup[fd]);
	free(buffer);
	return (result)

static char	*get_line(int fd, char **buffer, char **backup)
{
	int		byte; // read_file()로 파일을 잘 읽어왔는지 확인하는 변수
	char	*last_line; // 결과값
    
	// 파일을 read()를 이용해 읽어온다.
	byte = read_file(fd, buffer, backup);
	// 파일을 읽어오지 못했을때 예외처리
	if (!**backup || byte == -1)
	{
		free_ptr(backup);
		return (NULL);
	}
	// *backup에 \n을 발견했을 경우 backup에 첫번째 \n까지 문자열 반환후 반환 문자 삭제
	if (ft_strchr(*backup, '\n'))
		return (separate_line(backup));
	// 읽어들인 마지막줄까지의 backup을 동적 할당
	last_line = ft_strdup(*backup);
	free_ptr(backup);
	return (last_line);
}

static int	read_file(int fd, char **buffer, char **backup)
{
	int		byte; // read()로 파일을 잘 읽어왔는지 확인하는 변수
	char	*old_backup; // 버퍼로 읽은만큼 저장하기 위한 변수

	byte = 1;
	// \n을 발견전까지 BUFFER_SIZE만큼 파일을 읽음.
	while (!ft_strchr(*backup, '\n') && byte)
	{
		byte = read(fd, *buffer, BUFFER_SIZE);
		if (byte == -1)
			return (byte);
		(*buffer)[byte] = '\0';
		// 버퍼를 읽은 만큼 백업에 넣는다.
		old_backup = *backup;
		*backup = ft_strjoin(old_backup, *buffer);
		free(old_backup);
	}
	return (byte);
}

static char	*separate_line(char **backup)
{
	int		idx; // \n의 위치를 찾기 위한 인덱스
	char	*line; // \n 전까지 문자열
	char	*old_backup; // line을 구하기 위한 변수

	idx = 0;
	while ((*backup)[idx] != '\n')
		idx++;
	old_backup = *backup;
	// \n의 그 전부분 저장
	line = ft_substr(old_backup, 0, idx + 1);
	// \n을 만난 그 뒷부분을 저장
	*backup = ft_strdup(&(*backup)[idx + 1]);
	free(old_backup);
	return (line);
}

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}