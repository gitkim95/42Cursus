/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:43:27 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 03:38:56 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <sys/types.h>

# define BUFFER_SIZE 4096

typedef struct s_node
{
	char			**cmd;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		**p_fd;
	int		*p_idx;
	int		size;
}	t_list;

int		ft_strlen(char *str);
void	ft_putstr(int fd, char *str);
void	ft_error(char *msg, char *obj);
void 	ft_strcat(char *dst, char *src);
char	*ft_strdup(char *str);
void	free_all(t_list *list);

int		count_pipe(char **cmd);
int		recode_pipe_idx(t_list *list, char **cmd);
char	**sep_by_pipe(char **cmd, int cur_idx, int cmd_len);

void	add_back(t_list *list, t_node *node);
t_node	*make_node(char **cmd);
void	init_list(t_list *list);
void	make_list(t_list *list, char **cmd);

void	make_pipe(t_list *list);
void	close_all(t_list *list);
void	set_pipe(t_list *list, int idx);

void	ft_cd(char **cmd);
void	child(t_node *cmd, int idx, char **envp, t_list *list);
void	parent(t_list *list, pid_t *pid);
void	ft_exec(char **cmd, char **envp);

#endif