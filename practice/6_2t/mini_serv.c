#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

const int bufsize = 120000;
typedef struct s_client
{
	char buf[bufsize];
	int cli_id;
} t_client;

int serv_sock, maxfd = 0, number = 0;
char write_buf[bufsize];
char read_buf[bufsize];
char line[bufsize];
t_client cli_data[FD_SETSIZE];
fd_set fdsets, readfds;

int extract_line(int fd)
{
	int i = 0;

	while (cli_data[fd].buf[i] && cli_data[fd].buf[i] != '\n')
	{
		line[i] = cli_data[fd].buf[i];
		i++;
	}

	if (cli_data[fd].buf[i] == '\n')
	{
		line[i] = '\0';
		i++;
		int j = 0;

		while (cli_data[fd].buf[i])
			cli_data[fd].buf[j++] = cli_data[fd].buf[i++];
		cli_data[fd].buf[j] = '\0';
		return (1);
	}
	line[0] = '\0';
	return (0);
}

void send_to_client(int fd, const char *msg, int len)
{
	for (int i = 0; i <= maxfd; ++i)
	{
		if (i != serv_sock && i != fd && FD_ISSET(i, &fdsets))
			send(i, msg, len, 0);
	}
}

void print_error_exit(char *msg)
{
	int len = sprintf(write_buf, "%s\n", msg);

	write(STDERR_FILENO, write_buf, len);
	exit(1);
}

int main(int argc, char **argv)
{
	bzero(write_buf, sizeof(write_buf));
	bzero(read_buf, sizeof(read_buf));
	bzero(line, sizeof(line));
	bzero(cli_data, sizeof(cli_data));
	if (argc != 2)
		print_error_exit("Wrong number of arguments");

	int port = atoi(argv[1]);

	serv_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (serv_sock < 0)
		print_error_exit("Fatal error");

	struct sockaddr_in serv_addr;
	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serv_addr.sin_port = htons(port);

	if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		close(serv_sock);
		print_error_exit("Fatal error");
	}

	if (listen(serv_sock, 10) < 0)
	{
		close(serv_sock);
		print_error_exit("Fatal error");
	}

	FD_ZERO(&fdsets);
	FD_SET(serv_sock, &fdsets);
	maxfd = serv_sock;

	while (1)
	{
		readfds = fdsets;
		if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0)
		{
			close(serv_sock);
			print_error_exit("Fatal error");
		}

		for (int fd = 0; fd <= maxfd; ++fd)
		{
			if (FD_ISSET(fd, &fdsets))
			{
				if (fd == serv_sock)
				{
					struct sockaddr_in cli_addr;
					bzero(&cli_addr, sizeof(cli_addr));
					socklen_t clilen = sizeof(cli_addr);
					int clifd = accept(fd, (struct sockaddr *)&cli_addr, &clilen);
					if (clifd < 0)
					{
						close(serv_sock);
						print_error_exit("Fatal error");
					}

					FD_SET(clifd, &fdsets);
					if (clifd > maxfd)
						maxfd = clifd;
					cli_data[clifd].cli_id = number++;
					int len = sprintf(write_buf, "server: client %d just arrived\n", cli_data[clifd].cli_id);
					send_to_client(fd, write_buf, len);
				}
				else
				{
					int read_len = recv(fd, read_buf, sizeof(read_buf) - 1, 0);
					if (read_len <= 0)
					{
						FD_CLR(fd, &fdsets);
						close(fd);
						int len = sprintf(write_buf, "server: client %d just left\n", cli_data[fd].cli_id);
						send_to_client(fd, write_buf, len);
						if (fd == maxfd)
						{
							while (maxfd >= 0 && !FD_ISSET(maxfd, &fdsets))
								--maxfd;
						}
					}
					else
					{
						read_buf[read_len] = '\0';
						strcat(cli_data[fd].buf, read_buf);
						while (extract_line(fd))
						{
							int len = sprintf(write_buf, "client %d: %s\n", cli_data[fd].cli_id, line);
							send_to_client(fd, write_buf, len);
						}
					}
				}
			}
		}
	}
}