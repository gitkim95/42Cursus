/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_terminator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:25:59 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/08 15:49:36 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include "philo_bonus.h"

void	unlink_sem(int nop)
{
	int		idx;
	char	name[4];

	sem_unlink("/fork");
	sem_unlink("/print");
	idx = 0;
	while (idx < nop)
	{
		name[0] = '/';
		name[2] = '0' + idx % 10;
		name[3] = '\0';
		name[1] = 'd';
		sem_unlink(name);
		name[1] = 'n';
		sem_unlink(name);
		name[1] = 't';
		sem_unlink(name);
		idx++;
	}
}

void	close_sem(t_philo_b *philo, t_data_b *data, int flag)
{
	if (data->fork)
		sem_close(data->fork);
	if (data->print)
		sem_close(data->print);
	if (philo->dead_flag.sem)
		sem_close(philo->dead_flag.sem);
	if (philo->num_of_eaten.sem)
		sem_close(philo->num_of_eaten.sem);
	if (philo->num_of_eaten.sem)
		sem_close(philo->last_time_eaten.sem);
	if (flag == 1)
		unlink_sem(data->num_of_philo);
}

void	terminator_b(int flag, pid_t *pid, char *msg)
{
	if (pid)
		free(pid);
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (flag > 0)
		exit(1);
	if (!flag)
		exit(0);
}
