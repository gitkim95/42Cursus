/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:09:40 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/02 13:04:13 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <pthread.h>

typedef struct s_sema
{
	long	value;
	sem_t	*sem;
}	t_sema;

typedef struct s_data_b
{
	sem_t		*fork;
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
	t_sema		dead_flag;
	t_sema		num_of_eaten;
	t_sema		last_time_eaten;
	int			ord;
	int			hold;
}	t_philo_b;

//ph_check_status_bonus.c
int		ph_check_meal_b(t_philo_b *philo, t_data_b *data);
int		ph_check_starvation_b(t_philo_b *philo, t_data_b *data);
int		val_flag_b(t_philo_b *philo, t_data_b *data);

//ph_handle_sem.c
long	get_sem_value(t_sema *sem);
void	set_sem_value_1(t_sema *sem);
void	set_sem_value_2(t_sema *sem, long value);

//ph_init_bonus.c
void	ph_make_named_sem(t_philo_b **philo, t_sema *sem, char *name);
void	ph_set_sem_philo(t_philo_b **philo_p, t_data_b *data);
void	ph_philo_init_b(t_philo_b **philo, t_data_b *data);
void	ph_set_sem_data(t_philo_b **philo, t_data_b *data);
void	ph_data_init_b(t_philo_b **philo, t_data_b *data, int ac, char **av);

//ph_task_utils_bonus.c
int		get_fork_b(t_philo_b *philo, t_data_b *data);
void	ph_print_status_b(t_data_b *data, int ord, char *msg);
void	wait_tasking_b(long long start, int wait);
long	ph_get_time_b(void);

//ph_terminator_bonus.c
void	unlink_sem(int nop);
void	close_sem(t_philo_b **philo, t_data_b *data, int flag);
void	terminator_b(int flag, pid_t *pid, char *msg);

//ph_thread_task_bonus.c
int		ph_philo_think_b(t_philo_b *philo, t_data_b *data);
int		ph_philo_eat_b(t_philo_b *philo, t_data_b *data);
int		ph_philo_sleep_b(t_philo_b *philo, t_data_b *data);
void	*thread_task_b(void *param);

//ph_utils_bonus.c
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);

#endif

// 자식프로세스의 자식스레드에서 작업, 메인스레드에서 확인을 거친다.
// 이후 자식스레드를 종료시키는 플래그를 삽입
// 그걸 join으로 자원 회수, free 후 종료한다.