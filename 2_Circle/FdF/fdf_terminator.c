/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_terminator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:19:23 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/07 17:39:24 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"

void	free_split(char **split)
{
	int	idx;

	idx = 0;
	while (split[idx])
	{
		free(split[idx]);
		idx++;
	}
	free(split);
}

void	fdf_maplist_free(t_map_list *node)
{
	t_map_list	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		free_split(tmp->list);
		free(tmp);
	}
}

void	terminator(int type, void *addr_1, char **addr_2, t_map_list *node)
{
	if (addr_1)
		free(addr_1);
	if (addr_2)
		free_split(addr_2);
	if (node)
		fdf_maplist_free(node);
	if (type == 0)
	{
		ft_putendl_fd("OK", 1);
		exit(0);
	}
	if (type == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	if (type == 2)
	{
		ft_putendl_fd("KO", 2);
		exit(1);
	}
}
