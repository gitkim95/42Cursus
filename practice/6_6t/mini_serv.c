#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

struct cli
{
	int id;
	char buf[120000];
};

struct cli clidata[FD_SETSIZE];
int servfd = 0, maxfd = 0, nbr = 0;
char pbuf[120000], rbuf[120000], line[120000];
fd_set fdset, readfds;

int extract_line(int fd)
{
	int i = 0;

	while (clidata[fd].buf[i] && clidata[fd].buf[i] != '\n')
	{
		line[i] = clidata[fd].buf[i];
		i++;
	}

	if (clidata[fd].buf[i] == '\n')
	{
		line[i] = '\0';
		i++;
		
		int j = 0;
		while (clidata[fd].buf[i])
			clidata[fd].buf[j++] = clidata[fd].buf[i++];
		clidata[fd].buf[j] = '\0';
		return (1);
	}
	line[0] = '\0';
	return (0);
}

void send_to_client(int fd, int len)
{
	for (int i = 0; i <= maxfd; ++i)
	{
		if (i != servfd && i != fd && FD_ISSET(i, &fdset))
			send(i, pbuf, len, 0);
	}
}

void print_error_exit(char *msg)
{
	if (servfd)
		close(servfd);

	write(STDERR_FILENO, msg, strlen(msg));
	exit(1);
}

int main (int ac, char **av)
{
	memset(pbuf, 0, sizeof(pbuf));
	memset(rbuf, 0, sizeof(rbuf));
	memset(line, 0, sizeof(line));
	memset(clidata, 0, sizeof(clidata));

	if (ac != 2)
		print_error_exit("Wrong number of arguments\n");
	
	int port = atoi(av[1]);
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	servaddr.sin_port = htons(port);

	servfd = socket(AF_INET, SOCK_STREAM, 0);
	if (servfd < 0)
		print_error_exit("Fatal error\n");

	if (bind(servfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		print_error_exit("Fatal error\n");

	if (listen(servfd, 10))
		print_error_exit("Fatal error\n");
	
	FD_ZERO(&fdset);
	FD_SET(servfd, &fdset);
	maxfd = servfd;

	while (1)
	{
		readfds = fdset;
		if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0)
			print_error_exit("Fatal error\n");
		
		for (int fd = 0; fd <= maxfd; ++fd)
		{
			if (FD_ISSET(fd, &readfds))
			{
				if (fd == servfd)
				{
					struct sockaddr_in cli_addr;
					memset(&cli_addr, 0, sizeof(cli_addr));
					socklen_t clilen = sizeof(cli_addr);
					int clifd = accept(fd, (struct sockaddr *)&cli_addr, &clilen);

					FD_SET(clifd, &fdset);
					if (clifd > maxfd)
						maxfd = clifd;
					clidata[clifd].id = nbr++;

					int len = sprintf(pbuf, "server: client %d just arrived\n", clidata[clifd].id);
					send_to_client(clifd, len);
				}
				else
				{
					int read_len = recv(fd, rbuf, sizeof(rbuf) - 1, 0);
					if (read_len <= 0)
					{
						FD_CLR(fd, &fdset);
						close(fd);
						if (fd == maxfd)
						{
							while (maxfd >= 0 && !FD_ISSET(maxfd, &fdset))
								--maxfd;
						}

						int len = sprintf(pbuf, "server: client %d just left\n", clidata[fd].id);
						send_to_client(fd, len);
					}
					else
					{
						rbuf[read_len] = '\0';
						strcat(clidata[fd].buf, rbuf);

						while (extract_line(fd))
						{
							int len = sprintf(pbuf, "client %d: %s\n", clidata[fd].id, line);
							send_to_client(fd, len);
						}
					}
				}
			}
		}
	}
}