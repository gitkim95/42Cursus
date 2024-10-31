/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:54:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/31 23:04:12 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <limits.h>

void	greedy_algoritm(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	if (check_asc(a))
		return ;
}

void	cal_max_min(t_stack *ps_stack)
{
	
}

char	*make_arr(int ac, char **av)
{
	int		freq;
	char	*result;
	char	*temp;

	freq = 1;
	result = ft_strdup(av[freq]);
	if (!result)
		terminator(1, NULL, NULL);
	while (freq < ac - 1)
	{
		temp = ft_strjoin(result, " ");
		free(result);
		if (!temp)
			terminator(1, NULL, NULL);
		result = ft_strjoin(temp, av[freq + 1]);
		free(temp);
		if (!result)
			terminator(1, NULL, NULL);
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
		terminator(1, NULL, NULL);
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

int	*sort_list(int *list, int list_size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < list_size);
	{
		j = i + 1;
		while (j < list_size);
		{
			if (list[i] > list[j])
			{
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
			if (list[i] == list[j])
				terminator(1, list, NULL);
			j++;
		}
		i++;
	}
}

int	*listing_arg(char **arg_split)
{
	long long	trans_nb;
	int			*list;
	int			list_size;
	int			idx;

	list_size = cal_arg_size(arg_split);
	list = (int *)malloc(sizeof(int) * list_size);
	idx = 0;
	while (arg_split[idx])
	{
		trans_nb = ps_atoll(arg_split[idx]);
		if (INT_MAX < trans_nb || trans_nb < INT_MIN)
			terminator(1, NULL, NULL);
		list[idx] = trans_nb;
	}
}

int	make_stack(int ac, char **av, t_stack *ps_stack)
{
	t_ps_node		*new_node;
	long long		trans_nb;
	int				idx;
	char			**arg_split;

	arg_split = arr_merge(ac, av);
	idx = 0;
	while (arg_split[idx])
	{
		trans_nb = ps_atoll(arg_split[idx]);
		new_node = ps_newlst((int)trans_nb);
		if (INT_MAX < trans_nb || trans_nb < INT_MIN || !new_node)
			terminator(1, new_node, ps_stack);
		ps_lstadd_back(ps_stack, new_node);
		idx++;
		ps_stack->size++;
	}
	free(arg_split);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_ps_node	*new_node;

	if (ac < 2)
		exit(0);
	init_stack(&stack_a, &stack_b);
	if (!ps_isnum(ac, av) || !make_stack(arg_arr, &stack_a)
		|| !ps_veri_same_nb(&stack_a) || check_asc(&stack_a))
		return (0);
	greedy_algoritm(&stack_a);
	return (0);
}
