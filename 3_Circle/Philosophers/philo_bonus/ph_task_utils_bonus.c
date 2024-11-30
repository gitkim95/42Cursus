/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_task_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:20:47 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/30 23:12:55 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include "philo_bonus.h"

int	check_flags_b(t_philo_b *philo, t_data_b *data, int fork_num)
{
	int	ret;

	ret = 0;
	if (!get_sem_value(&(data->fork[fork_num])) && \
		!get_sem_value(&philo->dead_flag))
		ret++;
	else if (get_sem_value(&philo->dead_flag))
		ret--;
	return (ret);
}

int	get_fork_b(t_philo_b *philo, t_data_b *data, int fork_num)
{
	int	able_get;

	while (1)
	{
		able_get = check_flags_b(philo, data, fork_num);
		if (able_get > 0)
			break ;
		else if (able_get == 0)
		{
			usleep(10);
			continue ;
		}
		else
			return (0);
	}
	set_sem_value(&(data->fork[fork_num]), philo->ord + 1);
	ph_print_status_b(data, philo->ord, "has taken a fork");
	return (1);
}

void	check_holding_fork_b(t_philo_b *philo, t_data_b *data)
{
	if (get_sem_value(&(data->fork[philo->right_fork])) == philo->ord + 1)
		set_sem_value(&(data->fork[philo->right_fork]), 0);
	if (get_sem_value(&(data->fork[philo->left_fork])) == philo->ord + 1)
		set_sem_value(&(data->fork[philo->left_fork]), 0);
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
