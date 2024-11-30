/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_task_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:20:47 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/30 19:23:32 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <semaphore.h>
#include "philo_bonus.h"

void	ph_print_status(t_data_b *data, int ord, char *msg)
{
	long long	cur_time;

	cur_time = ph_get_time();
	if (cur_time == -1)
		return ;
	sem_wait(data->print);
	printf("%lld %d %s\n", cur_time, ord + 1, msg);
	sem_post(data->print);
}
