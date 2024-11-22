/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:24:49 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/23 01:21:48 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <stdio.h>

int	ph_print_status(t_data *data, int id, char *msg)
{
	long long	cur_time;

	cur_time = ph_get_time();
	if (cur_time == -1)
		return (-1);
	pthread_mutex_lock(&(data->print));
	printf("%lld %d %s \n", cur_time, id + 1, msg);
	pthread_mutex_unlock(&(data->print));
	return (0);
}

long long	ph_get_time(void)
{
	struct timeval	tv;
	long long		total_time;
	int				flag;

	flag = gettimeofday(&tv, NULL);
	if (flag == -1)
		return (-1);
	total_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (total_time);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	while (nptr[i] == 32 || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i + 1] == '+' || nptr[i + 1] == '-')
			return (0);
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (!('0' <= nptr[i] && nptr[i] <= '9'))
		return (0);
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
