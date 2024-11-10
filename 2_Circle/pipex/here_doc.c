/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 03:36:32 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/11 06:55:23 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void	get_stdin(t_pipex *cmd, int cmd_idx)
{
	char	buf[BUFFER_SIZE];
	int		lim_len;
	int		buf_len;
	int		n;

	lim_len = ft_strlen(cmd->limiter);
	while (1)
	{
		ft_printf("%s", "> ");
		n = read(0, buf, BUFFER_SIZE);
		if (n == -1)
			terminator(1, cmd, errno, "STDIN failed");
		buf[n] = '\0';
		buf_len = ft_strlen(buf);
		if (buf_len == lim_len && !ft_strncmp(buf, cmd->limiter, lim_len + 1))
			break;
		write(cmd->pipe_fd[0][1], buf, n);
	}
	close(cmd->pipe_fd[0][1]);
	execve_cmd(cmd, NULL, cmd_idx);
}

// void handle_here_doc(const char *delimiter, int pipefd[2]) {
//     char *line = NULL;
//     size_t len = 0;
//     ssize_t nread;

//     // 표준 입력에서 계속 읽어 들임
//     while (1) {
//         // 프롬프트 출력
//         printf("> ");
//         nread = getline(&line, &len, stdin);
//         if (nread == -1) {
//             break;
//         }

//         // "eof" 문자열을 만나면 종료
//         if (strncmp(line, delimiter, strlen(delimiter)) == 0) {
//             break;
//         }

//         // 파이프에 데이터를 씁니다.
//         write(pipefd[1], line, nread);
//     }

//     free(line);
//     close(pipefd[1]);  // 파이프의 쓰기 끝을 닫음
// }
// waitpid로 자식 2개 기다린 후 종료
// 직후 다시 fork, outfile에 STDOUT dup2 수행, 실행함수
// 부모프로세스는 else분기로 나와서 표준입력 받는다
//dup2(pipefd[0], STDIN_FILENO); 후 실행 함수
void	hd_make_pipe() // 자리 나면 fork까지
{

}

void	handle_heredoc(t_pipex *cmd, int argc, char *argv[], char *envp[])
{
	cmd->arg_size = argc - 4;
	cmd->path = set_path(envp, cmd);
	cmd->head = NULL;
	cmd->tail = NULL;
	cmd->limiter = ft_strjoin(argv[2], "\n");
	cmd->input_fd = STDIN_FILENO;
	cmd->output_fd = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
	if (cmd->output_fd == -1)
		terminator(1, cmd, errno, argv[argc - 1]);
	set_struct_data(cmd, argv, 3);
	set_cmd(cmd);
}
