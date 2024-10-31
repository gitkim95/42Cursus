/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arrange_arg_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 05:20:20 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/01 06:21:43 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*make_arr(int ac, char **av)
{
	int		freq;
	char	*result;
	char	*temp;

	freq = 1;
	result = ft_strdup(av[freq]);
	if (!result)
		terminator(1, NULL, NULL, NULL);
	while (freq < ac - 1)
	{
		temp = ft_strjoin(result, " ");
		free(result);
		if (!temp)
			terminator(1, NULL, NULL, NULL);
		result = ft_strjoin(temp, av[freq + 1]);
		free(temp);
		if (!result)
			terminator(1, NULL, NULL, NULL);
		freq++;
	}
	return (result);
}

char	**arr_merge(int ac, char **av)
{
	char	*arg_arr;
	char	**arg_split;

	arg_arr = make_arr(ac, av);
	arg_split = ft_split(arg_arr, ' ');
	free(arg_arr);
	if (!arg_split)
		terminator(1, NULL, NULL, NULL);
	return (arg_split);
}

int	cal_arg_size(char **arg_split)
{
	int	idx;

	idx = 0;
	while (arg_split[idx])
		idx++;
	return (idx);
}

void	make_stack(int ac, char **av, t_stack *ps_stack)
{
	t_ps_node	*new_node;
	int			idx;
	char		**arg_split;
	int			arg_size;
	int			*arg_array;

	arg_split = arr_merge(ac, av);
	arg_size = cal_arg_size(arg_split);
	arg_array = listing_arg(arg_split, arg_size);
	idx = 0;
	while (idx < arg_size)
	{
		new_node = ps_newlst(arg_array[idx]);
		if (!new_node)
			terminator(1, arg_array, NULL, ps_stack);
		ps_lstadd_back(ps_stack, new_node);
		idx++;
		ps_stack->size++;
	}
	if (ps_stack->size != arg_size)
		terminator(1, arg_array, NULL, ps_stack);
	free(arg_array);
	return ;
}
