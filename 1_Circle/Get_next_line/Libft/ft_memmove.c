/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:39:16 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/04 01:43:36 by gitkim           ###   ########.fr       */
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

	i = n;
	while (i > 0)
	{
		i--;
		dest[i] = src[i];
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ch_dst;
	char	*ch_src;

	ch_dst = (char *)dest;
	ch_src = (char *)src;
	if (ch_dst > ch_src && (size_t)(ch_dst - ch_src) < n)
	{
		return (reverse(ch_dst, ch_src, n));
	}
	if (ch_dst < ch_src && (size_t)(ch_src - ch_dst) < n)
	{
		return (sequential(ch_dst, ch_src, n));
	}
	return (ft_memcpy(dest, src, n));
}
