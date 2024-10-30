/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:54:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/30 23:17:28 by gitkim           ###   ########.fr       */
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

char	*make_a_argarr(int ac, char **av)
{
	int		freq;
	char	*result;
	char	*temp;

	freq = 1;
	result = ft_strdup(av[freq]);
	if (!result)
		return (NULL);
	while (freq < ac - 1)
	{
		temp = ft_strjoin(result, " ");
		if (!temp)
			return (NULL);
		free(result);
		result = ft_strjoin(temp, av[freq + 1]);
		free(temp);
		if (!result)
			return (NULL);
		freq++;
	}
	return (result);
}

char	**arr_merge(int ac, char **av)
{

}
//배열로 쓰까놓고 스플릿한걸 make stack에 넘겨서 쓰자.. 

int	make_stack(int ac, char **av, t_stack *ps_stack)
{
	t_ps_node		*new_node;
	long long		trans_nb;
	int				idx;
	char			*arg_arr;
	char			**arg_split;

	arg_arr = arg_merge(ac, av);
	if (!arg_arr)
		return (0);
	arg_split = ft_split(arg_arr, ' ');
	free(arg_arr);
	if (!arg_split)
		return (0);
	idx = 0;
	while (arg_split[idx])
	{
		trans_nb = ps_atoll(arg_split[idx]);
		new_node = ps_newlst((int)trans_nb);
		if (INT_MAX < trans_nb || trans_nb < INT_MIN || !new_node)
		{
			if (new_node)
				free(new_node);
			ps_lstfree(ps_stack);
			ft_printf("Error\n");
			return (0);
		}
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
