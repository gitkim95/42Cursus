#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFSIZE 120000

struct clda
{
	int id;
	char buf[BUFSIZE];
};

struct clda cli_data[FD_SETSIZE];
char pbuf[BUFSIZE], rbuf[BUFSIZE], line[BUFSIZE];
int servfd = 0, maxfd = 0, nbr = 0;
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

void send_to_client(int fd, int len)
{
	for (int i = 0; i <= maxfd; ++i)
	{
		if (i != servfd && i != fd && FD_ISSET(i, &fdsets))
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
	bzero(pbuf, sizeof(pbuf));
	bzero(rbuf, sizeof(rbuf));
	bzero(line, sizeof(line));
	bzero(cli_data, sizeof(cli_data));
}