/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:17:06 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/03 21:42:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*new_list;
	t_list	**lst_pnt;
	t_list	*tmp;

	new_list = NULL;
	lst_pnt = &new_list;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst -> content));
		if (tmp == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		*lst_pnt = tmp;
		lst_pnt = &tmp -> next;
		lst = lst -> next;
	}
	return (new_list);
}
