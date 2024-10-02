/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 01:41:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/03 02:10:22 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char st, char c)
{
	return (st == c || st == '\0');
}

int	count_words(char const *s, char c)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0)
		{
			if (!is_sep(s[i], c))
				cnt++;
		}
		else
		{
			if (!is_sep(s[i], c) && is_sep(s[i - 1], c))
				cnt++;
		}
		i++;
	}
	return (cnt);
}

void	insert_split(char const *s, char c, char *res_split)
{
	int	i;

	i = 0;
	while (!is_sep(s[i], c))
	{
		res_split[i] = s[i];
		i++;
	}
	res_split[i] = '\0';
}

void	alloc_split(char const *s, char c, char **res_split)
{
	int	i;
	int	j;
	int	res_idx;

	res_idx = 0;
	i = 0;
	while (s[i])
	{
		if (is_sep(s[i], c))
			i++;
		else
		{
			j = 0;
			while (!is_sep(s[i + j], c))
				j++;
			res_split[res_idx] = (char *)malloc(sizeof(char) * (j + 1));
			if (res_split[res_idx] == NULL)
				return ;
			insert_split(s + i, c, res_split[res_idx]);
			res_idx++;
			i += j;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**res_split;

	words = count_words(s, c);
	res_split = (char **)malloc(sizeof(char *) * (words + 1));
	if (res_split == NULL)
		return (NULL);
	res_split[words] = 0;
	alloc_split(s, c, res_split);
	return (res_split);
}
