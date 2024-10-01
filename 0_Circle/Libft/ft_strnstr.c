/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:17:21 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/01 21:27:49 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b_pnt;
	char	*l_pnt;
	size_t	i;

	if (little[0] == '\0')
		return (big);
	i = 0;
	while (big && i < len)
	{
		b_pnt = big;
		l_pnt = little;
		while (b_pnt == l_pnt && b_pnt != '\0' && l_pnt != '\0')
		{
			b_pnt++;
			l_pnt++;
		}
		if (l_pnt == '\0')
			return (big);
		big++;
		i++;
	}
	return (NULL);
}
