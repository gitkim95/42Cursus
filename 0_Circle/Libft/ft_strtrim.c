/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 23:24:13 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/04 01:20:15 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	alloc_result(char const *s1, char const *set, char **result)
{
	int	s1_idx;
	int	set_idx;
	int	cnt;

	s1_idx = 0;
	cnt = 0;
	while (s1[s1_idx])
	{
		set_idx = 0;
		while (set[set_idx])
		{
			if (s1[s1_idx] == set[set_idx])
				break ;
			set_idx++;
		}
		if (s1[s1_idx] != set[set_idx])
			cnt++;
		s1_idx++;
	}
	*result = (char *)malloc(sizeof(char) * (cnt + 1));
}

void	trim_paste(char const *s1, char const *set, char *result)
{
	int	s1_idx;
	int	set_idx;
	int	i;

	i = 0;
	s1_idx = 0;
	while (s1[s1_idx])
	{
		set_idx = 0;
		while (set[set_idx])
		{
			if (s1[s1_idx] == set[set_idx])
				break ;
			set_idx++;
		}
		if (s1[s1_idx] != set[set_idx])
		{
			result[i] = s1[s1_idx];
			i++;
		}
		s1_idx++;
	}
	result[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;

	result = NULL;
	alloc_result(s1, set, &result);
	if (result == NULL)
		return (NULL);
	trim_paste(s1, set, result);
	return (result);
}
