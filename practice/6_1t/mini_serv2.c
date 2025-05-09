#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>

char print_buf[120000];
char read_buf[120000];
char line[120000];
char client_buffer[FD_SETSIZE][120000];
fd_set fdsets, readfds;
int servfd, maxfd = 0;
int client_ids[FD_SETSIZE];
int client_id = 0;

int extract_line(int fd)
{
	int i = 0;

	while (client_buffer[fd][i] && client_buffer[fd][i] != '\n')
	{
		line[i] = client_buffer[fd][i];
		i++;
	}
	if (client_buffer[fd][i] == '\n')
	{
		line[i] = '\0';
		i++;

		int j = 0;
		while (client_buffer[fd][i])
			client_buffer[fd][j++] = client_buffer[fd][i++];
		client_buffer[fd][j] = '\0';
		return (1);
	}
	line[0] = '\0';
	return (0);
}

void send_to_client(int fd, const char *msg, int len)
{
	for (int i = 0; i <= maxfd; ++i)
	{
		if (i != fd && FD_ISSET(i, &fdsets) && i != servfd)
			send(i, msg, len, 0);
	}
}

void print_error_and_exit(const char *msg)
{
	int len;

	len = sprintf(print_buf, "%s\n", msg);
	write(2, print_buf, len);
	exit(1);
}

int main(int argc, char **argv)
{
	bzero(print_buf, sizeof(print_buf));
	bzero(read_buf, sizeof(read_buf));
	bzero(line, sizeof(line));
	bzero(client_buffer, sizeof(client_buffer));
	// argv 에외처리
	if (argc != 2)
		print_error_and_exit("Wrong number of arguments");

	// port 정수화
	int port = atoi(argv[1]);
	if (port < 1024 || port > 65535)
		print_error_and_exit("Port number must be between 1024 and 65535");

	// socket 생성
	servfd = socket(AF_INET, SOCK_STREAM, 0);
	if (servfd < 0)
		print_error_and_exit("Fatal error1");

	// sockaddr_in 구조체 초기화
	struct sockaddr_in serv_addr;
	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serv_addr.sin_port = htons(port);

	// socket bind
	if (bind(servfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		close(servfd);
		print_error_and_exit("Fatal error2");
	}

	// socket listen
	if (listen(servfd, 10) < 0)
	{
		close(servfd);
		print_error_and_exit("Fatal error3");
	}

	FD_ZERO(&fdsets);
	FD_SET(servfd, &fdsets);
	maxfd = servfd;

	while (1)
	{
		readfds = fdsets;
		if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0)
			print_error_and_exit("Fatal error4");

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
						print_error_and_exit("Fatal error5");
					}

					FD_SET(clifd, &fdsets);
					if (clifd > maxfd)
						maxfd = clifd;
					client_ids[clifd] = client_id++;
					int len = sprintf(print_buf, "server: client %d just arrived\n", client_ids[clifd]);
					send_to_client(clifd, print_buf, len);
				}
				else
				{
					int read_len;
					while (1)
					{
						read_len = recv(fd, read_buf, sizeof(read_buf) - 1, 0);
						if (read_len <= 0)
							break;
						read_buf[read_len] = '\0';
						strcat(client_buffer[fd], read_buf);
					}

					if (read_len == 0 || (read_len < 0 && errno != EWOULDBLOCK && errno != EAGAIN))
					{
						int id = client_ids[fd];
						int len = sprintf(print_buf, "server: client %d just left\n", id);
						send_to_client(fd, print_buf, len);
						close(fd);
						FD_CLR(fd, &fdsets);
						if (fd == maxfd)
						{
							while (maxfd >= 0 && !FD_ISSET(maxfd, &fdsets))
								maxfd--;
						}
					}
					else
					{
						while (extract_line(fd))
						{
							int len = sprintf(print_buf, "client %d: %s\n", client_ids[fd], line);
							send_to_client(fd, print_buf, len);
						}
					}
				}
			}
		}
	}
}