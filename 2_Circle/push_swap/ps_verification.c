/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:27:12 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/05 16:56:32 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

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
	if (!arr[idx])
		return (0);
	while (arr[idx])
	{
		if (!ft_isdigit(arr[idx])
			&& !ps_isspace(arr[idx]) && !ps_issign(arr[idx]))
			return (0);
		if (ps_issign(arr[idx]))
		{
			if (!ft_isdigit(arr[idx + 1]))
				return (0);
		}
		idx++;
	}
	return (1);
}

void	ps_isnum(int ac, char **av)
{
	int	idx;

	while (ac > 1)
	{
		idx = ac - 1;
		if (!ps_veri_val_nb(av[idx]))
			terminator(1, NULL, NULL, NULL);
		ac--;
	}
	return ;
}

void	ps_veri_same_nb(int *list, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (list[i] == list[j])
				terminator(1, list, NULL, NULL);
			j++;
		}
		i++;
	}
	return ;
}
