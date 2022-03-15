#include "minishell.h"

static t_cmd	*init_node(void)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->argv = 0;
	new->fd_in = 0;
	new->fd_out = 1;
	new->is_pipe = 0;
	new->pipe[0] = 0;
	new->pipe[1] = 1;
	new->next = 0;
	return (new);
}

static void	make_list(t_cmd **cmd)
{
	t_cmd	*cursor;

	if (!(*cmd))
	{
		*cmd = init_node();
		return ;
	}
	cursor = *cmd;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = init_node();
}

static int	count_pipe(t_token *list)
{
	t_token	*cursor;
	int		cnt;

	cursor = list;
	cnt = 1;
	while (list)
	{
		if (list->type == PIPE)
			cnt++;
		list = list->next;
	}
	return (cnt);
}

static t_cmd	*set_list(t_token *token_list)
{
	t_cmd	*temp;
	t_token	*cursor;
	int		len;

	cursor = token_list;
	len = count_pipe(cursor);
	temp = 0;
	while (len--)
		make_list(&temp);
	return (temp);
}

t_cmd	*init_cmd(t_token *token_list)
{
	t_cmd	*cmd;
	t_token	*t_cursor;
	t_cmd	*c_cursor;

	cmd = set_list(token_list);
	t_cursor = token_list;
	c_cursor = cmd;
	while (t_cursor)
	{
		c_cursor->argv = init_argv(t_cursor);
		check_redirection(t_cursor, &c_cursor->fd_in, &c_cursor->fd_out);
		pipe(c_cursor->pipe);
		while (t_cursor && t_cursor->type != PIPE)
			t_cursor = t_cursor->next;
		if (t_cursor)
		{
			t_cursor = t_cursor->next;
			c_cursor->is_pipe = 1;
		}
		if (t_cursor && c_cursor)
			c_cursor = c_cursor->next;
	}
	return (cmd);
}
