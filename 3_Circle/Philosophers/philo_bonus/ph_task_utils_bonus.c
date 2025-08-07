/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_task_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:20:47 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/08 16:07:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/time.h>
#include "philo_bonus.h"

int	get_fork_b(t_philo_b *philo, t_data_b *data)
{
	if (get_sem_value(&philo->dead_flag))
		return (0);
	sem_wait(data->fork);
	philo->hold++;
	sem_wait(data->print);
	ph_print_status_b(philo->ord, "has taken a fork");
	sem_post(data->print);
	if (data->num_of_philo == 1)
		return (0);
	return (1);
}

void	ph_print_status_b(int ord, char *msg)
{
	long long	cur_time;

	cur_time = ph_get_time_b();
	if (cur_time == -1)
		return ;
	printf("%lld %d %s\n", cur_time, ord + 1, msg);
}

void	wait_tasking_b(long long start, int wait)
{
	long long	fin_time;
	long long	remaining;

	fin_time = start + wait;
	while (ph_get_time_b() < fin_time)
	{
		remaining = fin_time - ph_get_time_b();
		if (remaining > 1000)
			usleep(500);
		else if (remaining > 100)
			usleep(50);
		else
			usleep(10);
	}
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
