/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_task_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:45:25 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/03 04:17:30 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	ps_swap(t_stack *stack)
{
	t_ps_node	*first;
	t_ps_node	*second;

	first = stack->head;
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	if (stack->size > 2)
		first->next->prev = first;
	stack->head = second;
}

void	ps_push(t_stack *dst, t_stack *src)
{
	t_ps_node	*src_head;
	t_ps_node	*dst_head;

	src_head = src->head;
	dst_head = dst->head;
	src->head = src_head->next;
	if (src->size == 1)
		src->tail = NULL;
	else
		src->head->prev = NULL;
	src_head->next = dst_head;
	if (dst->size > 0)
		dst_head->prev = src_head;
	dst->head = src_head;
	if (dst->size == 0)
		dst->tail = dst->head;
	dst->size += 1;
	src->size -= 1;
}

void	ps_rotate(t_stack *stack)
{
	t_ps_node	*first;
	t_ps_node	*second;
	t_ps_node	*last;

	first = stack->head;
	second = first->next;
	last = stack->tail;
	second->prev = NULL;
	first->prev = last;
	first->next = NULL;
	last->next = first;
	stack->head = second;
	stack->tail = first;
}

void	ps_r_rotate(t_stack *stack)
{
	t_ps_node	*first;
	t_ps_node	*last;
	t_ps_node	*last_prev;

	first = stack->head;
	last = stack->tail;
	last_prev = last->prev;
	last_prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->head = last;
	stack->tail = last_prev;
}
