/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_thread_task_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:14:29 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/01 08:25:23 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_bonus.h"

void	ph_philo_think_b(t_philo_b *philo, t_data_b *data)
{
	ph_print_status_b(data, philo->ord, "is thinking");
	get_fork_b(philo, data);
	get_fork_b(philo, data);
}

void	ph_philo_eat_b(t_philo_b *philo, t_data_b *data)
{
	philo->last_time_eaten = ph_get_time_b();
	ph_print_status_b(data, philo->ord, "is eating");
	wait_tasking_b(ph_get_time_b(), data->time_to_eat);
	philo->num_of_eaten++;
	sem_post(data->fork);
	sem_post(data->fork);
}

void	ph_philo_sleep_b(t_philo_b *philo, t_data_b *data)
{
	ph_print_status_b(data, philo->ord, "is sleeping");
	wait_tasking_b(ph_get_time_b(), data->time_to_sleep);
}

void	thread_task_b(t_philo_b *philo, t_data_b *data)
{
	while (1)
	{
		ph_philo_think_b(philo, data);
		ph_philo_eat_b(philo, data);
		ph_philo_sleep_b(philo, data);
		usleep(10);
	}
}
