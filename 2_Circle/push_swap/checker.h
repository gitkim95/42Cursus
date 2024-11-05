/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:37:25 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/05 14:37:01 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	check_instruction(t_stack *stack_a, t_stack *stack_b);
void	compare_inst(char *get_inst, t_stack *stack_a, t_stack *stack_b);
void	validate_inst(char *get_inst, t_stack *stack_a, t_stack *stack_b);

#endif
// 정렬이 확인 된 경우 "OK\n"출력
// 안 된 경우 "KO\n"출력
// 에러 발생 시 "Error\n"라는 메세지를 출력해야 한다.
//	- 정수가 아니거나/ integer 범위 밖이거나/ 중복이 있는 경우/ 존재하지 않는 명령어가 있는 경우