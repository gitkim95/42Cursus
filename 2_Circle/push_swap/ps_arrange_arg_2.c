/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arrange_arg_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 05:20:53 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/01 14:52:30 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	find_max_val(int *list, int size)
{
	int	idx;
	int	ret;
	int	max_val;

	max_val = INT_MIN;
	idx = 0;
	while (idx < size)
	{
		if (list[idx] > max_val)
		{
			max_val = list[idx];
			ret = idx;
		}
		idx++;
	}
	list[ret] = INT_MAX;
	return (ret);
}

int	find_min_val(int *list, int size)
{
	int	idx;
	int	ret;
	int	min_val;

	min_val = INT_MAX;
	idx = 0;
	while (idx < size)
	{
		if (list[idx] < min_val)
		{
			min_val = list[idx];
			ret = idx;
		}
		idx++;
	}
	list[ret] = INT_MAX;
	return (ret);
}

int	*indexing_list(int *list, int list_size)
{
	int	*new_list;
	int	idx;
	int	freq;

	new_list = (int *)malloc(sizeof(int) * list_size);
	if (!new_list)
		terminator(1, list, NULL, NULL);
	freq = 0;
	idx = find_max_val(list, list_size);
	new_list[idx] = list_size - 1;
	while (freq < list_size - 1)
	{
		idx = find_min_val(list, list_size);
		new_list[idx] = freq;
		freq++;
	}
	free(list);
	return (new_list);
}

int	*listing_arg(char **arg_split, int list_size)
{
	long long	trans_nb;
	int			*list;
	int			idx;

	list = (int *)malloc(sizeof(int) * list_size);
	if (!list)
		terminator(1, NULL, arg_split, NULL);
	idx = 0;
	while (arg_split[idx])
	{
		trans_nb = ps_atoll(arg_split[idx], arg_split, list);
		if (INT_MAX < trans_nb || trans_nb < INT_MIN)
			terminator(1, list, arg_split, NULL);
		list[idx] = trans_nb;
	}
	free_split(arg_split);
	ps_veri_same_nb(list, list_size);
	list = indexing_list(list, list_size);
	return (list);
}
