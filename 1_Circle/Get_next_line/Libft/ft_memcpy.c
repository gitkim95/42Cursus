/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:35:59 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/03 22:29:18 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ch_dst;
	char	*ch_src;

	ch_src = (char *)src;
	ch_dst = (char *)dest;
	i = 0;
	while (i < n)
	{
		ch_dst[i] = ch_src[i];
		i++;
	}
	return (dest);
}
