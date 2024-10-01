/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:49:58 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/01 20:56:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	s_idx;

	s_idx = ft_strlen(s) - 1;
	while (s_idx >= 0)
	{
		if (s[s_idx] == c)
			return (s + s_idx);
		s_idx--;
	}
	return (0);
}
