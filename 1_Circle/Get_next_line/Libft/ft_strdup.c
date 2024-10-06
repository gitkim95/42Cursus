/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:04:06 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/03 17:26:13 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
