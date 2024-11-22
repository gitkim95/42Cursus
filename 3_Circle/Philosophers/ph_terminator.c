/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_terminator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:25:59 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/23 01:19:15 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "philo.h"

void	ph_destroy_mutex(t_data *data)
{
	int	idx;

	pthread_mutex_destroy(&(data->print));
	while (idx < data->num_of_philo)
	{
		pthread_mutex_destroy(&(data->fork[idx]));
		idx++;
	}
	free(data->fork);
}

void	ph_detach(t_philo *philo, t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->num_of_philo)
	{
		pthread_detach(philo[idx].thread);
		idx++;
	}
}

void	free_philo(t_philo **philo)
{
	free(*philo);
}

int	terminator(int flag, void *for_free, char *msg)
{
	if (flag)
		write(2, msg, ft_strlen(msg));
	// if (flag == 2 && for_free)
	// 	free_data((t_data *)for_free);
	else if (flag == 3)
		free_philo((t_philo **)for_free);
	return (flag);
}
