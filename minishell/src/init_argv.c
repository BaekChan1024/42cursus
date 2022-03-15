#include "minishell.h"

static char	**malloc_argv(t_token *token)
{
	char	**argv;
	t_token	*cursor;
	int		len;

	len = 0;
	cursor = token;
	while (cursor && cursor->type != PIPE)
	{
		if (cursor->type == WORD)
			len++;
		cursor = cursor->next;
	}
	argv = (char **)malloc(sizeof(char *) * len + 1);
	if (!argv)
		return (NULL);
	argv[len] = 0;
	return (argv);
}

static void	init_element(t_token *token, char **str)
{
	char	**argv;
	t_token	*cursor;
	int		idx;

	cursor = token;
	idx = 0;
	argv = str;
	while (cursor && cursor->type != PIPE)
	{
		if (cursor->type == WORD)
		{
			argv[idx] = ft_strdup(cursor->content);
			idx++;
		}
		cursor = cursor->next;
	}
}

char	**init_argv(t_token *token)
{
	char	**argv;

	if (!token)
		return (0);
	argv = malloc_argv(token);
	init_element(token, argv);
	return (argv);
}
