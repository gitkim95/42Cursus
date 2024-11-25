/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:33:15 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/25 22:51:23 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	ph_check_flag(t_philo *philo, t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->num_of_philo)
	{
		if (philo[idx].dead_flag == 0)
			return (0);
		idx++;
	}
	return (1);
}

void	ph_check_meal(t_philo *philo, t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->num_of_philo)
	{
		if (philo[idx].num_of_eaten >= data->times_to_eat)
			philo[idx].dead_flag = 1;
		idx++;
	}
}

int	ph_check_starvation(t_philo *philo, t_data *data)
{
	long long	last_mealtime;
	long long	cur_time;
	int			idx;

	idx = 0;
	while (idx < data->num_of_philo)
	{
		last_mealtime = philo[idx].last_time_eaten;
		cur_time = ph_get_time();
		if (cur_time > last_mealtime + data->time_to_die)
		{
			philo[idx].dead_flag = 1;
			ph_print_status(data, philo[idx].id, "died");
			pthread_mutex_unlock(&data->fork[philo->left_fork]);
			data->run_flag = 0;
			return (1);
		}
		idx++;
	}
	return (0);
}

void	val_flag(t_philo **philo_pointer, t_data *data)
{
	t_philo	*philo;

	philo = *philo_pointer;
	while (data->run_flag)
	{
		if (ph_check_starvation(philo, data))
			break ;
		ph_check_meal(philo, data);
		if (ph_check_flag(philo, data))
			data->run_flag = 0;
	}
}
