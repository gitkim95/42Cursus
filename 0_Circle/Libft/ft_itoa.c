/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:03:17 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/03 17:26:25 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_arr(long long n, char *arr, int *i)
{
	if (n >= 10)
		fill_arr(n / 10, arr, i);
	arr[(*i)++] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	long long	conv;
	char		*result;
	int			i;

	conv = (long long)n;
	result = (char *)malloc(12);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (conv < 0)
	{
		conv *= -1;
		result[i] = '-';
		i++;
	}
	fill_arr(conv, result, &i);
	result[i] = '\0';
	return (result);
}
