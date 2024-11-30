/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_terminator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:25:59 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/01 07:19:53 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include "philo_bonus.h"

void	unlink_sem(void)
{
	sem_unlink("/fork");
	sem_unlink("/print");
	sem_unlink("/dead");
}

void	close_sem(t_data_b *data, int flag)
{
	if (data->fork)
		sem_close(data->fork);
	if (data->print)
		sem_close(data->print);
	if (data->dead)
		sem_close(data->dead);
	if (flag == 1)
		unlink_sem();
}

void	terminator_b(int flag, t_philo_b **philo_p, pid_t *pid, char *msg)
{
	if (philo_p)
		free(*philo_p);
	if (pid)
		free(pid);
	if (flag > 0)
	{
		write(2, msg, ft_strlen(msg));
		exit(1);
	}
	if (!flag)
		exit(0);
}
