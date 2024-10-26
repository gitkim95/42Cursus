/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:00:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/26 23:48:00 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_newlst(int nb)
{
	t_stack	*newstack;

	newstack = (t_stack *)malloc(sizeof(t_stack));
	if (!newstack)
		return (NULL);
	newstack -> nb = nb;
	newstack -> prev = NULL;
	newstack -> next = NULL;
	return (newstack);
}

void	ps_lstfree(t_stack **lst)
{
	t_stack	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = tmp -> next;
		free(tmp);
	}
	*lst = NULL;
}

t_stack	*ps_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ps_lstadd_back(t_stack **head, t_stack *new_node)
{
	t_stack	*last_node;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = ps_lstlast(*head);
		last_node -> next = new_node;
		new_node -> prev = last_node;
	}
}

int	ps_lstsize(t_stack *node)
{
	int	cnt;

	cnt = 0;
	while (node)
	{
		node = node -> next;
		cnt++;
	}
	return (cnt);
}
