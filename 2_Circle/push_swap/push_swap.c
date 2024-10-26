/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:54:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/27 02:56:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"
#include <limits.h>

void	check_asc(t_stack **a)
{
	t_stack	*head;

	head = *a;
	while ()
}

void	radix_sort(t_stack **a)
{
	t_stack	*a_head;
	t_stack	*b;
	int		lst_size;

	b = NULL;
	a_head = *a;
	lst_size = ps_lstsize(*a);
	while ()
}

int	main(int ac, char **av)
{
	t_stack		ps_stack;
	t_ps_node	*new_node;
	int			arg_size;

	ps_stack = (t_stack){0, INT_MIN, INT_MAX, NULL, NULL};
	arg_size = 1;
	while (arg_size < ac)
	{
		new_node = ps_newlst(ft_atoi(av[arg_size]));
		if (!new_node)
		{
			ps_lstfree(&(ps_stack.head));
			return (0);
		}
		ps_lstadd_back(&a, newstk);
		arg_size++;
	}
	return (0);
}
