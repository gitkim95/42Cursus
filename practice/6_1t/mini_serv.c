#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

char print_buf[120000];
char read_buf[120000];
fd_set fdsets, readfds;
int maxfd = 0;

void print_error_and_exit(const char *msg)
{
	int len;

	len = sprintf(print_buf, "%s\n", msg);
	write(2, print_buf, len);
	exit(1);
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
	serv_addr.sin_port = htons(port);

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

	maxfd = servfd;
	FD_ZERO(&fdsets);
	FD_SET(servfd, &fdsets);
	while (1)
	{
		readfds = fdsets;
		if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0)
			print_error_and_exit("Fatal error");
		for (int fd = 0; fd <= maxfd; ++fd)
		{
			if (FD_ISSET(fd, &readfds))
			{
				if (fd == servfd)
				{
					struct sockaddr_in cli_addr;
					socklen_t cli_len = sizeof(cli_addr);
					int clifd = accept(servfd, (struct sockaddr *)&cli_addr, &cli_len);
					if (clifd < 0)
					{
						close(servfd);
						print_error_and_exit("Fatal error");
					}

					FD_SET(clifd, &fdsets);
					if (clifd > maxfd)
						maxfd = clifd;
				}
				else
				{
				}
			}
		}
	}
}