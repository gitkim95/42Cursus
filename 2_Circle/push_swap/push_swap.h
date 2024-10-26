/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:55:09 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/26 18:02:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // malloc, free, exit
# include <unistd.h> // read, write

typedef struct s_stack
{
	int				nb;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef enum e_single
{
	SA = 0,
	SB = 3,
	RA = 6,
	RB = 9,
	RRA = 12,
	RRB = 16
}	t_single;

typedef enum e_double
{
	SS = 0,
	PA = 3,
	PB = 6,
	RR = 9,
	RRR = 12
}	t_double;

# define SINGLE_NAME "sa\0sb\0ra\0rb\0rra\0rrb"
# define DOUBLE_NAME "ss\0pa\0pb\0rr\0rrr"
//ps_list_utils.c
t_stack	*ps_newlst(int nb);
void	ps_lstfree(t_stack **lst);
t_stack	*ps_lstlast(t_stack *lst);
void	ps_lstadd_back(t_stack **head, t_stack *tail);

//ps_task_func.c
void	ps_swap(t_stack **stack);
void	ps_push(t_stack **dst, t_stack **src);
void	ps_rotate(t_stack **stack);
void	ps_r_rotate(t_stack **stack);

//ps_task_parsing.c
void	single_instruct(t_single e_inst, t_stack **stack);
void	double_instruct(t_double e_inst, t_stack **a, t_stack **b);

#endif

// typedef struct s_ps_node
// {
// 	int	nb;
// 	struct s_stack_node	*next;
// }	t_ps_node;

// typedef struct s_stack
// {
// 	int	size;
// 	t_stack_node	*head;
// 	t_stack_node	*tail;
// }	t_stack;

//Libft 사용 가능
//기수정렬 추천
//Makefile 작성
/*
넌 a와 b라는 이름을 가진 스택을 가진다.
a에는 복제 불가한 무작위 양의 음수/ 양수가 포함되어 있다.
b는 비어있다.

스택 a에 숫자를 오름차순 정렬한다.

sa - a의 맨 위 요소 둘을 교환, 요소가 두개 미만이면 작업 하지 않음
sb - b ,,
ss - sa와 sb를 동시에 수행
pa - b의 맨 위에 있는 요소를 a의 맨 위에 놓는다. b가 비면 작업 하지 않음
pb - a ,,
ra - a의 모든 요소를 한 칸 위로 이동, 첫 번째 요소가 마지막 요소가 된다.
rb - b ,,
rr - ra와 rb를 동시에 수행
rra - ra의 reverse
rrb - rb ,,
rrr - rra와 rrb를 동시에 수행
*/

// 전역변수 금지
// Makefile로 컴파일
// 스택 a는 int형식 배열 모양으로 인수로 들어온다. 첫 번째 인자는 스택의 맨 위에 있어야 한다.
// 결과적으로 가장 작은 숫자가 맨 위에 있어야 한다.
// 명령어는 '\n'으로 구분되어야 하며 그 외 다른 구분자는 없어야 한다.
// 정렬이 안 되거나 효율이 후지면 0점
// 매개변수가 지정되지 않은 경우 프로그램은 출력하지 않고 다시 프롬프트를 보여야 한다.
// 에러 발생 시 "Error\n"라는 메세지를 출력해야 한다.
//	- 정수가 아니거나/ integer 범위 밖이거나/ 중복이 있는 경우
// 100개의 무작위 숫자를 700개 미만의 작업으로 수행해야 함.
// 500개 ,, 5500개 미만 ,,

// 비트연산, 기수정렬, min or max값 저장, 음수/양수 갯수 세어놓기

// 뽀나스
// checker 프로그램 작성
// Make bonus 규칙 추가, 프로그램명 checker
// 정렬이 확인 된 경우 "OK\n"출력
// 안 된 경우 "KO\n"출력
// 에러 발생 시 "Error\n"라는 메세지를 출력해야 한다.
//	- 정수가 아니거나/ integer 범위 밖이거나/ 중복이 있는 경우/ 존재하지 않는 명령어가 있는 경우