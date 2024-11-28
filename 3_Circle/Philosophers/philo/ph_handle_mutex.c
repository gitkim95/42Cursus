/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_handle_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:23:24 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/28 23:26:17 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

void	set_mtx_value(t_mutex *arg, long long value)
{
	pthread_mutex_lock(&(arg->mtx));
	arg->value = value;
	pthread_mutex_unlock(&(arg->mtx));
}

void	increase_mtx_value(t_mutex *arg)
{
	pthread_mutex_lock(&(arg->mtx));
	arg->value++;
	pthread_mutex_unlock(&(arg->mtx));
}

long long	get_mtx_value(t_mutex *arg)
{
	long long	value;

	pthread_mutex_lock(&(arg->mtx));
	value = arg->value;
	pthread_mutex_unlock(&(arg->mtx));
	return (value);
}
