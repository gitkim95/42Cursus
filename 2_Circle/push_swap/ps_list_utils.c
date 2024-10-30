/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:00:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/30 19:58:06 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_node	*ps_newlst(int nb)
{
	t_ps_node	*newstack;

	newstack = (t_ps_node *)malloc(sizeof(t_ps_node));
	if (!newstack)
		return (NULL);
	newstack->nb = nb;
	newstack->prev = NULL;
	newstack->next = NULL;
	return (newstack);
}

void	ps_lstfree(t_stack *stack)
{
	t_ps_node	*node;
	t_ps_node	*tmp;

	node = stack->head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

t_ps_node	*ps_lstlast(t_ps_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ps_lstadd_back(t_stack *ps_stack, t_ps_node *new_node)
{
	if (!new_node)
		return ;
	if (ps_stack->head == NULL)
	{
		ps_stack->head = new_node;
		ps_stack->tail = new_node;
	}
	else
	{
		ps_stack->tail->next = new_node;
		new_node->prev = ps_stack->tail;
		ps_stack->tail = new_node;
	}
}

int	ps_lstsize(t_stack *stack)
{
	int			cnt;
	t_ps_node	*node;

	cnt = 0;
	node = stack->head;
	while (node)
	{
		cnt++;
		node = node->next;
	}
	return (cnt);
}
