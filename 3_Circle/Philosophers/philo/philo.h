/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:45:35 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/28 23:36:53 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_mutex
{
	long long		value;
	pthread_mutex_t	mtx;
}	t_mutex;

typedef struct s_data
{
	t_mutex			*fork;
	pthread_mutex_t	print;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	pthread_t		thread;
	int				ord;
	int				left_fork;
	int				right_fork;
	t_mutex			num_of_eaten;
	t_mutex			dead_flag;
	t_mutex			last_time_eaten;
}	t_philo;

//ph_check_status.c
void		set_dead_flag(t_philo **philo_pointer, t_data *data);
int			ph_check_meal(t_philo **philo_pointer, t_data *data);
int			ph_check_starvation(t_philo **philo_pointer, t_data *data);
void		val_flag(t_philo **philo, t_data *data);

//ph_handle_mutex.c
void		set_mtx_value(t_mutex *arg, long long value);
void		increase_mtx_value(t_mutex *arg);
long long	get_mtx_value(t_mutex *arg);

//ph_init.c
int			ph_philo_mutex_init(t_philo **philo, t_data *data);
int			ph_data_mutex_init(t_data *data);
int			ph_data_init(t_data *data, int argc, char *argv[]);
int			ph_philo_init(t_philo **philo, t_data *data);

//ph_task_utils.c
int			check_flags(t_philo *philo, t_data *data, int fork_num);
int			get_fork(t_philo *philo, t_data *data, int fork_num);
void		check_holding_fork(t_philo *philo, t_data *data);
void		ph_print_status(t_data *data, int ord, char *msg);

//ph_terminator.c
void		ph_destroy_mutex(t_data *data);
void		free_philo(t_philo **philo, t_data *data);
int			terminator(int flag, t_philo **philo, t_data *data, char *msg);

//ph_thread_task.c
int			ph_philo_think(t_philo *philo, t_data *data);
int			ph_philo_eat(t_philo *philo, t_data *data);
int			ph_philo_sleep(t_philo *philo, t_data *data);
void		*thread_task(void *param);

//ph_utils.c
void		wait_tasking(long long start, int wait);
long long	ph_get_time(void);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *nptr);

#endif
/*
보너스
• 모든 포크는 테이블 중앙에 놓입니다.
• 포크는 메모리에서 상태를 가지지 않음, 사용 가능한 포크의 수는 세마포어로 표시됩니다.
• 각 철학자는 하나의 프로세스, 메인 프로세스는 철학자가 되어서는 안 됩니다.
*/