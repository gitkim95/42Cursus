/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:23:14 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/03 17:34:10 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (node->prev != NULL && node->prev->nb < b_nb
			&& node->nb > b_nb && node->prev->nb < node->nb)
			break ;
		if (node->prev != NULL && node->prev->nb > b_nb
			&& node->nb > b_nb && node->prev->nb > node->nb)
			break ;
		if (node->prev != NULL && node->prev->nb < b_nb
			&& node->nb < b_nb && node->prev->nb > node->nb)
			break ;
		node = node->next;
		cnt++;
	}
	if (cnt > a->size / 2)
		cnt = cnt - a->size;
	return (cnt);
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
	if (a_loc < 0)
		a_loc *= -1;
	if (b_loc < 0)
		b_loc *= -1;
	if (a_co < 0)
		a_co *= -1;
	if (b_co < 0)
		b_co *= -1;
	if (a_loc + b_loc < a_co + b_co)
		return (1);
	return (0);
}
