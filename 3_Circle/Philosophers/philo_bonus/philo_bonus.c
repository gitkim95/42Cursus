/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:10:52 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/08 16:05:04 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "philo_bonus.h"

void	parents_process(t_data_b *data, pid_t *pid)
{
	int	status;
	int	idx_1;
	int	idx_2;

	idx_1 = 0;
	while (idx_1 < data->num_of_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			idx_2 = 0;
			while (idx_2 < data->num_of_philo)
			{
				kill(pid[idx_2], SIGKILL);
				idx_2++;
			}
		}
		idx_1++;
	}
}

void	child_process(t_philo_b *philo, t_data_b *data, int idx)
{
	int	code;

	philo->ord = idx;
	ph_set_sem_philo(philo, idx);
	if (pthread_create(&philo->thread, NULL, thread_task_b, philo))
	{
		close_sem(philo, data, 1);
		terminator_b(1, NULL, "Thread_create failed");
	}
	code = val_flag_b(philo, data);
	pthread_join(philo->thread, NULL);
	close_sem(philo, data, 0);
	terminator_b(code, NULL, NULL);
}

void	make_child_process(t_philo_b *philo, t_data_b *data, pid_t *pid)
{
	int		idx;

	idx = 0;
	while (idx < data->num_of_philo)
	{
		pid[idx] = fork();
		if (pid[idx] == -1)
		{
			close_sem(philo, data, 1);
			terminator_b(1, pid, "Fork failed");
		}
		else if (pid[idx] == 0)
		{
			free(pid);
			child_process(philo, data, idx);
		}
		idx++;
	}
}

void	philosophers_logic_b(t_philo_b *philo, t_data_b *data)
{
	pid_t	*pid;

	pid = (pid_t *)malloc(sizeof(pid_t) * data->num_of_philo);
	if (!pid)
	{
		close_sem(philo, data, 1);
		terminator_b(1, NULL, "Allocation failed");
	}
	make_child_process(philo, data, pid);
	parents_process(data, pid);
	close_sem(philo, data, 1);
	terminator_b(0, pid, NULL);
}

int	main(int argc, char *argv[])
{
	t_philo_b	philo;
	t_data_b	data;

	unlink_sem(ft_atoi(argv[1]));
	if (argc != 5 && argc != 6)
		terminator_b(1, NULL, "Incorrect number of arguments");
	ph_data_init_b(&philo, &data, argc, argv);
	ph_philo_init_b(&philo, &data);
	philosophers_logic_b(&philo, &data);
	return (0);
}
