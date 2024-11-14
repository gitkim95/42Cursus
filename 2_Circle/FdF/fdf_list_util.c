/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_list_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:51:14 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/14 17:52:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_map_list	*fdf_maplist_last(t_map_list *node)
{
	while (node -> next)
		node = node -> next;
	return (node);
}

void	fdf_maplist_addback(t_map_list **head, t_map_list *new_node)
{
	t_map_list	*tail;

	if (!new_node)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		tail = fdf_maplist_last(*head);
		tail -> next = new_node;
	}
}

t_map_list	*fdf_maplist_newnode(char **maplist)
{
	t_map_list	*new_node;

	new_node = (t_map_list *)malloc(sizeof(t_map_list));
	if (!new_node)
		return (NULL);
	new_node->list = maplist;
	new_node->next = NULL;
	return (new_node);
}
