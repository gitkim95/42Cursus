/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:54:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/01 18:37:45 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <limits.h>

void	push_b_except_3(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		double_instruct(PB, a, b);
	}
}

void	greedy_algoritm(t_stack *a, t_stack *b)
{
	push_b_except_3(a, b);
	while (b->size > 0)
	{
	
		if (b->size == 0 && check_asc(a))
			return ;
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

	return (0);
}
	// for (t_ps_node *node = stack_a.head; node ; node = node->next)
	// {
	// 	printf("a - %d\n", node->nb);
	// }
	// for (t_ps_node *node = stack_b.head; node ; node = node->next)
	// {
	// 	printf("b - %d\n", node->nb);
	// }
