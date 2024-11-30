/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:34:42 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/30 23:05:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <fcntl.h>
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>
#include "philo_bonus.h"

void	ph_philo_sem_open(t_philo_b **philo_p, t_data_b *data)
{
	t_philo_b	*philo;
	int			idx;
	char		name[4];

	philo = *philo_p;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		name[0] = '/';
		name[2] = '0' + idx % 10;
		name[3] = '\0';
		name[1] = 'n';
		philo[idx].num_of_eaten.sem = sem_open(name, O_CREAT | O_EXCL, 0644, 1);
		if (philo[idx].num_of_eaten.sem == SEM_FAILED)
			terminator_b(1, philo_p, data, "Sem_open failed");
		name[1] = 'd';
		philo[idx].dead_flag.sem = sem_open(name, O_CREAT | O_EXCL, 0644, 1);
		if (philo[idx].dead_flag.sem == SEM_FAILED)
			terminator_b(1, philo_p, data, "Sem_open failed");
		name[1] = 't';
		philo[idx].lt_eaten.sem = sem_open(name, O_CREAT | O_EXCL, 0644, 1);
		if (philo[idx].lt_eaten.sem == SEM_FAILED)
			terminator_b(1, philo_p, data, "Sem_open failed");
		idx++;
	}
}

void	ph_philo_init_b(t_philo_b **philo, t_data_b *data)
{
	int	idx;

	*philo = malloc(sizeof(t_philo_b) * data->num_of_philo);
	if (!(*philo))
		terminator_b(1, NULL, data, "Allocation failed");
	memset(*philo, 0, sizeof(t_philo_b) * data->num_of_philo);
	idx = 0;
	while (idx < data->num_of_philo)
	{
		(*philo)[idx].data = data;
		(*philo)[idx].ord = idx;
		(*philo)[idx].left_fork = idx;
		(*philo)[idx].right_fork = (idx + 1) % data->num_of_philo;
		(*philo)[idx].lt_eaten.value = ph_get_time_b();
		idx++;
	}
	ph_philo_sem_open(philo, data);
}

void	ph_alloc_data(t_data_b *data)
{
	int		idx;
	char	name[4];

	data->fork = (t_sema *)malloc(sizeof(t_sema) * data->num_of_philo);
	if (!data->fork)
		terminator_b(0, NULL, NULL, "Allocation failed");
	memset(data->fork, 0, sizeof(t_sema) * data->num_of_philo);
	data->pid = (pid_t *)malloc(sizeof(pid_t) * data->num_of_philo);
	if (!data->pid)
		terminator_b(0, NULL, data, "Allocation failed");
	idx = 0;
	data->print = sem_open("/p0", O_CREAT | O_EXCL, 0644, 1);
	if (data->print == SEM_FAILED)
		terminator_b(1, NULL, data, "Sem_open failed");
	while (idx < data->num_of_philo)
	{
		name[0] = '/';
		name[1] = 'f';
		name[2] = '0' + idx % 10;
		name[3] = '\0';
		data->fork[idx].sem = sem_open(name, O_CREAT | O_EXCL, 0644, 1);
		if (data->fork[idx].sem == SEM_FAILED)
			terminator_b(1, NULL, data, "Sem_open failed");
		idx++;
	}
}

void	ph_data_init_b(t_data_b *data, int argc, char *argv[])
{
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->print = 0;
	data->times_to_eat = INT_MAX;
	if (argc == 6)
	{
		data->times_to_eat = ft_atoi(argv[5]);
		if (data->times_to_eat < 0)
			terminator_b (1, NULL, NULL, "Incorrect data");
	}
	if (data->num_of_philo <= 0 || data->time_to_die < 0 || \
		data->time_to_eat < 0 || data->time_to_sleep < 0)
		terminator_b (1, NULL, NULL, "Incorrect data");
	ph_alloc_data(data);
}
