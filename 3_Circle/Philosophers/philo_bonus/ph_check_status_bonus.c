/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check_status_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:53:29 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/08 16:06:16 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_bonus.h"

int	ph_check_meal_b(t_philo_b *philo, t_data_b *data)
{
	if (get_sem_value(&philo->num_of_eaten) >= data->times_to_eat)
	{
		set_sem_value_1(&philo->dead_flag);
		return (1);
	}
	return (0);
}

int	ph_check_starvation_b(t_philo_b *philo, t_data_b *data)
{
	long		life;
	long		cur_time;

	life = get_sem_value(&philo->last_time_eaten) + data->time_to_die;
	cur_time = ph_get_time_b();
	if (cur_time > life)
	{
		sem_wait(data->print);
		ph_print_status_b(philo->ord, "died");
		sem_post(data->print);
		set_sem_value_1(&philo->dead_flag);
		return (1);
	}
	return (0);
}

int	val_flag_b(t_philo_b *philo, t_data_b *data)
{
	while (1)
	{
		if (ph_check_starvation_b(philo, data))
			return (1);
		if (ph_check_meal_b(philo, data))
			return (0);
	}
}
