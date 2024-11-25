/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_thread_task.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:27:15 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/25 22:50:30 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include "philo.h"

int	get_fork(t_philo *philo, t_data *data, int fork_num)
{
	if (data->run_flag == 0 || philo->dead_flag == 1)
		return (0);
	pthread_mutex_lock(&(data->fork[fork_num]));
	ph_print_status(data, philo->id, "has taken a fork");
	return (1);
}

int	ph_philo_think(t_philo *philo, t_data *data)
{
	if (philo->num_of_eaten)
		ph_print_status(data, philo->id, "is thinking");
	if (!get_fork(philo, data, philo->left_fork))
		return (0);
	if (!get_fork(philo, data, philo->right_fork))
		return (0);
	return (1);
}

int	ph_philo_eat(t_philo *philo, t_data *data)
{
	if (data->run_flag == 0 || philo->dead_flag == 1)
		return (0);
	philo->last_time_eaten = ph_get_time();
	ph_print_status(data, philo->id, "is eating");
	wait_tasking(ph_get_time(), data->time_to_eat);
	philo->num_of_eaten++;
	pthread_mutex_unlock(&(data->fork[philo->right_fork]));
	pthread_mutex_unlock(&(data->fork[philo->left_fork]));
	return (1);
}

int	ph_philo_sleep(t_philo *philo, t_data *data)
{
	if (data->run_flag == 0 || philo->dead_flag == 1)
		return (0);
	ph_print_status(data, philo->id, "is sleeping");
	wait_tasking(ph_get_time(), data->time_to_sleep);
	return (1);
}

void	*thread_task(void *param)
{
	t_philo	*philo;
	t_data	*data;

	philo = param;
	data = philo->data;
	if (philo->id % 2)
		usleep(500);
	while (data->run_flag)
	{
		if (!ph_philo_think(philo, data))
			break ;
		if (!ph_philo_eat(philo, data))
			break ;
		if (!ph_philo_sleep(philo, data))
			break ;
	}
	return (NULL);
}
