/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_thread_task_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:14:29 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/01 22:48:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo_bonus.h"

int	ph_philo_think_b(t_philo_b *philo, t_data_b *data)
{
	ph_print_status_b(data, philo->ord, "is thinking");
	if (!get_fork_b(philo, data))
		return (0);
	if (!get_fork_b(philo, data))
		return (0);
	return (1);
}

int	ph_philo_eat_b(t_philo_b *philo, t_data_b *data)
{
	if (get_sem_value(&philo->dead_flag))
		return (0);
	set_sem_value_2(&philo->last_time_eaten, ph_get_time_b());
	ph_print_status_b(data, philo->ord, "is eating");
	wait_tasking_b(ph_get_time_b(), data->time_to_eat);
	sem_post(data->fork);
	philo->hold--;
	sem_post(data->fork);
	philo->hold--;
	set_sem_value_1(&philo->num_of_eaten);
	return (1);
}

int	ph_philo_sleep_b(t_philo_b *philo, t_data_b *data)
{
	if (get_sem_value(&philo->dead_flag))
		return (0);
	ph_print_status_b(data, philo->ord, "is sleeping");
	wait_tasking_b(ph_get_time_b(), data->time_to_sleep);
	return (1);
}

void	*thread_task_b(void *param)
{
	t_philo_b	*philo;
	t_data_b	*data;

	philo = (t_philo_b *)param;
	data = philo->data;
	if (philo->ord % 2)
		usleep (500);
	while (1)
	{
		if (!ph_philo_think_b(philo, data))
			break ;
		if (!ph_philo_eat_b(philo, data))
			break ;
		if (!ph_philo_sleep_b(philo, data))
			break ;
		usleep(100);
	}
	while (philo->hold > 0)
	{
		sem_post(data->fork);
		philo->hold--;
	}
	return (NULL);
}
