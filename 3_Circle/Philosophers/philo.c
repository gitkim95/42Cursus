/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:42:53 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/23 01:28:36 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>//usleep
#include <stdio.h>

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
		// 먹을 시간 주기
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
		//생각 할 시간 주기
		ph_print_status(data, philo->id, "is thinking");
	}
	return (0);
}

// void	val_flag(t_philo *philo, t_data *data)
// {
// 	int			idx;
// 	long long	time;

// 	if (data->dead_flag)
// 	{
// 		if ()
// 	}
// }

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
	idx = 0;
	while (idx < data->num_of_philo)
	{
		pthread_join(philo[idx].thread, NULL);
		idx++;
	}
	return (0);
}

void	ph_clear(t_philo **philo, t_data *data)
{
	ph_detach(*philo, data);
	ph_destroy_mutex(data);

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
