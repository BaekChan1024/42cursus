#include "minishell.h"

static int	count_str(char *s, char c)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len++;
			s++;
			while (*s && *s != c)
				s++;
		}
	}
	return (len);
}

static void	init_split_element(char **arr, char *str, char c, char *arg)
{
	int		i;
	int		j;
	int		idx;
	char	*s;

	idx = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] && str[i + j] != c)
				j++;
			s = ft_substr(str, i, j);
			arr[idx] = ft_strjoin(s, arg);
			free(s);
			i += j;
			idx++;
		}
	}
}

static char	**path_split(char *s, char *arg, char c)
{
	char	**ret;
	int		len;
	char	*str;

	str = (char *)s;
	len = count_str(str, c);
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = 0;
	init_split_element(ret, str, c, arg);
	free(arg);
	return (ret);
}

char	**parse_path(char *arg, t_lst *env_list)
{
	char	**path_arr;
	char	*path;

	if (!arg)
		return (0);
	while (env_list)
	{
		if (ft_strcmp(env_list->key, "PATH") == 0)
			path = ft_strdup(env_list->value);
		env_list = env_list->next;
	}
	path_arr = path_split(path, ft_strjoin("/", arg), ':');
	free(path);
	return (path_arr);
}
