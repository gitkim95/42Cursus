/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:37:34 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/05 12:41:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "./libft/libft.h"

void	check_instruction(t_stack *stack)
{
	char	*get_inst;

	while (1)
	{
		get_inst = get_next_line(0);
		if (ft_strncmp(get_inst, "sa", 2))
			single_instruct(SA, stack);
		else if (ft_strncmp(get_inst, "sb", 2))
			single_instruct(SB, stack);
		else if (ft_strncmp(get_inst, "pa", 2))
		else if (ft_strncmp(get_inst, "pb", 2))
		else if (ft_strncmp(get_inst, "ra", 2))
		else if (ft_strncmp(get_inst, "rb", 2))
		else if (ft_strncmp(get_inst, "rr", 2))
		else if (ft_strncmp(get_inst, "rra", 2))
		else if (ft_strncmp(get_inst, "rrb", 2))
		else if (ft_strncmp(get_inst, "rrr", 2))
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
	if (check_asc(&stack_a))
		terminator(2, NULL, NULL, &stack_a);
	else
		check_instruction(&stack_a);
	// 표준입력 받아서 그 입력대로 명령 실행, 정렬되면 ok 아니면 ko
	// 유효하지 않은 명령이면 Error
}
