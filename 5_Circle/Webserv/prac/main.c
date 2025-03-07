/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:01:04 by gitkim            #+#    #+#             */
/*   Updated: 2025/03/08 03:55:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h> // sigaction, sigemptyset
#include <stdio.h>
#include <string.h> // memset
#include <stdlib.h> // exit
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define BUF_SIZE 30

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
	int					str_len, state;
	char				buf[BUF_SIZE];

	act.sa_handler = read_childproc();
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	state = sigaction(SIGCHLD, &act, 0); // handler 설정, mask 초기화, flag 설정, SIGCHLD 핸들러 등록

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET; // address family, process family라는 의미, 같은 값이다.
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY); // 32비트 IPv4 주소를 저장하는 필드, htonl은 32비트 숫자를 호스트 바이트 순서에서 네트워크 바이트 순서로 변환하는 함수
	serv_adr.sin_port = htons(atoi(argv[1])); // 16비트 숫자를 호스트 바이트 순서에서 네트워크 바이트 순서로 변환하는 함수
	
	
}
