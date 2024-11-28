/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_task_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:27:15 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/28 23:41:38 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

int	check_flags(t_philo *philo, t_data *data, int fork_num)
{
	int	ret;

	ret = 0;
	if (!get_mtx_value(&(data->fork[fork_num])) && \
		!get_mtx_value(&philo->dead_flag))
		ret++;
	else if (get_mtx_value(&philo->dead_flag))
		ret--;
	return (ret);
}

int	get_fork(t_philo *philo, t_data *data, int fork_num)
{
	int	able_get;

	while (1)
	{
		able_get = check_flags(philo, data, fork_num);
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
	set_mtx_value(&(data->fork[fork_num]), philo->ord + 1);
	ph_print_status(data, philo->ord, "has taken a fork");
	return (1);
}

void	check_holding_fork(t_philo *philo, t_data *data)
{
	if (get_mtx_value(&(data->fork[philo->right_fork])) == philo->ord + 1)
		set_mtx_value(&(data->fork[philo->right_fork]), 0);
	if (get_mtx_value(&(data->fork[philo->left_fork])) == philo->ord + 1)
		set_mtx_value(&(data->fork[philo->left_fork]), 0);
}

void	ph_print_status(t_data *data, int ord, char *msg)
{
	long long	cur_time;

	cur_time = ph_get_time();
	if (cur_time == -1)
		return ;
	pthread_mutex_lock(&(data->print));
	printf("%lld %d %s\n", cur_time, ord + 1, msg);
	pthread_mutex_unlock(&(data->print));
}
