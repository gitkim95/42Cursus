#include <stdlib.h>
#include "exam04.h"

t_cmd	*make_node(char **cmd, int cmd_len)
{
	t_cmd	*new_node;
	int		idx;

	new_node = (t_cmd *)malloc(sizeof(t_cmd));
	new_node->cmd = (char **)malloc(sizeof(char *) * cmd_len + 1);
	idx = 0;
	while (idx < cmd_len)
	{
		new_node->cmd[idx] = ft_strdup(cmd[idx]);
		idx++;
	}
	new_node->cmd[idx] = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	list_add_back(t_list *cmd_list, t_cmd *node)
{
	if (!cmd_list->head)
	{
		cmd_list->head = node;
		cmd_list->tail = node;
		return ;
	}
	else
	{
		cmd_list->tail->next = node;
		node->prev = cmd_list->tail;
		cmd_list->tail = node;
	}
}

void	make_list(t_list *cmd_list, char **cmd, int *pipe_idx, int pipe_num)
{
	t_cmd	*node;
	int		cmd_len;
	int 	idx;
	int		et;

	cmd_list->cmd_size = 0;
	cmd_list->head = NULL;
	cmd_list->tail = NULL;
	idx = 0;
	et = 0;
	while (et < pipe_num + 1)
	{
		cmd_len = pipe_idx[et] - idx;
		node = make_node(cmd + idx, cmd_len);
		list_add_back(cmd_list, node);
		cmd_list->cmd_size++;
		idx = pipe_idx[et] + 1;
		et++;
	}
}
