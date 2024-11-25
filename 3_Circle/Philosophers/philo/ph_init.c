/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:42:06 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/26 00:09:40 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "philo.h"

int	ph_data_mutex_init(t_data *data)
{
	int	idx;

	if (pthread_mutex_init(&(data->print), NULL))
		return (1);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!data->fork)
		return (1);
	idx = 0;
	while (idx < data->num_of_philo)
	{
		if (pthread_mutex_init(&(data->fork[idx]), NULL))
			return (1);
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
	data->run_flag = 1;
	data->start_time = ph_get_time();
	data->fork_flag = (int *)malloc(sizeof(int) * data->num_of_philo);
	memset(data->fork_flag, 0, sizeof(int) * data->num_of_philo);
	data->times_to_eat = INT_MAX;
	if (argc == 6)
	{
		data->times_to_eat = ft_atoi(argv[5]);
		if (data->times_to_eat < 0)
			return (1);
	}
	if (data->num_of_philo <= 0 || data->time_to_die < 0 || \
		data->time_to_eat < 0 || data->time_to_sleep < 0)
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
		(*philo)[idx].id = idx;
		(*philo)[idx].left_fork = idx;
		(*philo)[idx].right_fork = (idx + 1) % data->num_of_philo;
		(*philo)[idx].last_time_eaten = ph_get_time();
		(*philo)[idx].num_of_eaten = 0;
		(*philo)[idx].dead_flag = 0;
		idx++;
	}
	return (0);
}
