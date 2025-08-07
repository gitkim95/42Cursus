/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:42:06 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/28 13:05:46 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "philo.h"

int	ph_philo_mutex_init(t_philo **philo, t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->num_of_philo)
	{
		if (pthread_mutex_init(&(*philo)[idx].num_of_eaten.mtx, NULL))
			return (1);
		if (pthread_mutex_init(&(*philo)[idx].dead_flag.mtx, NULL))
			return (1);
		if (pthread_mutex_init(&(*philo)[idx].last_time_eaten.mtx, NULL))
			return (1);
		idx++;
	}
	return (0);
}

int	ph_data_mutex_init(t_data *data)
{
	int	idx;

	if (pthread_mutex_init(&(data->print), NULL))
		return (1);
	data->fork = (t_mutex *)malloc(sizeof(t_mutex) * data->num_of_philo);
	if (!data->fork)
		return (1);
	idx = 0;
	while (idx < data->num_of_philo)
	{
		if (pthread_mutex_init(&(data->fork[idx].mtx), NULL))
			return (1);
		data->fork[idx].value = 0;
		idx++;
	}
	return (0);
}

int	ph_data_init(t_data *data, int argc, char *argv[])
{
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->times_to_eat = INT_MAX;
	if (argc == 6)
	{
		data->times_to_eat = ft_atoi(argv[5]);
		if (data->times_to_eat < 0)
			return (1);
	}
	if (data->num_of_philo <= 0 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (1);
	if (ph_data_mutex_init(data))
		return (1);
	return (0);
}

int	ph_philo_init(t_philo **philo, t_data *data)
{
	int	idx;

	*philo = malloc(sizeof(t_philo) * data->num_of_philo);
	if (!(*philo))
		return (1);
	idx = 0;
	while (idx < data->num_of_philo)
	{
		(*philo)[idx].data = data;
		(*philo)[idx].ord = idx;
		(*philo)[idx].left_fork = idx;
		(*philo)[idx].right_fork = (idx + 1) % data->num_of_philo;
		(*philo)[idx].num_of_eaten.value = 0;
		(*philo)[idx].dead_flag.value = 0;
		(*philo)[idx].last_time_eaten.value = ph_get_time();
		idx++;
	}
	if (ph_philo_mutex_init(philo, data))
		return (1);
	return (0);
}
