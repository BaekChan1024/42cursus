#include "minishell.h"

t_lst	*env_lst_new(char *key, char *value, int idx)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (0);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->idx = idx;
	new->next = 0;
	return (new);
}

void	env_lst_add(t_lst **lst, t_lst *new)
{
	t_lst	*head;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	head = *lst;
	while (head->next)
		head = head->next;
	head->next = new;
}

t_lst	*env_lst_alloc(char *str, int lst_idx)
{
	char	*key;
	char	*value;
	int		idx;
	t_lst	*new;

	idx = 0;
	while (str[idx] && str[idx] != '=')
		idx++;
	if (str[idx] == 0)
	{
		key = str;
		value = "";
	}
	else
	{
		str[idx] = 0;
		key = str;
		value = str + idx + 1;
	}
	new = env_lst_new(key, value, lst_idx);
	return (new);
}
