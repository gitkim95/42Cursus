/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_task_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:45:25 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/26 13:24:38 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

void	ps_swap(t_stack **stack)
{
	t_stack *first;
	t_stack	*second;

	first = *stack;
	second = first -> next;
	first -> next = second -> next;
	second -> prev = first -> prev;
	first -> prev = second;
	second -> next = first;
	first -> next -> prev = first;
	*stack = second;
}


void	ps_push(t_stack **stack)
{

}

void	ps_rotate(t_stack **stack)
{

}

void	ps_r_rotate(t_stack **stack)
{

}

void single_instruct(e_single e_inst, t_stack **stack)
{
	if (e_inst == SA || e_inst == SB)
		ps_swap(stack);
	else if (e_inst == RA || e_inst == RB)
		psr(stack);
	ft_printf("%s\n", SINGLE_NAME + e_inst);
}

void double_instruct(e_double e_inst, t_stack **stack, t_stack **stack2)
{
	if (e_inst == SS)
	{
		ps_swap(stack);
		ps_swap(stack2);
	}
	else if (e_inst == RR)
	{
		ps_rr(stack);
		ps_rr(stack2);
	}
	else if (e_inst == RRR)
	{
		ps_rrr(stack);
		ps_rrr(stack2);
	}
	ft_printf("%s\n", DOUBLE_NAME + e_inst);
}

// void	ps_sb(t_stack **b, int pf)
// {
// 	t_stack *head;
// 	t_stack	*b_2nd;

// 	head = *b;
// 	b_2nd = head -> next;
// 	head -> next = b_2nd -> next;
// 	b_2nd -> prev = head -> prev;
// 	head -> prev = b_2nd;
// 	b_2nd -> next = head;
// 	head -> next -> prev = head;
// 	*b = b_2nd;
// 	if (pf)
// 		write (1, "sb\n", 3);
// }

// void	ps_ss(t_stack **a, t_stack **b)
// {
// 	ps_sa(a, 0);
// 	ps_sb(b, 0);
// 	write (1, "ss\n", 3);
// }