#include "minishell.h"

t_token	*token_new(char *content)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	new->content = content;
	new->type = -1;
	new->next = 0;
	return (new);
}

int	token_add(t_token **lst, t_token *new)
{
	t_token	*head;

	if (!(*lst))
	{
		*lst = new;
		return (0);
	}
	head = *lst;
	while (head->next)
		head = head->next;
	head->next = new;
	return (0);
}
