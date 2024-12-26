#ifndef EXAM04_H
# define EXAM04_H

typedef struct s_cmd
{
	char			**cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_list
{
	t_cmd	*head;
	t_cmd	*tail;
	int		cmd_size;
	int		**pipe_fd;
}	t_list;

t_cmd	*make_node(char **cmd, int cmd_len);
void	list_add_back(t_list *cmd_list, t_cmd *node);
void	make_list(t_list *cmd_list, char **cmd, int *pipe_idx, int pipe_num);

void	make_pipe(t_list *cmd_list, int pipe_num);
int		*count_pipe(char **cmd, int *pipe_num);

void	close_all(int **pipe_fd, int pipe_num);
void	free_all(t_list *cmd_list);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
void	ft_putstr(int fd, char *str);
void	ft_error(char *str1, char *str2);

#endif