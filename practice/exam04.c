#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include "exam04.h"

void	ft_cd(char **cmd)
{
	if (!cmd[1])
		return ;
	if (!strncmp(cmd[1], "-", 1))
		ft_error("error: cd: bad arguments", NULL);
	else if (chdir(cmd[1]) == -1)
		ft_error("error: cd: cannot change directory to ", cmd[1]);
}

void	child(t_cmd *node, char **envp, t_list *cmd_list)
{
	if (execve(node->cmd[0], node->cmd, envp) == -1)
	{
		ft_error("error: cannot execute ", node->cmd[0]);
		free_all(cmd_list);
		exit(1);
	}
}

void	ft_exec(char **cmd, char **envp)
{
	t_list	cmd_list;
	t_cmd	*node;
	int		*pipe_idx;
	int		pipe_num;
	int		et;
	pid_t	pid[101];

	pipe_idx = count_pipe(cmd, &pipe_num);
	make_list(&cmd_list, cmd, pipe_idx, pipe_num);
	free(pipe_idx);
	make_pipe(&cmd_list, pipe_num);
	et = 0;
	node = cmd_list.head;
	while (et < pipe_num + 1)
	{
		pid[et] = fork();
		if (pid[et] == -1)
			ft_error("error: fatal", NULL);
		else if (pid[et] == 0)
		{
			if (et > 0)
			{
				dup2(cmd_list.pipe_fd[et - 1][0], STDIN_FILENO);
			}
			if (et != pipe_num)
			{
				dup2(cmd_list.pipe_fd[et][1], STDOUT_FILENO);
			}
			close_all(cmd_list.pipe_fd, pipe_num);
			child(node, envp, &cmd_list);
		}
		node = node->next;
		et++;
	}
	close_all(cmd_list.pipe_fd, pipe_num);
	free_all(&cmd_list);
	et = 0;
	while (et < pipe_num + 1)
	{
		waitpid(pid[et], NULL, 0);
		et++;
	}	
}

int	main(int ac, char **av, char **envp)
{
	int	idx;
	int	c_idx;

	if (ac < 2)
		return (0);
	idx = 1;
	while (av[idx])
	{
		if (!strcmp(av[idx], ";"))
		{
			av[idx] = NULL;
			idx++;
		}
		else if (*av[idx])
		{
			c_idx = idx;
			while (av[idx] && strcmp(av[idx], ";"))
				idx++;
			if (av[idx])
			{
				av[idx] = NULL;
				idx++;
			}
			if (!strcmp(av[c_idx], "cd"))
				ft_cd(av + c_idx);
			else
				ft_exec(av + c_idx, envp);
		}
		else
			idx++;
	}
	return (0);
}
