#include "minishell.h"

int	get_env_str_len(char *input, int *idx, t_lst *env_lst)
{
	int		key_len;
	char	*key;
	int		len;

	key_len = 0;
	len = 0;
	while (input[*idx + key_len] && input[*idx + key_len] != ' ' && \
	input[*idx + key_len] != '$' && input[*idx + key_len] != '"' && \
	input[*idx + key_len] != '\'')
		key_len++;
	key = ft_substr(input, *idx, key_len);
	*idx += key_len;
	while (env_lst)
	{
		if (ft_strcmp(env_lst->key, key) == 0)
			len += ft_strlen(env_lst->value);
		env_lst = env_lst->next;
	}
	free(key);
	return (len);
}
