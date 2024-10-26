/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_task_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:28:32 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/26 17:41:10 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	single_instruct(t_single e_inst, t_stack **stack)
{
	if (e_inst == SA || e_inst == SB)
		ps_swap(stack);
	else if (e_inst == RA || e_inst == RB)
		ps_rotate(stack);
	else if (e_inst == RRA || e_inst == RRB)
		ps_r_rotate(stack);
	ft_printf("%s\n", SINGLE_NAME + e_inst);
}

void	double_instruct(t_double e_inst, t_stack **a, t_stack **b)
{
	if (e_inst == SS)
	{
		ps_swap(a);
		ps_swap(b);
	}
	else if (e_inst == PA)
		ps_push(a, b);
	else if (e_inst == PB)
		ps_push(b, a);
	else if (e_inst == RR)
	{
		ps_rotate(a);
		ps_rotate(b);
	}
	else if (e_inst == RRR)
	{
		ps_r_rotate(a);
		ps_r_rotate(b);
	}
	ft_printf("%s\n", DOUBLE_NAME + e_inst);
}
