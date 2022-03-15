#include "minishell.h"

void	free_token(t_token *token_list)
{
	t_token	*cursur;

	cursur = token_list;
	while (cursur)
	{
		free(cursur->content);
		free(cursur);
		cursur = cursur->next;
	}
}

void	free_2_arr(char **str)
{
	int	idx;

	idx = 0;
	if (!str)
		return ;
	while (str[idx])
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		free_2_arr(tmp->argv);
		free(tmp);
		tmp = tmp->next;
	}
}