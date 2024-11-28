/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_thread_task.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:27:15 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/29 00:14:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include "philo.h"

int	ph_philo_think(t_philo *philo, t_data *data)
{
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
	wait_tasking(ph_get_time(), data->time_to_eat);
	increase_mtx_value(&(philo->num_of_eaten));
	set_mtx_value(&(data->fork[philo->right_fork]), 0);
	set_mtx_value(&(data->fork[philo->left_fork]), 0);
	return (1);
}

int	ph_philo_sleep(t_philo *philo, t_data *data)
{
	if (get_mtx_value(&(philo->dead_flag)))
		return (0);
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
