#include "minishell.h"

char	*cnt_join(char *s1, char *s2, int idx, int r_idx)
{
	char	*ret;
	int		len;

	if (!s1)
	{
		ret = ft_strdup(s2);
		free(s2);
		return (ret);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = 0;
	while (s1[idx])
		ret[r_idx++] = s1[idx++];
	free(s1);
	idx = 0;
	while (s2[idx])
		ret[r_idx++] = s2[idx++];
	free(s2);
	return (ret);
}

int	lst_len(t_lst *lst)
{
	int		idx;

	idx = 0;
	while (lst)
	{
		lst = lst->next;
		idx++;
	}
	return (idx);
}

int	check_multi_n(char *str)
{
	int		idx;

	idx = 0;
	if (str[idx] != '-')
		return (0);
	idx++;
	while (str[idx])
	{
		if (str[idx] != 'n')
			return (0);
		idx++;
	}
	return (1);
}
