/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:36:03 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/03 13:35:43 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	mem_size;
	char	*new_str;

	mem_size = size * nmemb;
	if (mem_size < nmemb || size == 0)
		return (NULL);
	new_str = malloc(mem_size);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb && size != 0)
	{
		new_str[i] = 0;
		i++;
	}
	return (new_str);
}
