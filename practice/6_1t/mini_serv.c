#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void print_error_and_exit(const char *msg)
{
	char print_buf[1024];
	int len;

	len = sprintf(print_buf, "%s\n", msg);
	write(2, print_buf, len);
	exit(1);
}

short swap_bits(short value)
{
	return ((value & 0x00FF) << 8) | ((value & 0xFF00) >> 8);
}

int main(int argc, char *argv)
{
	// argv 에외처리
	if (argc != 2)
		print_error_and_exit("Wrong number of arguments");

	// port 정수화
	int port = atoi(argv[1]);
	if (port < 1024 || port > 65535)
	{
		write(2, "Port number must be between 1024 and 65535\n", 43);
		return (1);
	}
	// socket 생성
	int servfd = socket(AF_INET, SOCK_STREAM, 0);
	if (servfd < 0)
		print_error_and_exit("Fatal error");

	// sockaddr_in 구조체 초기화
	struct sockaddr_in serv_addr;
	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_LOOPBACK;
	serv_addr.sin_port = swap_bits(port);

	// socket bind
	if (bind(servfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		close(servfd);
		print_error_and_exit("Fatal error");
	}

	// socket listen
	if (listen(servfd, 5) < 0)
	{
		close(servfd);
		print_error_and_exit("Fatal error");
	}

	// socket accept
	struct sockaddr_in cli_addr;
	socklen_t cli_len = sizeof(cli_addr);
	int clifd = accept(servfd, (struct sockaddr *)&cli_addr, &cli_len);
	if (clifd < 0)
	{
		close(servfd);
		print_error_and_exit("Fatal error");
	}
}