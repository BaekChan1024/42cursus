#include "minishell.h"

static int	is_printable(char c)
{
	if (' ' <= c && c <= '~')
	{
		if (c == ' ' || c == '\'' || c == '"')
			return (0);
		return (1);
	}
	return (0);
}

static int	len_none(char *input, int idx, t_lst *env_lst)
{
	int		len;
	int		i;

	i = idx;
	len = 0;
	while (is_printable(input[i]) && input[i])
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

static void	fill_str(char *input, int *i, t_lst *env_lst, char **str)
{
	int		idx;
	char	*env_str;
	int		len;
	int		env_idx;

	idx = 0;
	len = len_none(input, *i, env_lst);
	while (is_printable(input[*i]) && input[*i])
	{
		if (input[*i] == '$')
		{
			env_idx = 0;
			env_str = parse_doller(input, i, env_lst);
			if (!env_str)
				return ;
			while (env_str[env_idx])
				(*str)[idx++] = env_str[env_idx++];
			free(env_str);
		}
		else
			(*str)[idx++] = input[(*i)++];
	}
}

char	*parse_none(char *input, int *i, t_lst *env_lst)
{
	int		len;
	char	*temp;
	int		idx;

	len = len_none(input, *i, env_lst);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	idx = 0;
	temp[len] = 0;
	fill_str(input, i, env_lst, &temp);
	(*i)--;
	return (temp);
}
