/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:28:02 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/01 23:32:17 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "microshell.h"

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	c_i;

	if (ac < 2)
		return (0);
	i = 1;
	while(av[i])
	{
		if (!strcmp(av[i], ";"))
		{
			av[i] = NULL;
			i++;
		}
		else if (*av[i])
		{
			c_i = i;
			while (av[i] && strcmp(av[i], ";"))
				i++;
			while (av[i] && !strcmp(av[i], ";"))
			{
				av[i] = NULL;
				i++;
			}
			if (!strcmp(av[c_i], "cd"))
				ft_cd(av + c_i);
			else
				ft_exec(av + c_i, envp);
		}
		else
			i++;
	}
	return (0);
}