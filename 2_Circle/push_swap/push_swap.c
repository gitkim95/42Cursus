/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:54:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/28 05:48:50 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./Libft/libft.h"
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

int	make_stack(int ac, char **av, t_stack *ps_stack)
{
	t_ps_node	*new_node;
	long		trans_nb;
	int			arg_size;

	arg_size = 1;
	while (arg_size < ac)
	{
		trans_nb = ps_atol(av[arg_size]);
		new_node = ps_newlst((int)trans_nb);
		if (!new_node || INT_MAX < trans_nb || trans_nb < INT_MIN)
		{
			ps_lstfree(ps_stack);
			ft_printf("Error\n");
			return (0);
		}
		ps_lstadd_back(ps_stack, new_node);
		arg_size++;
		ps_stack->size++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_ps_node	*new_node;

	stack_a = (t_stack){0, NULL, NULL};
	stack_b = (t_stack){0, NULL, NULL};
	if (!ps_isnum(ac, av))
		return (0);
	if (!make_stack(ac, av, &stack_a))
		return (0);
	if (!ps_veri_same_nb(&stack_a))
		return (0);
	return (0);
}
