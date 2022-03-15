#include "minishell.h"

static void	init_old_pwd_value(t_lst *env_list, char *old_pwd)
{
	t_lst	*cursor;

	cursor = env_list;
	while (cursor)
	{
		if (ft_strcmp(cursor->key, "OLDPWD") == 0)
		{
			free(cursor->value);
			cursor->value = old_pwd;
			return ;
		}
		cursor = cursor->next;
	}
}

static void	init_pwd_value(t_lst *env_list)
{
	char	*pwd;
	char	*old_pwd;
	t_lst	*cursor;

	pwd = 0;
	cursor = env_list;
	pwd = getcwd(pwd, 0);
	if (!pwd)
		return ;
	while (cursor)
	{
		if (ft_strcmp(cursor->key, "PWD") == 0 && ft_strcmp(pwd, cursor->key) != 0)
		{
			old_pwd = ft_strdup(cursor->value);
			free(cursor->value);
			cursor->value = pwd;
			init_old_pwd_value(env_list, old_pwd);
		}
		cursor = cursor->next;
	}
}

static char	*init_home_path(t_lst *env_list)
{
	t_lst	*cursor;

	cursor = env_list;
	while (cursor)
	{
		if (ft_strcmp(cursor->key, "HOME") == 0)
			return (cursor->value);
		cursor = cursor->next;
	}
	return (0);
}

int	mini_cd(char **argv, t_lst *env_list)
{
	char	*error_msg;
	char	*path;

	path = argv[1];
	if (!path || ft_strcmp(path, "~") == 0)
	{
		free(path);
		path = init_home_path(env_list);
	}
	if (!path)
	{
		free(path);
		write(2, "minishell: cd: HOME not set\n", 29);
	}
	if (chdir(path) == -1)
	{
		printf("minishell: cd: ");
		error_msg = strerror(errno);
		printf("%s: ", path);
		printf("%s\n", error_msg);
		return (1);
	}
	init_pwd_value(env_list);
	return (0);
}