/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_handle_sem_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:44:25 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/30 22:50:34 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include "philo_bonus.h"

void	set_sem_value(t_sema *arg, long value)
{
	sem_wait(arg->sem);
	arg->value = value;
	sem_post(arg->sem);
}

void	increase_sem_value(t_sema *arg)
{
	sem_wait(arg->sem);
	arg->value++;
	sem_post(arg->sem);
}

long	get_sem_value(t_sema *arg)
{
	long	value;

	sem_wait(arg->sem);
	value = arg->value;
	sem_post(arg->sem);
	return (value);
}
