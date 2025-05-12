#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_clidata
{
	int cli_id;
	char cli_buf[120000];
} t_clidata;

int serv_sock = 0, maxfd = 0, numbering = 0;
fd_set fdsets, readfds;
char print_buf[120000], read_buf[120000], line[120000];
t_clidata cli_data[FD_SETSIZE];

int extract_line(int fd)
{
	int i = 0;

	while (cli_data[fd].cli_buf[i] && cli_data[fd].cli_buf[i] != '\n')
	{
		line[i] = cli_data[fd].cli_buf[i];
		i++;
	}

	if (cli_data[fd].cli_buf[i] == '\n')
	{
		line[i] = '\0';
		i++;

		int j = 0;
		while (cli_data[fd].cli_buf[i])
			cli_data[fd].cli_buf[j++] = cli_data[fd].cli_buf[i++];
		cli_data[fd].cli_buf[j] = '\0';
		return (1);
	}
	line[0] = '\0';
	return (0);
}

void send_to_client(int fd, int len)
{
	for (int i = 0; i <= maxfd; ++i)
	{
		if (i != serv_sock && i != fd && FD_ISSET(i, &fdsets))
			send(i, print_buf, len, 0);
	}
}

void print_error_exit(char *msg)
{
	if (serv_sock)
		close(serv_sock);
	write(STDERR_FILENO, msg, strlen(msg));
	exit(1);
}

int main(int argc, char **argv)
{
	bzero(&print_buf, sizeof(print_buf));
	bzero(&read_buf, sizeof(read_buf));
	bzero(&line, sizeof(line));
	bzero(&cli_data, sizeof(cli_data));

	if (argc != 2)
		print_error_exit("Wrong number of arguments\n");

	int port = atoi(argv[1]);

	serv_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (serv_sock < 0)
		print_error_exit("Fatal error\n");

	struct sockaddr_in serv_addr;
	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serv_addr.sin_port = htons(port);

	if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		print_error_exit("Fatal error\n");

	if (listen(serv_sock, 10) < 0)
		print_error_exit("Fatal error\n");

	FD_ZERO(&fdsets);
	FD_SET(serv_sock, &fdsets);
	maxfd = serv_sock;

	while (1)
	{
		readfds = fdsets;
		if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0)
			print_error_exit("Fatal error\n");

		for (int fd = 0; fd <= maxfd; ++fd)
		{
			if (FD_ISSET(fd, &readfds))
			{
				if (fd == serv_sock)
				{
					struct sockaddr_in cli_addr;
					bzero(&cli_addr, sizeof(cli_addr));
					socklen_t clilen = sizeof(cli_addr);
					int cli_sock = accept(fd, (struct sockaddr *)&cli_addr, &clilen);
					if (cli_sock < 0)
						print_error_exit("Fatal error\n");

					cli_data[cli_sock].cli_id = numbering++;
					FD_SET(cli_sock, &fdsets);
					if (cli_sock > maxfd)
						maxfd = cli_sock;

					int len = sprintf(print_buf, "server: client %d just arrived\n", cli_data[cli_sock].cli_id);
					send_to_client(cli_sock, len);
				}
				else
				{
					int read_len = recv(fd, read_buf, sizeof(read_buf) - 1, 0);
					if (read_len <= 0)
					{
						FD_CLR(fd, &fdsets);
						close(fd);
						if (fd == maxfd)
						{
							while (maxfd >= 0 && !FD_ISSET(maxfd, &fdsets))
								--maxfd;
						}
						int len = sprintf(print_buf, "server: client %d just left\n", cli_data[fd].cli_id);
						send_to_client(fd, len);
					}
					else
					{
						read_buf[read_len] = '\0';
						strcat(cli_data[fd].cli_buf, read_buf);
						if (extract_line(fd))
						{
							int len = sprintf(print_buf, "client %d: %s", cli_data[fd].cli_id, line);
							send_to_client(fd, len);
						}
					}
				}
			}
		}
	}
}