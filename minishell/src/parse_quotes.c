#include "minishell.h"

static int	len_dquote(char *input, int idx, t_lst *env_lst)
{
	int		len;
	int		i;

	i = idx;
	len = 0;
	while (input[i] != '"' && input[i])
	{
		if (input[i] == '$')
		{
			i++;
			len += get_env_str_len(input, &i, env_lst);
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

static int	trans_doller(int *idx, char *env_str, char **str)
{
	int		env_idx;

	env_idx = 0;
	if (!env_str)
		return (1);
	while (env_str[env_idx])
		(*str)[(*idx)++] = env_str[env_idx++];
	return (0);
}

static void	fill_str(char *input, int *i, t_lst *env_lst, char **str)
{
	int		idx;
	char	*env_str;
	int		len;

	idx = 0;
	len = len_dquote(input, *i, env_lst);
	while (idx < len)
	{
		if (input[*i] == '$')
		{
			env_str = parse_doller(input, i, env_lst);
			if (trans_doller(&idx, env_str, str) == 1)
				return ;
		}
		else
			(*str)[idx++] = input[(*i)++];
	}
	if (input[*i] == '$')
	{
		env_str = parse_doller(input, i, env_lst);
		if (trans_doller(&idx, env_str, str) == 1)
			return ;
	}
	free(env_str);
}

char	*parse_dquote(char *input, int *i, t_lst *env_lst)
{
	int		len;
	char	*temp;

	(*i)++;
	len = len_dquote(input, *i, env_lst);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	temp[len] = 0;
	if (len != 0)
		fill_str(input, i, env_lst, &temp);
	return (temp);
}

char	*parse_quote(char *input, int *i)
{
	int		len;
	char	*temp;

	len = 0;
	(*i)++;
	while (input[*i + len] && input[*i + len] != '\'')
		len++;
	temp = ft_substr(input, *i, len);
	*i += len;
	return (temp);
}
