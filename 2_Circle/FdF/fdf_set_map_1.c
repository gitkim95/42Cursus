/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:37:18 by gitkim            #+#    #+#             */
/*   Updated: 2024/11/13 22:16:31 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"
#include <errno.h>

t_map_list	*fdf_maplist_last(t_map_list *node)
{
	while (node -> next)
		node = node -> next;
	return (node);
}

void	fdf_maplist_addback(t_map_list **head, t_map_list *new_node)
{
	t_map_list	*tail;

	if (!new_node)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		tail = fdf_maplist_last(*head);
		tail -> next = new_node;
	}
}

t_map_list	*fdf_maplist_newnode(char **maplist)
{
	t_map_list	*new_node;

	new_node = (t_map_list *)malloc(sizeof(t_map_list));
	if (!new_node)
		return (NULL);
	new_node->list = maplist;
	new_node->next = NULL;
	return (new_node);
}

void	set_map_size_n_list(t_fdf *fdf, t_map_list **temp, int fd)
{
	t_map_list	*node;
	char		*buf;
	char		**buf_split;
	int			cal_width;

	while (1)
	{
		buf = get_next_line(fd);
		if (!buf || !(*buf))
			break ;
		buf_split = ft_split(buf, ' ');
		free(buf);
		if (!buf_split)
			terminator(1, NULL, 0, "Allocation failed");
		cal_width = get_map_width(buf_split);
		node = fdf_maplist_newnode(buf_split);
		free_split(buf_split, NULL, 0);
		if (!node)
			terminator(4, *temp, 0, "Allocation failed");
		if (fdf->map.width && fdf->map.width != cal_width)
			terminator(4, *temp, 0, "File data incorrect");
		fdf_maplist_addback(temp, node);
		fdf->map.width = cal_width;
		fdf->map.height++;
	}
}

void	set_map_struct(t_fdf *fdf, char *file_path)
{
	t_map_list	*temp;
	int			fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		terminator(1, NULL, errno, "File open failed");
	temp = NULL;
	set_map_size_n_list(fdf, &temp, fd);
	close(fd);
	set_integer_map(fdf, &temp);
}
