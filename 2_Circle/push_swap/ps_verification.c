/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:27:12 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/27 22:15:27 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"

int	ps_issign(char c)
{
	return (c == '-' || c == '+');
}

int	ps_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

int	ps_veri_val_nb(char *arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
	{
		if (!ft_isdigit(arr[idx])
			&& !ps_isspace(arr[idx]) && !ps_issign(arr[idx]))
			return (0);
		if (ps_issign(arr[idx]))
		{
			if (!ft_isdigit(arr[idx + 1])) // 터진다면 여기
				return (0);
		}
		idx++;
	}
	return (1);
}

int	ps_isnum(int ac, char **av)
{
	int	idx;

	while (ac > 1)
	{
		idx = ac - 1;
		if (!ps_veri_val_nb(av[idx]))
		{
			ft_printf("Error\n");
			return (0);
		}
		ac--;
	}
	return (1);
}

int	ps_veri_same_nb(t_stack *stack)
{
	t_ps_node	*node_1;
	t_ps_node	*node_2;

	node_1 = stack->head;
	while (node_1->next)
	{
		node_2 = node_1->next;
		while (node_2)
		{
			if (node_1->nb == node_2->nb)
			{
				ft_printf("Error\n");
				return (0);
			}
			node_2 = node_2->next;
		}
		node_1 = node_1->next;
	}
	return (1);
}
