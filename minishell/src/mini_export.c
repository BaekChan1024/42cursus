#include "minishell.h"

static void	print_export(t_lst *env_lst)
{
	while (env_lst)
	{
		printf("declare -x ");
		printf("%s", env_lst->key);
		if (ft_strcmp(env_lst->value, "") == 0)
			printf("\n");
		else
			printf("=\"%s\"\n", env_lst->value);
		env_lst = env_lst->next;
	}
}

static void	swap_lst(t_lst *curr, t_lst *next)
{
	char	*temp_key;
	char	*temp_value;
	int		temp_idx;

	temp_key = curr->key;
	temp_value = curr->value;
	temp_idx = curr->idx;
	curr->key = next->key;
	curr->value = next->value;
	curr->idx = next->idx;
	next->key = temp_key;
	next->value = temp_value;
	next->idx = temp_idx;
}

static int	print_sort_export(t_lst **env_lst)
{
	t_lst	*curr;
	t_lst	*next;
	int		size;

	size = lst_len(*env_lst);
	while (size--)
	{
		curr = *env_lst;
		next = curr->next;
		while (next)
		{
			if (ft_strcmp(curr->key, next->key) > 0)
				swap_lst(curr, next);
			curr = curr->next;
			next = next->next;
		}
	}
	print_export(*env_lst);
	return (0);
}

static int	export_add_env(t_lst **env_lst, char *str)
{
	t_lst	*new;
	t_lst	*head;
	int		size;

	head = *env_lst;
	size = lst_len(*env_lst);
	new = env_lst_alloc(str, size);
	while (head)
	{
		if (ft_strcmp(head->key, new->key) == 0)
		{
			free(head->key);
			free(head->value);
			head->key = ft_strdup(new->key);
			head->value = ft_strdup(new->value);
			free(new->key);
			free(new->value);
			free(new);
			return (0);
		}
		head = head->next;
	}
	env_lst_add(env_lst, new);
	return (0);
}

int	mini_export(t_lst **env_lst, char *argv[])
{
	int	idx;
	int	ret;

	ret = 0;
	idx = 1;
	if (!argv[idx])
		ret = print_sort_export(env_lst);
	else
	{
		while (argv[idx])
		{
			ret = export_add_env(env_lst, argv[idx]);
			idx++;
		}
	}
	return (ret);
}
