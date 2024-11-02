/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:54:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/02 21:52:02 by gitkim           ###   ########.fr       */
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
	int i;
	int	size;
	int nb;
	int pivot_1;
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
			break;
		if (node->prev != NULL && node->prev->nb < b_nb && \
			node->nb > b_nb && node->prev->nb < node->nb)
			break;
		if (node->prev != NULL && node->prev->nb > b_nb && \
			node->nb > b_nb && node->prev->nb > node->nb)
			break;
		if (node->prev != NULL && node->prev->nb < b_nb && \
			node->nb < b_nb && node->prev->nb > node->nb)
			break;
		node = node->next;
		cnt++;
	}
	if (cnt > a->size / 2)
		cnt = cnt - a->size;
	return (cnt);
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
		if (idx == 0 || )
		{
			cal->a_cost = cal->a_location;
			cal->b_cost = cal->b_location;
		}
		b_node = b_node->next;
		idx++;
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
	while (!(b->size == 0 && check_asc(a)))
	{
		cal.a_cost = 0;
		cal.b_cost = 0;
		find_best(a, b, &cal);
		// rotate logic
		// cost의 값이 음수라면 rr, 양수라면 r을 돈다. 둘다 음수 혹은 양수라면 같이 굴린 후 따로 굴린다.
		double_instruct(PA, a, b);
	}
}

#include <stdio.h> // 나중에 지워야 함

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
	else // 정렬 확인, 정렬 됐다면 바로 종료, 아니면 로직 시작
		greedy_algoritm(&stack_a, &stack_b);
	// for (t_ps_node *node = stack_a.head; node ; node = node->next)
	// {
	// 	printf("a - %d\n", node->nb);
	// }
	// for (t_ps_node *node = stack_b.head; node ; node = node->next)
	// {
	// 	printf("b - %d\n", node->nb);
	// }
	ps_lstfree(&stack_a);
	return (0);
}
