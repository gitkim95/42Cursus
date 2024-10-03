/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:49:58 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/03 22:34:48 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_idx;

	s_idx = ft_strlen(s) - 1;
	while (s_idx >= 0)
	{
		if (s[s_idx] == c)
			return ((char *)(s + s_idx));
		s_idx--;
	}
	return (0);
}
