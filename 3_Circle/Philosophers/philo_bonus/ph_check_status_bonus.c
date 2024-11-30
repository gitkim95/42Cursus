/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check_status_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:53:29 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/30 23:13:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_dead_flag_b(t_philo_b **philo_pointer, t_data_b *data)
{
	int			idx;
	t_philo_b	*philo;

	philo = *philo_pointer;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		increase_sem_value(&(philo[idx].dead_flag));
		idx++;
	}
}

int	ph_check_meal_b(t_philo_b **philo_pointer, t_data_b *data)
{
	int			idx;
	t_philo_b	*philo;

	philo = *philo_pointer;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		if (get_sem_value(&(philo[idx].num_of_eaten)) < data->times_to_eat)
			return (0);
		idx++;
	}
	return (1);
}

int	ph_check_starvation_b(t_philo_b **philo_pointer, t_data_b *data)
{
	long		life;
	long		cur_time;
	int			idx;
	t_philo_b	*philo;

	philo = *philo_pointer;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		life = get_sem_value((&philo[idx].lt_eaten)) + data->time_to_die;
		cur_time = ph_get_time_b();
		if (cur_time > life)
		{
			increase_sem_value(&(philo[idx].dead_flag));
			ph_print_status_b(data, philo[idx].ord, "died");
			return (1);
		}
		idx++;
	}
	return (0);
}

void	val_flag_b(t_philo_b **philo, t_data_b *data)
{
	while (1)
	{
		if (ph_check_starvation_b(philo, data) || ph_check_meal_b(philo, data))
		{
			set_dead_flag_b(philo, data);
			break ;
		}
	}
}
