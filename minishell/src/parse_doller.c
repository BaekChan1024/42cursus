#include "minishell.h"

int	len_doller(char *input, int *idx)
{
	int	len;

	len = 0;
	(*idx)++;
	while (input[*idx] && input[*idx] != ' ')
		(*idx)++;
	len++;
	return (len);
}

static char	*replace_doller(char *str, t_lst *env_lst)
{
	char	*ret;

	if (str[0] == '?')
		return (ft_itoa(g_status));
	while (env_lst)
	{
		if (ft_strcmp(env_lst->key, str) == 0)
		{
			free(str);
			ret = ft_strdup(env_lst->value);
			return (ret);
		}
		env_lst = env_lst->next;
	}
	free(str);
	return (ft_strdup(""));
}

char	*parse_doller(char *input, int *i, t_lst *env_lst)
{
	int		len;
	char	*temp;

	len = 0;
	(*i)++;
	while (input[*i + len] && input[*i + len] != ' ' && \
	input[*i + len] != '$' && input[*i + len] != '"' && input[*i + len] != '\'')
		len++;
	temp = replace_doller(ft_substr(input, *i, len), env_lst);
	*i += len;
	return (temp);
}
