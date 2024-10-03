/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:39:16 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/03 15:18:49 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*sequential(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*reverse(char *dest, char *src, size_t n)
{
	size_t	i;

	i = n - 1;
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ch_dst;
	char	*ch_src;

	ch_dst = (char *)dest;
	ch_src = (char *)src;
	if (ch_dst > ch_src && (ch_dst - ch_src < n))
	{
		return (sequential(ch_dst, ch_src, n));
	}
	if (ch_dst < ch_src && (ch_src - ch_dst < n))
	{
		return (reverse(ch_dst, ch_src, n));
	}
	return (ft_memcpy);
}
