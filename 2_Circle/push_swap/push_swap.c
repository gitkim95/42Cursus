/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:54:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/03 04:18:20 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	push_to_b_except_3(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		double_instruct(PB, a, b);
}

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
			double_instruct(PB, a, b);
			if (b->size > 1)
				single_instruct(RB, b);
		}
		else if (pivot_1 < nb && nb <= pivot_2)
			double_instruct(PB, a, b);
		else
			single_instruct(RA, a);
		i++;
	}
}

void	sort_a_3node(t_stack *a)
{
	int	head_nb;
	int	middle_nb;
	int	tail_nb;

	head_nb = a->head->nb;
	middle_nb = a->head->next->nb;
	tail_nb = a->tail->nb;
	if (head_nb < tail_nb && tail_nb < middle_nb)
	{
		single_instruct(SA, a);
		single_instruct(RA, a);
	}
	else if (middle_nb < head_nb && head_nb < tail_nb)
		single_instruct(SA, a);
	else if (tail_nb < head_nb && head_nb < middle_nb)
		single_instruct(RRA, a);
	else if (middle_nb < tail_nb && tail_nb < head_nb)
		single_instruct(RA, a);
	else if (tail_nb < middle_nb && middle_nb < head_nb)
	{
		single_instruct(SA, a);
		single_instruct(RRA, a);
	}
	else
		return ;
}

void	sort_a_2node(t_stack *a)
{
	int	head_nb;
	int	tail_nb;

	head_nb = a->head->nb;
	tail_nb = a->tail->nb;
	if (head_nb > tail_nb)
		single_instruct(SA, a);
}

int	if_a_prev_null(t_stack *a, int b_nb)
{
	t_ps_node	*head;
	t_ps_node	*tail;

	head = a->head;
	tail = a->tail;
	if (tail->nb < b_nb && head->nb > b_nb && tail->nb < head->nb)
		return (1);
	if (tail->nb > b_nb && head->nb > b_nb && tail->nb > head->nb)
		return (1);
	if (tail->nb < b_nb && head->nb < b_nb && tail->nb > head->nb)
		return (1);
	return (0);
}

int	find_a_cost(t_stack *a, int b_nb)
{
	t_ps_node	*node;
	int			cnt;

	node = a->head;
	cnt = 0;
	while (node)
	{
		if (node->prev == NULL && if_a_prev_null(a, b_nb))
			break ;
		if (node->prev != NULL && node->prev->nb < b_nb && \
			node->nb > b_nb && node->prev->nb < node->nb)
			break ;
		if (node->prev != NULL && node->prev->nb > b_nb && \
			node->nb > b_nb && node->prev->nb > node->nb)
			break ;
		if (node->prev != NULL && node->prev->nb < b_nb && \
			node->nb < b_nb && node->prev->nb > node->nb)
			break ;
		node = node->next;
		cnt++;
	}
	if (cnt > a->size / 2)
		cnt = cnt - a->size;
	return (cnt);
}

void	set_abs_value(int a_loc, int b_loc, int a_co, int b_co)
{
	if (a_loc < 0)
		a_loc *= -1;
	if (b_loc < 0)
		b_loc *= -1;
	if (a_co < 0)
		a_co *= -1;
	if (b_co < 0)
		b_co *= -1;
}

int	check_least_cost(t_least_cost *cal)
{
	int	a_loc;
	int	b_loc;
	int	a_co;
	int	b_co;

	a_loc = cal->a_location;
	b_loc = cal->b_location;
	a_co = cal->a_cost;
	b_co = cal->b_cost;
	set_abs_value(a_loc, b_loc, a_co, b_co);
	if (a_loc + b_loc < a_co + b_co)
		return (1);
	return (0);
}

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

// int	get_zero_location(t_stack *a)
// {
	
// }

// void	set_zero_top(t_stack *a)
// {

// }

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
}
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;

	if (ac < 2)
		exit(0);
	init_stack(&stack_a, &stack_b);
	ps_isnum(ac, av);
	make_stack(ac, av, &stack_a);
	if (check_asc(&stack_a))
		return (0);
	else
		greedy_algoritm(&stack_a, &stack_b);
	for (t_ps_node *node = stack_a.head; node ; node = node->next)
	{
		printf("a - %d\n", node->nb);
	}
	for (t_ps_node *node = stack_b.head; node ; node = node->next)
	{
		printf("b - %d\n", node->nb);
	}
	ps_lstfree(&stack_a);
	return (0);
}