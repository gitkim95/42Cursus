/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:17:21 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/04 02:05:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b_pnt;
	const char	*l_pnt;
	size_t		i;
	size_t		j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (*big && i < len)
	{
		b_pnt = big + i;
		l_pnt = little;
		j = i;
		while (*b_pnt == *l_pnt && *b_pnt != '\0' && *l_pnt != '\0' && j < len)
		{
			b_pnt++;
			l_pnt++;
			j++;
		}
		if (*l_pnt == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
