/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:33:49 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/02 00:32:20 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "microshell.h"

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(int fd, char *str)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}

void	ft_error(char *msg, char *obj)
{
	ft_putstr(STDERR_FILENO, msg);
	ft_putstr(STDERR_FILENO, obj);
	ft_putstr(STDERR_FILENO, "\n");
}

char	*ft_strdup(char *str)
{
	char	*new_str;
	int		i = 0;

	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}