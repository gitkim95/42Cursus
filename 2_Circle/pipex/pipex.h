/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:38:04 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/12 13:11:44 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>

# define BUFFER_SIZE 1024

typedef struct s_data
{
	char			**cmd;
	int				cmd_idx;
	struct s_data	*next;
}	t_data;

typedef struct s_pipex
{
	char	**path;
	int		arg_size;
	int		input_fd;
	int		output_fd;
	int		**pipe_fd;
	char	*limiter;
	t_data	*head;
	t_data	*tail;
}	t_pipex;

//ppx_set_struct_1.c
t_data	*make_new_data_node(char **cmd, int idx);
void	set_struct_data(t_pipex *cmd, int argc, char *argv[], int idx);
char	*find_path(char *envp[], t_pipex *cmd);
char	**set_path(char *envp[], t_pipex *cmd);
void	set_struct_pipex(t_pipex *cmd, int argc, char *argv[], char *envp[]);

//ppx_set_struct_2.c
char	*check_cmd(t_pipex *data, char *cmd);
void	set_cmd(t_pipex *cmd);
void	data_lst_addback(t_pipex *cmd, t_data *new_node);
void	init_pipe_fd(t_pipex *cmd);
void	alloc_pipe_fd(t_pipex *cmd);

//ppx_logic.c
void	execve_cmd(t_pipex *cmd, int cmd_idx, char *envp[]);
void	pipe_connect_process(t_pipex *cmd, int cmd_idx);
void	fork_loop(t_pipex *cmd, pid_t *pid, int cmd_idx, char *envp[]);
void	pipe_logic(t_pipex *cmd, char *envp[]);

//fd_closer.c
void	close_all_fd(t_pipex *cmd, int cmd_idx);
void	close_child_last(t_pipex *cmd, int cmd_idx);
void	close_child_middle(t_pipex *cmd, int cmd_idx);
void	close_child_first(t_pipex *cmd);

//terminator.c
void	free_split(char **c_split, int **i_split, int i_size);
void	free_lst(t_pipex *cmd);
void	free_pipex_struct(t_pipex *cmd);
void	terminator(int flag, t_pipex *cmd, int errnum, char *msg);

//here_doc.c
void	get_stdin(t_pipex *cmd);
void	hd_pipe_logic(t_pipex *cmd, pid_t *pid);
void	hd_make_pipe(t_pipex *cmd, char *envp[]);
void	handle_heredoc(t_pipex *cmd, int argc, char *argv[], char *envp[]);

#endif