/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:37:57 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/10 22:52:58 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"

void close_pipes(t_pipex *cmd)
{
    int i;

    i = 0;
    while (i < cmd->arg_size - 1)
    {
        close(cmd->pipe_fd[i][0]);
        close(cmd->pipe_fd[i][1]);
        i++;
    }
}

int main (int argc, char *argv[], char *envp[])
{
	t_pipex	cmd;

	if (argc < 5)
		terminator(1, NULL, 0, "Not enough argument");
	set_struct_pipex(&cmd, argc, argv, envp);
	pipe_logic(&cmd, envp);
	close_pipes(&cmd);
	terminator(0, &cmd, 0, NULL);
}
