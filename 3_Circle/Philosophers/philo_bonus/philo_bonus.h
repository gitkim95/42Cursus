/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:09:40 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/30 23:12:41 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <pthread.h>

typedef struct s_sema
{
	long		value;
	sem_t		*sem;
}	t_sema;

typedef struct s_data_b
{
	t_sema		*fork;
	pid_t		*pid;
	sem_t		*print;
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_to_eat;
}	t_data_b;

typedef struct s_philo_b
{
	t_data_b	*data;
	pthread_t	thread;
	int			ord;
	int			left_fork;
	int			right_fork;
	t_sema		num_of_eaten;
	t_sema		dead_flag;
	t_sema		lt_eaten;
}	t_philo_b;

//ph_check_status_bonus.c
void	set_dead_flag_b(t_philo_b **philo_pointer, t_data_b *data);
int		ph_check_meal_b(t_philo_b **philo_pointer, t_data_b *data);
int		ph_check_starvation_b(t_philo_b **philo_pointer, t_data_b *data);
void	val_flag_b(t_philo_b **philo, t_data_b *data);

//ph_handle_sem_bonus.c
void	set_sem_value(t_sema *arg, long value);
void	increase_sem_value(t_sema *arg);
long	get_sem_value(t_sema *arg);

//ph_init_bonus.c
void	ph_philo_sem_open(t_philo_b **philo_p, t_data_b *data);
void	ph_philo_init_b(t_philo_b **philo, t_data_b *data);
void	ph_alloc_data(t_data_b *data);
void	ph_data_init_b(t_data_b *data, int argc, char *argv[]);

//ph_task_utils_bonus.c
int		check_flags_b(t_philo_b *philo, t_data_b *data, int fork_num);
int		get_fork_b(t_philo_b *philo, t_data_b *data, int fork_num);
void	check_holding_fork_b(t_philo_b *philo, t_data_b *data);
void	ph_print_status_b(t_data_b *data, int ord, char *msg);

//ph_terminator_bonus.c
void	ph_delete_sem(t_sema *sem, char flag, int idx);
void	free_philo_b(t_philo_b **philo, t_data_b *data);
void	free_data_b(t_data_b *data);
void	terminator_b(int flag, t_philo_b **philo, t_data_b *data, char *msg);

//ph_thread_task_bonus.c
int		ph_philo_think_b(t_philo_b *philo, t_data_b *data);
int		ph_philo_eat_b(t_philo_b *philo, t_data_b *data);
int		ph_philo_sleep_b(t_philo_b *philo, t_data_b *data);
void	*th_work(void *param);

//ph_utils_bonus.c
void	wait_tasking_b(long long start, int wait);
long	ph_get_time_b(void);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);

#endif