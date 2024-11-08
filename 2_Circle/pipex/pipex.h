/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:38:04 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/08 23:52:05 by gitkim           ###   ########.fr       */
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
access#include <unistd.h>
int access(const char *pathname, int mode);
	- 권한을 확인함
	- R_OK : 파일 존재 여부, 읽기 권한 여부
	- W_OK : 파일 존재 여부, 쓰기 권한 여부
	- X_OK : 파일 존재 여부, 실행 권한 여부
	- F_OK : 파일 존재 여부
	- 성공 시 0 반환, 실패 시 -1 반환
dup(int fd);
	- fd를 복제하여 반환
	- 성공 시 fd 반환, 실패 시 -1 반환
dup2(int fd, int fd2);
	- fd를 복제하여 fd2값으로 지정
	- 이미 fd2가 open되어있다면 close 후 복제 실행
execve(const char *filename, char *const argv[], char *const envp[]);
	- filename이 가리키는 파일을 실행, 이는 실행파일이거나 스크립트여야 함
	- ex)	char *catArgv[] = {"/usr/bin/cat", "Makefile", NULL};
			execve(catArgv[0], catArgv, NULL);
fork()
	- 성공 시 부모 프로세서에서는 자식 프로세서의 PID값을 반환, 실패 시 -1
	- https://codetravel.tistory.com/23
	- <sys/types.h> 확인 필요 ----pid_t pid;----
pipe(int fd[2]);
	- 함수 호출 후 fd[0]에 데이터 입력을 받을 수 있는 fd 저장 (출구, write)
	- 함수 호출 후 fd[1]에 데이터 출력을 할 수 있는 fd 저장 (입구, read)
	- 성공 시 0을 반환, 실패 시 -1을 반환
	- https://nroses-taek.tistory.com/139
unlink(const char* pathname);
	- 받은 경로의 파일을 삭제한다.
	- 성공 시 0을 반환, 실패 시 -1을 반환
perror(const char *string);
	- 받은 string을 stderr로 출력
strerror-
wait	-
waitpid	-
*/