/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:54:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/26 17:43:03 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*newstk;
	int		size;

	a = NULL;
	b = NULL;
	size = 1;
	while (size < ac)
	{
		newstk = ps_newlst(ft_atoi(av[size]));
		if (!newstk)
		{
			ps_lstclear(&a);
			return (0);
		}
		ps_lstadd_back(&a, newstk);
		size++;
	}
	return (0);
}
