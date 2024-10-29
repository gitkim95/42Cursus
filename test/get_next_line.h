/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:17:47 by hwilkim           #+#    #+#             */
/*   Updated: 2024/10/29 02:43:31 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_gnl_node
{
	char				*buf;
	struct s_gnl_node	*next;
}	t_gnl_node;

typedef struct s_gnl_list
{
	t_gnl_node	*head;
}	t_gnl_list;

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strcat(char *dest, char const *src);
char	*ft_strjoin(char const *s1, char const *s2);
void	leak_handle(t_gnl_list *fd_list);

char	*get_next_line(int fd);

#endif
