/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:10:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/03 17:28:46 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_best(t_stack *a, t_stack *b, t_least_cost *cal)
{
	t_ps_node	*b_node;
	int			idx;
	int			nb;

	b_node = b->head;
	idx = 0;
	while (idx < b->size)
	{
		nb = b_node->nb;
		cal->a_location = find_a_cost(a, nb);
		if (idx > b->size / 2)
			cal->b_location = idx - b->size;
		else
			cal->b_location = idx;
		if (idx == 0 || check_least_cost(cal))
		{
			cal->a_cost = cal->a_location;
			cal->b_cost = cal->b_location;
		}
		b_node = b_node->next;
		idx++;
	}
}

void	rotate_for_push_all(t_stack *a, t_stack *b, t_least_cost *cal)
{
	while (cal->a_cost < 0 && cal->b_cost < 0)
	{
		double_instruct(RRR, a, b);
		cal->a_cost++;
		cal->b_cost++;
	}
	while (cal->a_cost > 0 && cal->b_cost > 0)
	{
		double_instruct(RR, a, b);
		cal->a_cost--;
		cal->b_cost--;
	}
}

void	rotate_for_push_a(t_stack *stack, t_least_cost *cal)
{
	while (cal->a_cost > 0)
	{
		single_instruct(RA, stack);
		cal->a_cost--;
	}
	while (cal->a_cost < 0)
	{
		single_instruct(RRA, stack);
		cal->a_cost++;
	}
}

void	rotate_for_push_b(t_stack *stack, t_least_cost *cal)
{
	while (cal->b_cost > 0)
	{
		single_instruct(RB, stack);
		cal->b_cost--;
	}
	while (cal->b_cost < 0)
	{
		single_instruct(RRB, stack);
		cal->b_cost++;
	}
}

void	greedy_algoritm(t_stack *a, t_stack *b)
{
	t_least_cost	cal;

	if (a->size > 3)
	{
		ready_to_sort(a, b);
		push_to_b_except_3(a, b);
	}
	if (a->size == 3)
		sort_a_3node(a);
	else if (a->size == 2)
		sort_a_2node(a);
	else
		return ;
	while (b->size > 0)
	{
		cal.a_cost = 0;
		cal.b_cost = 0;
		find_best(a, b, &cal);
		rotate_for_push_all(a, b, &cal);
		rotate_for_push_a(a, &cal);
		rotate_for_push_b(b, &cal);
		double_instruct(PA, a, b);
	}
	set_zero_top(a);
}
