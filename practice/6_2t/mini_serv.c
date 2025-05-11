

#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>

const int bufsize = 120000;
typedef struct s_client
{
	char buf[bufsize];
	int cli_id;
} t_client;

int serv_sock;
char print_buf[bufsize];
char write_buf[bufsize];
char line[bufsize];
t_client cli_data[FD_SETSIZE];


int main(int argc, char **argv)
{

}