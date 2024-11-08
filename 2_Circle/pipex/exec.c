#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	char *env[] = {
		"/usr/bin/ls", getenv("MY_HOME"), NULL
	};

	execve(env[0], env, NULL);
}