/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_terminator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:25:59 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/28 22:41:19 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"

void	ph_destroy_mutex(t_data *data)
{
	int	idx;

	idx = 0;
	pthread_mutex_destroy(&(data->print));
	while (idx < data->num_of_philo)
	{
		pthread_mutex_destroy(&(data->fork[idx].mtx));
		idx++;
	}
	free(data->fork);
}

void	free_philo(t_philo **philo, t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->num_of_philo)
	{
		pthread_mutex_destroy(&(*philo)[idx].num_of_eaten.mtx);
		pthread_mutex_destroy(&(*philo)[idx].dead_flag.mtx);
		pthread_mutex_destroy(&(*philo)[idx].last_time_eaten.mtx);
		idx++;
	}
	free(*philo);
}

int	terminator(int flag, t_philo **philo, t_data *data, char *msg)
{
	if (flag)
		write(2, msg, ft_strlen(msg));
	if (data)
		ph_destroy_mutex(data);
	if (philo)
		free_philo(philo, data);
	return (flag);
}
