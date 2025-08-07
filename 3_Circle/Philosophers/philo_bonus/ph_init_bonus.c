/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:34:42 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/08 16:12:53 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <fcntl.h>
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>
#include "philo_bonus.h"

void	ph_make_named_sem(t_philo_b *philo, t_sema *sem, char *name)
{
	sem->sem = sem_open(name, O_CREAT, 0644, 1);
	if (sem->sem == SEM_FAILED)
	{
		close_sem(philo, philo->data, 1);
		terminator_b(1, NULL, "Sem_open failed");
	}
}

void	ph_set_sem_philo(t_philo_b *philo, int idx)
{
	char		name[4];

	name[0] = '/';
	name[2] = '0' + idx % 10;
	name[3] = '\0';
	name[1] = 'd';
	ph_make_named_sem(philo, &philo->dead_flag, name);
	name[1] = 'n';
	ph_make_named_sem(philo, &philo->num_of_eaten, name);
	name[1] = 't';
	ph_make_named_sem(philo, &philo->last_time_eaten, name);
}

void	ph_philo_init_b(t_philo_b *philo, t_data_b *data)
{
	memset(philo, 0, sizeof(t_philo_b));
	philo->data = data;
	philo->last_time_eaten.value = ph_get_time_b();
}

void	ph_set_sem_data(t_philo_b *philo, t_data_b *data)
{
	data->fork = sem_open("/fork", O_CREAT, 0644, data->num_of_philo);
	if (data->fork == SEM_FAILED)
		terminator_b(1, NULL, "Sem_open failed");
	data->print = sem_open("/print", O_CREAT, 0644, 1);
	if (data->print == SEM_FAILED)
	{
		close_sem(philo, data, 1);
		terminator_b(1, NULL, "Sem_open failed");
	}
}

void	ph_data_init_b(t_philo_b *philo, t_data_b *data, int ac, char **av)
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
			terminator_b (1, NULL, "Incorrect data");
	}
	if (data->num_of_philo <= 0 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
		terminator_b (1, NULL, "Incorrect data");
	ph_set_sem_data(philo, data);
}
