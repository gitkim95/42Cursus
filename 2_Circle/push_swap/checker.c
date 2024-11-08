/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:37:34 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/08 21:30:48 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "./libft/libft.h"

void	validate_inst(char *get_inst, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(get_inst, "sa\n", 3) || !ft_strncmp(get_inst, "sb\n", 3) || \
		!ft_strncmp(get_inst, "ss\n", 3) || !ft_strncmp(get_inst, "pa\n", 3) || \
		!ft_strncmp(get_inst, "pb\n", 3) || !ft_strncmp(get_inst, "ra\n", 3) || \
		!ft_strncmp(get_inst, "rb\n", 3) || !ft_strncmp(get_inst, "rr\n", 3) || \
		!ft_strncmp(get_inst, "rra\n", 4) || !ft_strncmp(get_inst, "rrb\n", 4) || \
		!ft_strncmp(get_inst, "rrr\n", 4))
		return ;
	else
	{
		if (stack_b->head)
			ps_lstfree(stack_b);
		terminator(1, get_inst, NULL, stack_a);
	}
}

void	compare_inst(char *get_inst, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(get_inst, "sa\n", 3))
		single_instruct(SA, stack_a, 0);
	else if (!ft_strncmp(get_inst, "sb\n", 3))
		single_instruct(SB, stack_b, 0);
	else if (!ft_strncmp(get_inst, "ss\n", 3))
		double_instruct(SS, stack_a, stack_b, 0);
	else if (!ft_strncmp(get_inst, "pa\n", 3))
		double_instruct(PA, stack_a, stack_b, 0);
	else if (!ft_strncmp(get_inst, "pb\n", 3))
		double_instruct(PB, stack_a, stack_b, 0);
	else if (!ft_strncmp(get_inst, "ra\n", 3))
		single_instruct(RA, stack_a, 0);
	else if (!ft_strncmp(get_inst, "rb\n", 3))
		single_instruct(RB, stack_b, 0);
	else if (!ft_strncmp(get_inst, "rr\n", 3))
		double_instruct(RR, stack_a, stack_b, 0);
	else if (!ft_strncmp(get_inst, "rra\n", 4))
		single_instruct(RRA, stack_a, 0);
	else if (!ft_strncmp(get_inst, "rrb\n", 4))
		single_instruct(RRB, stack_b, 0);
	else if (!ft_strncmp(get_inst, "rrr\n", 4))
		double_instruct(RRR, stack_a, stack_b, 0);
}

void	check_instruction(t_stack *stack_a, t_stack *stack_b)
{
	char	*get_inst;
	int		total_size;

	total_size = stack_a->size;
	get_inst = ft_strdup("");
	if (!get_inst)
		terminator(1, NULL, NULL, stack_a);
	while (1)
	{
		free(get_inst);
		get_inst = get_next_line(0);
		if (!get_inst)
			break ;
		validate_inst(get_inst, stack_a, stack_b);
		compare_inst(get_inst, stack_a, stack_b);
	}
	if (check_asc(stack_a) && !stack_b->size && stack_a->size == total_size)
		terminator(0, get_inst, NULL, stack_a);
	else
	{
		if (stack_b->head)
			ps_lstfree(stack_b);
		terminator(2, get_inst, NULL, stack_a);
	}
}

int	main(int ac, char *av[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		exit(0);
	init_stack(&stack_a, &stack_b);
	ps_isnum(ac, av);
	make_stack(ac, av, &stack_a);
	check_instruction(&stack_a, &stack_b);
	return (0);
}
