/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:43:25 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/27 03:09:41 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "microshell.h"

int	main(int ac, char **av, char **envp)
{
	int	idx;
	int	cur_idx;

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
			cur_idx = idx;
			while (av[idx] && strcmp(av[idx], ";"))
				idx++;
			while (av[idx] && !strcmp(av[idx], ";"))
			{
				av[idx] = NULL;
				idx++;
			}
			if (!strcmp(av[cur_idx], "cd"))
				ft_cd(av + cur_idx);
			else
				ft_exec(av + cur_idx, envp);
		}
		else
			idx++;
	}
	return (0);
}