/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:37:57 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/12 01:19:17 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	cmd;

	if (argc < 5)
		terminator(1, NULL, 0, "Not enough argument");
	if (argc == 6 && !ft_strncmp(argv[1], "here_doc", 9))
		handle_heredoc(&cmd, argc, argv, envp);
	else
	{
		set_struct_pipex(&cmd, argc, argv, envp);
		pipe_logic(&cmd);
	}
	terminator(0, &cmd, 0, NULL);
	return (0);
}
