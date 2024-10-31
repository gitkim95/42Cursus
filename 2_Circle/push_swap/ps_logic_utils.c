/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_logic_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:53:01 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/31 20:57:42 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminator(int type, void *addr, t_stack *stack)
{
	if (type == 1)
	{
		if (addr)
			free(addr);
		if (stack)
			ps_lstfree(stack);
		ft_printf("Error\n");
		exit(1);
	}
}

void	init_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_b->size = 0;
}

int	check_asc(t_stack *a)
{
	t_ps_node	*a_node;

	a_node = a->head;
	while (a_node->next)
	{
		if (a_node->nb >= a_node->next->nb)
			return (0);
		a_node = a_node->next;
	}
	return (1);
}

long long	ps_atoll(char *arr)
{
	long long	ret;
	long long	sign;
	int			idx;

	sign = 1;
	idx = 0;
	ret = 0;
	if (arr[idx] == '+' || arr[idx] == '-')
	{
		if (arr[idx + 1] == '+' || arr[idx + 1] == '-')
			return (0);
		if (arr[idx] == '-')
			sign *= -1;
		idx++;
	}
	while ('0' <= arr[idx] && arr[idx] <= '9')
	{
		ret = ret * 10 + (arr[idx] - '0');
		idx++;
	}
	return (ret * sign);
}
