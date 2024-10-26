/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_logic_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:53:01 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/27 03:04:24 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_asc(t_stack **a, int size)
{
	t_stack	*head;

	head = *a;
	while (head -> next && head -> nb < head -> next -> nb)

}