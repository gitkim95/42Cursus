/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:38:04 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/12 01:58:04 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>

# define BUFFER_SIZE 1024

typedef struct s_data
{
	char			**cmd;
	int				cmd_idx;
	struct s_data	*next;
}	t_data;

typedef struct s_pipex
{
	char	**path;
	int		arg_size;
	int		input_fd;
	int		output_fd;
	int		**pipe_fd;
	char	*limiter;
	t_data	*head;
	t_data	*tail;
}	t_pipex;

//ppx_set_struct_1.c
t_data	*make_new_data_node(char **cmd, int idx);
void	set_struct_data(t_pipex *cmd, int argc, char *argv[], int idx);
char	*find_path(char *envp[], t_pipex *cmd);
char	**set_path(char *envp[], t_pipex *cmd);
void	set_struct_pipex(t_pipex *cmd, int argc, char *argv[], char *envp[]);

//ppx_set_struct_2.c
char	*check_cmd(t_pipex *data, char *cmd);
void	set_cmd(t_pipex *cmd);
void	data_lst_addback(t_pipex *cmd, t_data *new_node);
void	init_pipe_fd(t_pipex *cmd);
void	alloc_pipe_fd(t_pipex *cmd);

//ppx_logic.c
void	execve_cmd(t_pipex *cmd, int cmd_idx);
void	pipe_connect_process(t_pipex *cmd, int cmd_idx);
void	fork_loop(t_pipex *cmd, pid_t *pid, int cmd_idx);
void	pipe_logic(t_pipex *cmd);

//fd_closer.c
void	close_all_fd(t_pipex *cmd, int cmd_idx);
void	close_child_last(t_pipex *cmd, int cmd_idx);
void	close_child_middle(t_pipex *cmd, int cmd_idx);
void	close_child_first(t_pipex *cmd);

//terminator.c
void	free_split(char **c_split, int **i_split, int i_size);
void	free_lst(t_pipex *cmd);
void	free_pipex_struct(t_pipex *cmd);
void	terminator(int flag, t_pipex *cmd, int errnum, char *msg);

//here_doc.c
void	get_stdin(t_pipex *cmd);
void	hd_pipe_logic(t_pipex *cmd, pid_t *pid);
void	hd_make_pipe(t_pipex *cmd);
void	handle_heredoc(t_pipex *cmd, int argc, char *argv[], char *envp[]);

#endif
/*
./pipex file1 cmd1 cmd2 file2 의 형식으로 실행된다.
file1: 첫 번째 파일 이름 (입력 파일)
cmd1: 첫 번째 셸 명령어 및 그에 따른 파라미터
cmd2: 두 번째 셸 명령어 및 그에 따른 파라미터
file2: 두 번째 파일 이름 (출력 파일)
$> < file1 cmd1 | cmd2 > file2와 같이 작동하게 하는 게 목표.
프로그램에서 오류 처리를 철저히 해야 하며, 절대로 예기치 않게 종료되지 않도록 해야 한다.

access(const char *pathname, int mode);
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
	- fd를 복제하여 fd2에 해당 값으로 지정
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
	- 함수 호출 후 fd[0]에 데이터 입력을 받을 수 있는 fd 저장 (출구, read)
	- 함수 호출 후 fd[1]에 데이터 출력을 할 수 있는 fd 저장 (입구, write)
	- 성공 시 0을 반환, 실패 시 -1을 반환
	- https://nroses-taek.tistory.com/139
unlink(const char* pathname);
	- 받은 경로의 파일을 삭제한다.
	- 성공 시 0을 반환, 실패 시 -1을 반환
perror(const char *string);
	- 받은 string을 stderr로 출력
strerror(int errnum);
	- errno를 전달하여 호출 시 해당 errno에 맞는 오류 메세지를 반환
	- error에 맞는 메세지가 없을 경우 "Unknown error nnn" 메세지를 반환
wait(int *wstatus)
	- wstatus에는 자식 프로세스가 종료될 때의 상태 정보가 저장
	- 정상 종료 시
		- 상위 8비트에는 프로세스를 종료시킨 exit 함수의 인수가 기록
		- 하위 8비트에는 0이 저장 
	- 비정상 종료 시
		- 상위 8비트에는 0이 저장
		- 하위 8비트에는 프로세스를 종료시킨 시그널의 번호가 기록
	- 성공 시 종료된 자식 프로세스의 PID를 반환, 실패 시 -1을 반환
waitpid(pid_t pid, int *wstatus, int option)
	- 첫 번째 인수는 목표 프로세스 타겟이라고 볼 수 있다.
		- -1을 전달 시 여러 자식 프로세스가 생성이 됐다고 가정 시
			뭐든 하나라도 종료가 되면 해당 종료된 자식 프로세스의 정보를 받을 수 있다.
	- 두 번째 인수가 필요 없다면 NULL을 넣어줄 수 있다.
	- 세 번째 인수는 옵션을 넣어줄 수 있다.
		- 0을 넣을 시 일반 wait 함수와 같도록 할 수 있다.
		- WNOHANG을 넣을 시 부모 프로세스가 기다리지 않게 해준다.
	- 성공 시 종료된 자식 프로세스의 PID를 반환, 실패 시 -1을 반환
	- https://blog.naver.com/skout123/50133478563
*/