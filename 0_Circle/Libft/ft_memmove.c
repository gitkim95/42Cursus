/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:39:16 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/03 12:54:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;
	char	*ch_dst;
	char	*ch_src;
	int		i;

	i = 0;
	while (i < n)
	{
		tmp[i] = ch_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		ch_dst[i] = tmp[i];
		i++;
	}
	return (dest);
}
