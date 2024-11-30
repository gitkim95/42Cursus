/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check_status_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:53:29 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/01 08:16:29 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_bonus.h"

int	ph_check_meal_b(t_philo_b *philo, t_data_b *data)
{
	if (philo->num_of_eaten < data->times_to_eat)
		return (0);
	return (1);
}

int	ph_check_starvation_b(t_philo_b *philo, t_data_b *data)
{
	long		life;
	long		cur_time;

	life = philo->last_time_eaten + data->time_to_die;
	cur_time = ph_get_time_b();
	if (cur_time > life)
	{
		ph_print_status_b(data, philo->ord, "died");
		return (1);
	}
	return (0);
}

int	val_flag_b(t_philo_b *philo, t_data_b *data)
{
	while (1)
	{
		sem_wait(data->dead);
		if (ph_check_starvation_b(philo, data))
			return (1);
		sem_post(data->dead);
		if (ph_check_meal_b(philo, data))
			return (0);
	}
}

void	*check_dead(void *param)
{
	t_philo_b	*philo;
	t_data_b	*data;
	int			flag;

	philo = (t_philo_b *)param;
	data = philo->data;
	flag = val_flag_b(philo, data);
	close_sem(data, 0);
	exit(flag);
	return (NULL);
}
