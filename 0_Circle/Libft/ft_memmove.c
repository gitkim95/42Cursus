/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:39:16 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/01 18:48:38 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;
	int		i;

	i = 0;
	while (i < n)
	{
		tmp[i] = src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest[i] = tmp[i];
		i++;
	}
	return (dest);
}
