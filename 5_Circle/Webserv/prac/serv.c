/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:01:04 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/08 10:38:10 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h> // sigaction, sigemptyset
#include <stdio.h>
#include <string.h> // memset
#include <stdlib.h> // exit
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h> // waitpid
#define BUF_SIZE 30

void read_childproc(int sig)
{
    int status;
    pid_t pid;

    // 자식 프로세스 종료를 기다리고, 좀비 프로세스 방지
	(void)sig;
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        printf("Child process %d terminated\n", pid);
    }
}

int	main(int argc, char **argv)
{
	if (argc != 2) {
		exit (1);
	}
	int					serv_sock, clnt_sock;
	struct sockaddr_in	serv_adr, clnt_adr;
	pid_t				pid;
	struct sigaction	act;
	socklen_t			adr_size;
	int					str_len;
	char				buf[BUF_SIZE];

	act.sa_handler = read_childproc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGCHLD, &act, 0); // handler 설정, mask 초기화, flag 설정, SIGCHLD 핸들러 등록

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));

	serv_adr.sin_family = AF_INET; // address family, process family라는 의미, 같은 값이다.
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY); // 32비트 IPv4 주소를 저장하는 필드, htonl은 32비트 숫자를 호스트 바이트 순서에서 네트워크 바이트 순서로 변환하는 함수
	serv_adr.sin_port = htons(atoi(argv[1])); // 16비트 숫자를 호스트 바이트 순서에서 네트워크 바이트 순서로 변환하는 함수
	
	bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
	listen(serv_sock, 5);

	while(1)
	{
		adr_size = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_size);

		pid = fork();
		if (pid == 0)
		{
			close(serv_sock);
			while ((str_len = read(clnt_sock, buf, BUF_SIZE)) != 0){
				write(clnt_sock, buf, str_len);
			}
			close(clnt_sock);
			return (0);
		}
		else
			close(clnt_sock);
	}
	close(serv_sock);
	return (0);
}