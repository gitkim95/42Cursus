/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 01:41:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/02 03:07:58 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char st, char c) 
{
	if (st == c || st == '\0')
		return (1);
	else
		return (0);

char	**ft_split(char const *s, char c)
{
	int	cnt_word;

	cnt_word = 
