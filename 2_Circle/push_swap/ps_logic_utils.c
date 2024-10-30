/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_logic_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:53:01 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/30 17:43:51 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

long	ps_atol(char *arr)
{
	long	ret;
	long	sign;
	int		idx;

	sign = 1;
	idx = 0;
	ret = 0;
	while (arr[idx] == 32 || (9 <= arr[idx] && arr[idx] <= 13))
		idx++;
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
