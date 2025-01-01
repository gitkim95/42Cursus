#ifndef MICROSHELL_H
# define MICROSHELL_H

# define BUFFER_SIZE 1024

typedef struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	char			*cmd;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		size;
	int		*pipe_loc;
}	t_list;


#endif