/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_task_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:45:25 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/26 17:39:38 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

void	ps_swap(t_stack **stack)
{
	t_stack	*first;
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
	t_stack	*src_head;
	t_stack	*dst_head;

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
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = *stack;
	second = first -> next;
	last = ps_lstlast(*stack);
	second -> prev = NULL;
	first -> prev = last;
	first -> next = NULL;
	last -> next = first;
	*stack = second;
}

void	ps_r_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = ps_lstlast(*stack);
	last -> prev -> next = NULL;
	last -> prev = NULL;
	last -> next = first;
	first -> prev = last;
	*stack = last;
}
