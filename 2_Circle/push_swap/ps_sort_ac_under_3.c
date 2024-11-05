/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_ac_under_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:16:19 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/05 13:48:03 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		single_instruct(SA, a, 1);
		single_instruct(RA, a, 1);
	}
	else if (middle_nb < head_nb && head_nb < tail_nb)
		single_instruct(SA, a, 1);
	else if (tail_nb < head_nb && head_nb < middle_nb)
		single_instruct(RRA, a, 1);
	else if (middle_nb < tail_nb && tail_nb < head_nb)
		single_instruct(RA, a, 1);
	else if (tail_nb < middle_nb && middle_nb < head_nb)
	{
		single_instruct(SA, a, 1);
		single_instruct(RRA, a, 1);
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
		single_instruct(SA, a, 1);
}
