/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:34:42 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/01 08:28:34 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <fcntl.h>
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>
#include "philo_bonus.h"

void	ph_philo_init_b(t_philo_b **philo, t_data_b *data)
{
	int	idx;

	*philo = malloc(sizeof(t_philo_b) * data->num_of_philo);
	if (!(*philo))
	{
		close_sem(data, 1);
		terminator_b(1, NULL, NULL, "Allocation failed");
	}
	memset(*philo, 0, sizeof(t_philo_b) * data->num_of_philo);
	idx = 0;
	while (idx < data->num_of_philo)
	{
		(*philo)[idx].data = data;
		(*philo)[idx].ord = idx;
		(*philo)[idx].last_time_eaten = ph_get_time_b();
		idx++;
	}
}

void	ph_set_sem(t_data_b *data)
{
	data->fork = sem_open("/fork", O_CREAT, 0644, data->num_of_philo);
	if (data->fork == SEM_FAILED)
		terminator_b(1, NULL, NULL, "Sem_open failed");
	data->print = sem_open("/print", O_CREAT, 0644, 1);
	if (data->print == SEM_FAILED)
	{
		close_sem(data, 1);
		terminator_b(1, NULL, NULL, "Sem_open failed");
	}
	data->dead = sem_open("/dead", O_CREAT, 0644, data->num_of_philo);
	if (data->dead == SEM_FAILED)
	{
		close_sem(data, 1);
		terminator_b(1, NULL, NULL, "Sem_open failed");
	}
}

void	ph_data_init_b(t_data_b *data, int ac, char **av)
{
	memset(data, 0, sizeof(t_data_b));
	data->num_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->times_to_eat = INT_MAX;
	if (ac == 6)
	{
		data->times_to_eat = ft_atoi(av[5]);
		if (data->times_to_eat < 0)
			terminator_b (1, NULL, NULL, "Incorrect data");
	}
	if (data->num_of_philo <= 0 || data->time_to_die < 0 || \
		data->time_to_eat < 0 || data->time_to_sleep < 0)
		terminator_b (1, NULL, NULL, "Incorrect data");
	ph_set_sem(data);
}
