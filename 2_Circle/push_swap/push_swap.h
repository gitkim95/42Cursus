/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:55:09 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/05 12:41:21 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_ps_node
{
	int					nb;
	struct s_ps_node	*prev;
	struct s_ps_node	*next;
}	t_ps_node;

typedef struct s_stack
{
	int			size;
	t_ps_node	*head;
	t_ps_node	*tail;
}	t_stack;

typedef struct s_least_cost
{
	int	a_location;
	int	b_location;
	int	a_cost;
	int	b_cost;
}	t_least_cost;

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
//ps_arrange_arg_1.c
char		*make_arr(int ac, char **av);
char		**arr_merge(int ac, char **av);
int			cal_arg_size(char **arg_split);
void		make_stack(int ac, char **av, t_stack *ps_stack);

//ps_arrange_arg_2.c
void		free_split(char **split);
int			find_max_val(int *list, int size);
int			find_min_val(int *list, int size);
int			*indexing_list(int *list, int list_size);
int			*listing_arg(char **arg_split, int list_size);

//ps_greedy_logic.c
void		find_best(t_stack *a, t_stack *b, t_least_cost *cal);
void		rotate_for_push_all(t_stack *a, t_stack *b, t_least_cost *cal);
void		rotate_for_push_a(t_stack *stack, t_least_cost *cal);
void		rotate_for_push_b(t_stack *stack, t_least_cost *cal);
void		greedy_algoritm(t_stack *a, t_stack *b);

//ps_greedy_utils_1.c
void		ready_to_sort(t_stack *a, t_stack *b);
void		push_to_b_except_3(t_stack *a, t_stack *b);
void		set_zero_top(t_stack *a);

//ps_greedy_utils_2.c
int			if_a_prev_null(t_stack *a, int b_nb);
int			find_a_cost(t_stack *a, int b_nb);
void		set_abs_value(int *a_loc, int *b_loc, int *a_co, int *b_co);
int			check_least_cost(t_least_cost *cal);

//ps_list_utils.c
t_ps_node	*ps_newlst(int nb);
void		ps_lstfree(t_stack *stack);
t_ps_node	*ps_lstlast(t_ps_node *lst);
void		ps_lstadd_back(t_stack *ps_stack, t_ps_node *new_node);

//ps_logic_utils.c
void		terminator(int type, void *addr_1, char **addr_2, t_stack *stack);
void		init_stack(t_stack *stack_a, t_stack *stack_b);
int			check_asc(t_stack *a);
long long	ps_atoll(char *arr, char **arg_split, int *list);

//ps_sort_ac_under_3.c
void		sort_a_3node(t_stack *a);
void		sort_a_2node(t_stack *a);

//ps_task_func.c
void		ps_swap(t_stack *stack);
void		ps_push(t_stack *dst, t_stack *src);
void		ps_rotate(t_stack *stack);
void		ps_r_rotate(t_stack *stack);

//ps_task_parsing.c
void		single_instruct(t_single e_inst, t_stack *stack);
void		double_instruct(t_double e_inst, t_stack *a, t_stack *b);

//ps_verification.c
void		ps_isnum(int ac, char **av);
void		ps_veri_same_nb(int *list, int size);

#endif