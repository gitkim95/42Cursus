/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:54:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/02 01:45:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

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
	while (a->size > 3)
		double_instruct(PB, a, b);
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

void	cal_rotate_freq(t_stack *a, t_stack *b, int *a_r, int *b_r)
{
	t_ps_node	*b_head;
	int			idx;
	int			nb;

	b_head = b->head;
	idx = 0;
	while (idx < b->size)
	{
		nb = b_head->nb;

	}

}

void	greedy_algoritm(t_stack *a, t_stack *b)
{
	int	a_r;
	int	b_r;

	if (a->size > 3)
		ready_to_sort(a, b);
	if (a->size == 3)
		sort_a_3node(a);
	else if (a->size == 2)
		sort_a_2node(a);
	else
		return ;
	while (!(b->size == 0 && check_asc(a)))
	{
		a_r = 0;
		b_r = 0;
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

	return (0);
}
