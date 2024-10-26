/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:54:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/26 23:53:29 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

void	check_asc(t_stack **a)
{
	t_stack	*head;

	head = *a;
	while ()
}

void	radix_sort(t_stack **a)
{
	t_stack	*a_head;
	t_stack *b;
	int		lst_size;

	b = NULL;
	a_head = *a;
	lst_size = ps_lstsize(*a);
	while ()
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*newstk;
	int		size;

	a = NULL;
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
