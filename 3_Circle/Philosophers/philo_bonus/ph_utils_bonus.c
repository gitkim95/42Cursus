/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:18:16 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/30 21:18:57 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "philo_bonus.h"

void	wait_tasking_b(long long start, int wait)
{
	long long	fin_time;

	fin_time = start + wait;
	while (ph_get_time() < fin_time)
		usleep(100);
}

long	ph_get_time_b(void)
{
	struct timeval	tv;
	long long		total_time;
	int				flag;

	flag = gettimeofday(&tv, NULL);
	if (flag == -1)
		return (-1);
	total_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (total_time);
}
