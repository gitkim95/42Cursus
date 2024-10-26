/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_task_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:45:25 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/26 14:58:46 by gitkim           ###   ########.fr       */
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


void	ps_push(t_stack **dst, t_stack **src)
{
	t_stack *src_head;
	t_stack *dst_head;

	src_head = *src;
	dst_head = *dst;
	src_head -> next -> prev = NULL;
	*src = src_head -> next;
	src_head -> next = dst_head;
	dst_head -> prev = src_head;
	*dst = src_head;
}

void	ps_rotate(t_stack **stack)
{
	t_stack	tmp;
}

void	ps_r_rotate(t_stack **stack)
{

}

void single_instruct(e_single e_inst, t_stack **stack)
{
	if (e_inst == SA || e_inst == SB)
		ps_swap(stack);
	else if (e_inst == RA || e_inst == RB)
		ps_rotate(stack);
	else if (e_inst == RRA || e_inst == RRB)
		ps_r_rotate(stack);
	ft_printf("%s\n", SINGLE_NAME + e_inst);
}

void double_instruct(e_double e_inst, t_stack **a, t_stack **b)
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