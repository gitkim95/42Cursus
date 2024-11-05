/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:11:21 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/05 14:01:01 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ready_to_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	size;
	int	nb;
	int	pivot_1;
	int	pivot_2;

	pivot_1 = a->size / 3;
	pivot_2 = pivot_1 * 2 + 1;
	i = 0;
	size = a->size;
	while (i < size && a->size > 3)
	{
		nb = a->head->nb;
		if (nb <= pivot_1)
		{
			double_instruct(PB, a, b, 1);
			if (b->size > 1)
				single_instruct(RB, b, 1);
		}
		else if (pivot_1 < nb && nb <= pivot_2)
			double_instruct(PB, a, b, 1);
		else
			single_instruct(RA, a, 1);
		i++;
	}
}

void	push_to_b_except_3(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		double_instruct(PB, a, b, 1);
}

int	get_zero_location(t_stack *a)
{
	t_ps_node	*node;
	int			zero_location;

	zero_location = 0;
	node = a->head;
	while (node)
	{
		if (node->nb == 0)
			break ;
		node = node -> next;
		zero_location++;
	}
	return (zero_location);
}

void	set_zero_top(t_stack *a)
{
	int	zero_location;

	zero_location = get_zero_location(a);
	if (zero_location > a->size / 2)
		zero_location = zero_location - a->size;
	while (zero_location < 0)
	{
		single_instruct(RRA, a, 1);
		zero_location++;
	}
	while (zero_location > 0)
	{
		single_instruct(RA, a, 1);
		zero_location--;
	}
}
