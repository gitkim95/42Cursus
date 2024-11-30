/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_task_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:20:47 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/01 08:13:38 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_bonus.h"

void	get_fork_b(t_philo_b *philo, t_data_b *data)
{
	sem_wait(data->fork);
	ph_print_status_b(data, philo->ord, "has taken a fork");
}

void	ph_print_status_b(t_data_b *data, int ord, char *msg)
{
	long long	cur_time;

	cur_time = ph_get_time_b();
	if (cur_time == -1)
		return ;
	sem_wait(data->print);
	printf("%lld %d %s\n", cur_time, ord + 1, msg);
	sem_post(data->print);
}

void	wait_tasking_b(long long start, int wait)
{
	long long	fin_time;

	fin_time = start + wait;
	while (ph_get_time_b() < fin_time)
		usleep(100);
}

long	ph_get_time_b(void)
{
	struct timeval	tv;
	long			total_time;
	int				flag;

	flag = gettimeofday(&tv, NULL);
	if (flag == -1)
		return (-1);
	total_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (total_time);
}
