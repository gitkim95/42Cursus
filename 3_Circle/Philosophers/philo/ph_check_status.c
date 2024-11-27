/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:33:15 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/27 23:14:55 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

void	check_holding_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&(data->ff_mutex[philo->right_fork]));
	if (data->fork_flag[philo->right_fork] == philo->right_fork)
	{
		pthread_mutex_unlock(&data->fork[philo->right_fork]);
		data->fork_flag[philo->right_fork] = 0;
	}
	pthread_mutex_unlock(&(data->ff_mutex[philo->right_fork]));
	pthread_mutex_lock(&(data->ff_mutex[philo->left_fork]));
	if (data->fork_flag[philo->left_fork] == philo->left_fork)
	{
		pthread_mutex_unlock(&data->fork[philo->left_fork]);
		data->fork_flag[philo->left_fork] = 0;
	}
	pthread_mutex_unlock(&(data->ff_mutex[philo->left_fork]));
}

void	set_dead_flag(t_philo **philo_pointer, t_data *data)
{
	int		idx;
	t_philo	*philo;

	philo = *philo_pointer;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		pthread_mutex_lock(&(philo[idx].df_mutex));
		philo[idx].dead_flag = 1;
		pthread_mutex_unlock(&(philo[idx].df_mutex));
		idx++;
	}
}

int	ph_check_meal(t_philo **philo_pointer, t_data *data)
{
	int		idx;
	t_philo	*philo;

	philo = *philo_pointer;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		if (philo[idx].num_of_eaten < data->times_to_eat)
			return (0);
		idx++;
	}
	return (1);
}

int	ph_check_starvation(t_philo **philo_pointer, t_data *data)
{
	long long	starve_time;
	long long	cur_time;
	int			idx;
	t_philo	*philo;

	philo = *philo_pointer;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		starve_time = philo[idx].last_time_eaten + data->time_to_die;
		cur_time = ph_get_time();
		if (cur_time > starve_time)
		{
			pthread_mutex_lock(&(philo[idx].df_mutex));
			philo[idx].dead_flag = 1;
			pthread_mutex_unlock(&(philo[idx].df_mutex));
			ph_print_status(data, philo[idx].id, "died");
			return (1);
		}
		idx++;
	}
	return (0);
}

void	val_flag(t_philo **philo, t_data *data)
{
	while (1)
	{
		if (ph_check_starvation(philo, data) || ph_check_meal(philo, data))
		{
			set_dead_flag(philo, data);
			break ;
		}
	}
}
