/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:12:46 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/03 13:34:37 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str_1;
	char	*str_2;

	str_1 = (char *)s1;
	str_2 = (char *)s2;
	i = 0;
	while (str_1[i] && str_2[i] && i < n)
	{
		if (str_1[i] != str_2[i])
			return (str_1[i] - str_2[i]);
		i++;
	}
	if (i < n)
		return (str_1[i] - str_2[i]);
	return (0);
}
