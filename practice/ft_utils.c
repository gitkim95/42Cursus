#include <unistd.h>
#include <stdlib.h>
#include "exam04.h"

void	close_all(int **pipe_fd, int pipe_num)
{
	int	i;

	i = 0;
	while (i < pipe_num)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		free(pipe_fd[i]);
		i++;
	}
	free(pipe_fd);
}

void	free_all(t_list *cmd_list)
{
	int	i;
	t_cmd	*node;
	t_cmd	*temp;

	node = cmd_list->head;
	while (node)
	{
		i = 0;
		while (node->cmd[i])
		{
			free(node->cmd[i]);
			i++;
		}
		free(node->cmd);
		temp = node;
		node = node->next;
		free(temp);
	}
}

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strdup(char *str)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	ft_putstr(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_error(char *str1, char *str2)
{
	if (str1)
		ft_putstr(2, str1);
	if (str2)
		ft_putstr(2, str2);
	ft_putstr(2, "\n");
}
