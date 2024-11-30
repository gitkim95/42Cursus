/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_terminator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:25:59 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/30 23:27:54 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include "philo_bonus.h"

void	ph_delete_sem(t_sema *sem, char flag, int idx)
{
	char	name[4];

	name[0] = '/';
	name[1] = flag;
	name[2] = '0' + idx % 10;
	name[3] = '\0';
	if (sem)
		sem_close(sem->sem);
	sem_unlink(name);
}

void	free_philo_b(t_philo_b **philo, t_data_b *data)
{
	int		idx;

	idx = 0;
	while (idx < data->num_of_philo)
	{
		if ((*philo)[idx].num_of_eaten.sem)
			ph_delete_sem(&(*philo)[idx].num_of_eaten, 'n', idx);
		if ((*philo)[idx].dead_flag.sem)
			ph_delete_sem(&(*philo)[idx].dead_flag, 'd', idx);
		if ((*philo)[idx].lt_eaten.sem)
			ph_delete_sem(&(*philo)[idx].lt_eaten, 't', idx);
		idx++;
	}
	free(*philo);
}

void	free_data_b(t_data_b *data)
{
	int		idx;

	if (data->fork)
	{
		idx = 0;
		while (idx < data->num_of_philo)
		{
			if (data->fork[idx].sem)
				ph_delete_sem(&data->fork[idx], 'f', idx);
			idx++;
		}
		free(data->fork);
	}
	if (data->print)
	{
		sem_close(data->print);
		sem_unlink("/p0");
	}
	if (data->pid)
		free(data->pid);
}

void	terminator_b(int flag, t_philo_b **philo, t_data_b *data, char *msg)
{
	if (flag)
		write(2, msg, ft_strlen(msg));
	if (data)
		free_data_b(data);
	if (philo)
		free_philo_b(philo, data);
	exit (flag);
}
