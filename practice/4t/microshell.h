/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:59:12 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/02 13:36:45 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# define BUFFER_SIZE 1024
# include <sys/types.h>

typedef struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	char			**cmd;
	int				pipe_fd[2];
}	t_node;

typedef struct	s_list
{
	t_node	*head;
	t_node	*tail;
	int		size;
	int		*pipe_idx;
}	t_list;

//exec.c
void	ft_cd(char **cmd);
void	child(t_node *node, char **envp, t_list *list);
void	parents(pid_t	*pid, t_list *list);
void	ft_exec(char **cmd, char **envp);

//list.c
void	init_list(t_list *list);
t_node	*make_node(char **av);
void	addback(t_list *list, t_node *node);
void	make_list(t_list *list, char **cmd);

//sep.c
int		count_pipe(char **cmd);
int		find_pipe(t_list *list, char **cmd);
char	**sep_by_pipe(char **cmd, int cur_idx, int len);

//utils.c
int		ft_strlen(char *str);
void	ft_putstr(int fd, char *str);
void	ft_error(char *msg, char *obj);
char	*ft_strdup(char *str);
void	free_list(t_list *list);

#endif