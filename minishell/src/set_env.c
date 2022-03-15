#include "minishell.h"

static void	env_set_shlvl(t_lst *env_lst)
{
	t_lst	*head;
	int		num;

	head = env_lst;
	while (head)
	{
		if (ft_strcmp(head->key, "SHLVL") == 0)
		{
			num = ft_atoi(head->value);
			num++;
			free(head->value);
			head->value = ft_itoa(num);
			return ;
		}
		head = head->next;
	}
}

static void	env_set_oldpwd(t_lst *env_lst)
{
	t_lst	*head;

	head = env_lst;
	while (head)
	{
		if (ft_strcmp(head->key, "OLDPWD") == 0)
		{
			free(head->value);
			head->value = ft_strdup("");
			return ;
		}
		head = head->next;
	}
}

int	init_env_lst(t_lst **env_lst, char *env[])
{
	t_lst	*new;
	int		size;
	int		idx;

	size = 0;
	while (env[size])
		size++;
	idx = 0;
	while (idx < size)
	{
		new = env_lst_alloc(env[idx], idx);
		env_lst_add(env_lst, new);
		idx++;
	}
	env_set_shlvl(*env_lst);
	env_set_oldpwd(*env_lst);
	return (0);
}

char	**make_env_arr(t_lst *env_lst)
{
	char	**env_arr;
	int		size;
	char	*elem;
	char	*temp_elem;
	int		idx;

	size = lst_len(env_lst);
	idx = 0;
	env_arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!env_arr)
		return (0);
	env_arr[size] = 0;
	while (env_lst)
	{
		temp_elem = ft_strjoin(env_lst->key, "=");
		elem = ft_strjoin(temp_elem, env_lst->value);
		env_arr[idx] = elem;
		free(temp_elem);
		env_lst = env_lst->next;
		idx++;
	}
	return (env_arr);
}
