/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:42:53 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/19 22:47:42 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdlib.h>

int	philosopher_logic(t_philo *philo, t_data *data)
{
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philo;
	int		flag;

	if (argc != 5 || argc != 6)
		return (terminator(1, NULL, "Incorrect number of arguments"));
	flag = ph_data_init(&data, argc, argv);
	if (flag)
		return (terminator(2, &data, "Data init error"));
	flag = ph_philo_init(&philo, &data);
	if (flag)
		return (terminator(3, &philo, "Philo init error"));
	flag = philosophers_logic(philo, &data);
	if (flag)
		return (terminator);
	return (0);
}
