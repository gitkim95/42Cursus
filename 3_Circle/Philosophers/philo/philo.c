/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:42:53 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/23 15:57:19 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>//usleep
#include <stdio.h>
#include "philo.h"

int	ph_philo_eating(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&(data->fork[philo->left_fork]));
	ph_print_status(data, philo->id, "has taken a fork");
	if (data->num_of_philo != 1)
	{
		pthread_mutex_lock(&(data->fork[philo->right_fork]));
		ph_print_status(data, philo->id, "has taken a fork");
		ph_print_status(data, philo->id, "is eating");
		philo->last_time_eaten = ph_get_time();
		philo->num_of_eaten++;
		wait_tasking(ph_get_time(), data->time_to_eat);
		pthread_mutex_unlock(&(data->fork[philo->right_fork]));
	}
	pthread_mutex_unlock(&(data->fork[philo->left_fork]));
	return (0);
}

void	*thread_task(void *param)
{
	t_philo	*philo;
	t_data	*data;

	philo = param;
	data = philo->data;
	if (philo->id % 2)
		usleep(1000);
	while (data->dead_flag)
	{
		ph_philo_eating(philo, data);
		if (data->times_to_eat == philo->num_of_eaten)
		{
			data->dead_flag = 0;
			break;
		}
		ph_print_status(data, philo->id, "is sleeping");
		wait_tasking(ph_get_time(), data->time_to_sleep);
		ph_print_status(data, philo->id, "is thinking");
	}
	return (0);
}

void	val_flag(t_philo *philo, t_data *data)
{
	int			idx;
	long long	cur_time;

	while (data->dead_flag)
	{
		// if (data->times_to_eat != 0 && data->num_of_philo == )
		idx = 0;
		while (idx < data->num_of_philo)
		{
			cur_time = ph_get_time();
			if (philo[idx].last_time_eaten + data->time_to_die < cur_time)
			{
				ph_print_status(data, philo[idx].id, "died");
				data->dead_flag = 0;
			}
			idx++;
		}
	}
}

int	philosophers_logic(t_philo *philo, t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->num_of_philo)
	{
		if (pthread_create(&philo[idx].thread, NULL, thread_task, &philo[idx]))
			return (1);
		idx++;
	}
	val_flag(philo, data);
	idx = 0;
	while (idx < data->num_of_philo)
	{
		pthread_join(philo[idx].thread, NULL);
		idx++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philo;
	int		flag;

	if (argc != 5 && argc != 6)
		return (terminator(1, NULL, "Incorrect number of arguments"));
	flag = ph_data_init(&data, argc, argv);
	if (flag)
		return (terminator(2, &data, "Data init error"));
	flag = ph_philo_init(&philo, &data);
	if (flag)
		return (terminator(3, &philo, "Philo init error"));
	flag = philosophers_logic(philo, &data);
	if (flag)
		return (0);
	ph_detach(philo, &data);
	return (0);
}
