/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:17:21 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/03 23:07:25 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b_pnt;
	const char	*l_pnt;
	size_t		i;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		b_pnt = big + i;
		l_pnt = little;
		while (*b_pnt == *l_pnt && *b_pnt != '\0' && *l_pnt != '\0')
		{
			b_pnt++;
			l_pnt++;
		}
		if (*l_pnt == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
