/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:38:04 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/08 20:02:03 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> //open
# include <unistd.h> //close, read, write, access, dup, dup2, execve, fork, pipe, unlink,
# include <stdlib.h> //malloc, free, exit, 
# include <stdio.h> //perror
# include <string.h> //strerror
# include <sys/wait.h> // wait, waitpid


#endif
/*
./pipex file1 cmd1 cmd2 file2 의 형식으로 실행된다.
file1: 첫 번째 파일 이름 (입력 파일)
cmd1: 첫 번째 셸 명령어 및 그에 따른 파라미터
cmd2: 두 번째 셸 명령어 및 그에 따른 파라미터
file2: 두 번째 파일 이름 (출력 파일)
$> < file1 cmd1 | cmd2 > file2와 같이 작동하게 하는 게 목표.
프로그램에서 오류 처리를 철저히 해야 하며, 절대로 예기치 않게 종료되지 않도록 해야 한다.
*/