/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_handle_sem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:53:45 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/01 22:19:22 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include "philo_bonus.h"

long	get_sem_value(t_sema *sem)
{
	long	value;

	sem_wait(sem->sem);
	value = sem->value;
	sem_post(sem->sem);
	return (value);
}

void	set_sem_value_1(t_sema *sem)
{
	sem_wait(sem->sem);
	sem->value++;
	sem_post(sem->sem);
}

void	set_sem_value_2(t_sema *sem, long value)
{
	sem_wait(sem->sem);
	sem->value = value;
	sem_post(sem->sem);
}
