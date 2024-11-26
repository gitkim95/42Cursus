/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:33:15 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/26 20:09:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

void	check_holding_fork(t_philo *philo, t_data *data)
{
	if (data->fork_flag[philo->left_fork] == philo->left_fork)
	{
		pthread_mutex_unlock(&data->fork[philo->left_fork]);
		data->fork_flag[philo->left_fork] = 0;
	}
	if (data->fork_flag[philo->right_fork] == philo->right_fork)
	{
		pthread_mutex_unlock(&data->fork[philo->right_fork]);
		data->fork_flag[philo->right_fork] = 0;
	}
}

void	set_dead_flag(t_philo **philo_pointer, t_data *data)
{
	int		idx;
	t_philo	*philo;

	philo = *philo_pointer;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		philo[idx].dead_flag = 1;
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
	long long	last_mealtime;
	long long	cur_time;
	int			idx;
	t_philo	*philo;

	philo = *philo_pointer;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		last_mealtime = philo[idx].last_time_eaten;
		cur_time = ph_get_time();
		if (cur_time > last_mealtime + data->time_to_die)
		{
			philo[idx].dead_flag = 1;
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
