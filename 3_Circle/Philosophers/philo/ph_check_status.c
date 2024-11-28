/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:33:15 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/28 23:40:13 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_dead_flag(t_philo **philo_pointer, t_data *data)
{
	int		idx;
	t_philo	*philo;

	philo = *philo_pointer;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		increase_mtx_value(&(philo[idx].dead_flag));
		idx++;
	}
}

int	ph_check_meal(t_philo **philo_pointer, t_data *data)
{
	int			idx;
	t_philo		*philo;

	philo = *philo_pointer;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		if (get_mtx_value(&(philo[idx].num_of_eaten)) < data->times_to_eat)
			return (0);
		idx++;
	}
	return (1);
}

int	ph_check_starvation(t_philo **philo_pointer, t_data *data)
{
	long long	life;
	long long	cur_time;
	int			idx;
	t_philo		*philo;

	philo = *philo_pointer;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		life = get_mtx_value((&philo[idx].last_time_eaten)) + data->time_to_die;
		cur_time = ph_get_time();
		if (cur_time > life)
		{
			increase_mtx_value(&(philo[idx].dead_flag));
			ph_print_status(data, philo[idx].ord, "died");
			return (1);
		}
		idx++;
	}
	return (0);
}

void	val_flag(t_philo **philo, t_data *data)
{
	while (1)
	{
		if (ph_check_starvation(philo, data) || ph_check_meal(philo, data))
		{
			set_dead_flag(philo, data);
			break ;
		}
	}
}
