/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_thread_task.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:27:15 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/28 19:19:20 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include "philo.h"

void	set_mtx_value(t_mutex *arg, long long value)
{
	pthread_mutex_lock(&(arg->mtx));
	arg->value = value;
	pthread_mutex_unlock(&(arg->mtx));
}

long long	get_mtx_value(t_mutex *arg)
{
	long long	value;

	pthread_mutex_lock(&(arg->mtx));
	value = arg->value;
	pthread_mutex_unlock(&(arg->mtx));
	return (value);
}

int	check_flags(t_philo *philo, t_data *data, int fork_num)
{
	int	ret;

	ret = 0;
	if (!get_mtx_value(&(data->fork[fork_num])) && \
		!get_mtx_value(&philo->dead_flag))
		ret++;
	else if (get_mtx_value(&philo->dead_flag))
		ret--;
	return (ret);
}

int	get_fork(t_philo *philo, t_data *data, int fork_num)
{
	int	able_get;

	while (1)
	{
		able_get = check_flags(philo, data, fork_num);
		if (able_get > 0)
			break ;
		else if (able_get == 0)
		{
			usleep(10);
			continue ;
		}
		else
			return (0);
	}
	set_mtx_value(&(data->fork[fork_num]), philo->ord + 1);
	ph_print_status(data, philo->ord, "has taken a fork");
	return (1);
}

int	ph_philo_think(t_philo *philo, t_data *data)
{
	if (get_mtx_value(&philo->num_of_eaten))
		ph_print_status(data, philo->ord, "is thinking");
	if (!get_fork(philo, data, philo->left_fork))
		return (0);
	if (!get_fork(philo, data, philo->right_fork))
		return (0);
	return (1);
}

int	ph_philo_eat(t_philo *philo, t_data *data)
{
	if (get_mtx_value(&(philo->dead_flag)))
		return (0);
	set_mtx_value(&(philo->last_time_eaten), ph_get_time());
	ph_print_status(data, philo->ord, "is eating");
	wait_tasking(ph_get_time(), data->time_to_eat); // ttd, tte, tts 중복??
	set_mtx_value(&(philo->num_of_eaten), )
	philo->num_of_eaten++;
	pthread_mutex_unlock(&(data->fork[philo->right_fork]));
	pthread_mutex_lock(&(data->ff_mutex[philo->right_fork]));
	data->fork_flag[philo->right_fork] = 0;
	pthread_mutex_unlock(&(data->ff_mutex[philo->right_fork]));
	pthread_mutex_unlock(&(data->fork[philo->left_fork]));
	pthread_mutex_lock(&(data->ff_mutex[philo->left_fork]));
	data->fork_flag[philo->left_fork] = 0;
	pthread_mutex_unlock(&(data->ff_mutex[philo->left_fork]));
	return (1);
}

int	ph_philo_sleep(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&(philo->df_mutex));
	if (philo->dead_flag == 1)
		return (0);
	pthread_mutex_unlock(&(philo->df_mutex));
	ph_print_status(data, philo->ord, "is sleeping");
	wait_tasking(ph_get_time(), data->time_to_sleep);
	return (1);
}

void	*thread_task(void *param)
{
	t_philo	*philo;
	t_data	*data;

	philo = param;
	data = philo->data;
	if (philo->ord % 2)
		usleep(500);
	while (1)
	{
		if (!ph_philo_think(philo, data))
			break ;
		if (!ph_philo_eat(philo, data))
			break ;
		if (!ph_philo_sleep(philo, data))
			break ;
		usleep(10);
	}
	check_holding_fork(philo, data);
	return (NULL);
}
