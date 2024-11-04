/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:37:34 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/05 01:00:11 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// void	checker_output(int type, void *)
// {

// }

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
	{
	}
	// 표준입력 받아서 그 입력대로 명령 실행, 정렬되면 ok 아니면 ko
	// 유효하지 않은 명령이면 Error
}
