#include <unistd.h>
#include <stdlib.h>
#include "exam04.h"

void	make_pipe(t_list *cmd_list, int pipe_num)
{
	int	i;

	cmd_list->pipe_fd = (int **)malloc(sizeof(int *) * pipe_num);
	i = 0;
	while (i < pipe_num)
	{
		cmd_list->pipe_fd[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < pipe_num)
	{
		pipe(cmd_list->pipe_fd[i]);
		i++;
	}
}

int	*count_pipe(char **cmd, int *pipe_num)
{
	int	*pipe_idx;

	int idx1;
	int	idx2;

	idx1 = 0;
	idx2 = 0;
	*pipe_num = 0;
	while (cmd[idx1])
	{
		if (!strcmp(cmd[idx1], "|"))
			(*pipe_num)++;
		idx1++;
	}
	pipe_idx = (int *)malloc(sizeof(int) * (*pipe_num) + 1);
	idx1 = 0;
	while (cmd[idx1])
	{
		if (!strcmp(cmd[idx1], "|"))
		{
			pipe_idx[idx2] = idx1;
			idx2++;
		}
		idx1++;
	}
	pipe_idx[idx2] = idx1;
	return (pipe_idx);
}
