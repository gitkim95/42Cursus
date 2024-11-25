/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:42:53 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/25 22:49:16 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	philosophers_logic(t_philo **philo_pointer, t_data *data)
{
	t_philo	*philo;
	int		idx;

	philo = *philo_pointer;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		if (pthread_create(&philo[idx].thread, NULL, thread_task, &philo[idx]))
			return (1);
		idx++;
	}
	val_flag(&philo, data);
	idx = 0;
	while (idx < data->num_of_philo)
	{
		pthread_join(philo[idx].thread, NULL);
		idx++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (terminator(1, NULL, NULL, "Incorrect number of arguments"));
	if (ph_data_init(&data, argc, argv))
		return (terminator(1, NULL, &data, "Data init error"));
	if (ph_philo_init(&philo, &data))
		return (terminator(1, &philo, &data, "Philo init error"));
	if (philosophers_logic(&philo, &data))
		return (terminator(2, &philo, &data, "Thread create error"));
	return (terminator(0, &philo, &data, NULL));
}
