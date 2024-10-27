/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_logic_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:53:01 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/27 23:14:30 by gitkim           ###   ########.fr       */
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

}
