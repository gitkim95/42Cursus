/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:54:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/01 06:28:50 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <limits.h>

void	greedy_algoritm(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	if (check_asc(a))
		return ;
}

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_ps_node	*new_node;

	if (ac < 2)
		exit(0);
	init_stack(&stack_a, &stack_b);
	ps_isnum(ac, av);
	make_stack(ac, av, &stack_a);
	if (check_asc(&stack_a))
		return (0);
	else
	{
		greedy_algoritm(&stack_a);
		// 정렬 확인, 정렬 됐다면 바로 종료, 아니면 로직 시작
	}
	return (0);
}
