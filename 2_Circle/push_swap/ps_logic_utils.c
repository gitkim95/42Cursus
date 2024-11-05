/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_logic_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:53:01 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/05 12:00:43 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	terminator(int type, void *addr_1, char **addr_2, t_stack *stack)
{
	if (addr_1)
		free(addr_1);
	if (addr_2)
		free_split(addr_2);
	if (stack)
		ps_lstfree(stack);
	if (type == 0)
	{
		ft_putendl_fd("OK", 1);
		exit(0);
	}
	if (type == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	if (type == 2)
	{
		ft_putendl_fd("KO", 2);
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
	while (a_node && a_node->next)
	{
		if (a_node->nb >= a_node->next->nb)
			return (0);
		a_node = a_node->next;
	}
	return (1);
}

long long	ps_atoll(char *arr, char **arg_split, int *list)
{
	long long	ret;
	long long	sign;
	int			idx;

	sign = 1;
	idx = 0;
	ret = 0;
	if (arr[idx] == '+' || arr[idx] == '-')
	{
		if (arr[idx] == '-')
			sign *= -1;
		idx++;
	}
	if (!('0' <= arr[idx] && arr[idx] <= '9'))
		terminator(1, list, arg_split, NULL);
	while ('0' <= arr[idx] && arr[idx] <= '9')
	{
		ret = ret * 10 + (arr[idx] - '0');
		idx++;
	}
	if (arr[idx])
		terminator(1, list, arg_split, NULL);
	return (ret * sign);
}
