/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:10:52 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/30 21:17:25 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "philo_bonus.h"

void	philosophers_logic_b(t_philo_b **philo_p, t_data_b *data)
{
	t_philo_b	*philo;
	int			idx;

	philo = *philo_p;
	idx = 0;
	while (idx < data->num_of_philo)
	{
		data->pid[idx] = fork();
		if (data->pid[idx] == -1)
			terminator_b(1, philo_p, data, "Fork failed");
		else if (data->pid[idx] == 0)
		{
			if (pthread_create(&philo[idx].thread, NULL, th_work, &philo[idx]))
				terminator_b(1, philo_p, data, "Thread_create failed");
			pthread_join(philo[idx].thread, NULL);
			terminator_b(0, philo_p, data, NULL);
		}
		idx++;
	}
	val_flag_b(philo_p, data);
	idx = 0;
	while (idx < data->num_of_philo)
	{
		waitpid(data->pid[idx], NULL, 0);
	}
}

int	main(int argc, char *argv[])
{
	t_data_b	data;
	t_philo_b	*philo;

	if (argc != 5 && argc != 6)
		terminator_b(1, NULL, NULL, "Incorrect number of arguments");
	ph_data_init_b(&data, argc, argv);
	ph_philo_init_b(&philo, &data);
	philosophers_logic_b(&philo, &data);
	terminator(0, &philo, &data, NULL);
	return (0);
}
