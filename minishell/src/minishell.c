#include "minishell.h"

static void	close_fd(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->pipe[0] != 0)
			close(cmd->pipe[0]);
		if (cmd->pipe[1] != 1)
			close(cmd->pipe[1]);
		if (cmd->fd_in != 0)
			close(cmd->fd_in);
		if (cmd->fd_out != 1)
			close(cmd->fd_out);
		cmd = cmd->next;
	}
}

static int	exec_func(t_cmd *cmd, t_lst **env_lst)
{
	char	**env_arr;
	char	**path_arr;
	t_cmd	*prev;

	if (!cmd || !cmd->argv || !env_lst || cmd->fd_in < 0 || cmd->fd_out < 0 || \
	 !cmd->argv[0] || ft_strcmp(cmd->argv[0], "") == 0)
		return (1);
	prev = 0;
	while (cmd)
	{
		if (is_built_in(cmd->argv))
			exec_built_in(cmd, env_lst, prev);
		else
		{
			env_arr = make_env_arr(*env_lst);
			path_arr = parse_path(cmd->argv[0], *env_lst);
			execute_path(cmd, prev, env_arr, path_arr);
			free_2_arr(env_arr);
			free_2_arr(path_arr);
		}
		prev = cmd;
		cmd = cmd->next;
		if (prev->is_pipe == 1 && (cmd->fd_in != 0 || cmd->fd_out != 1))
			break ;
	}
	return (0);
}

static int	minishell(char *env[])
{
	t_lst	*env_lst;
	char	*input;
	t_cmd	*cmd;

	env_lst = 0;
	init_env_lst(&env_lst, env);
	while (1)
	{
		handle_signal();
		input = readline("minishell $ ");
		if (!input)
		{
			printf("exit\n");
			exit(g_status);
		}
		cmd = parsing(input, env_lst);
		exec_func(cmd, &env_lst);
		add_history(input);
		close_fd(cmd);
		free(input);
		free_cmd(cmd);
	}
	return (1);
}

static void	print_ascii(void)
{
	char	ascii[2860];
	int		result;
	int		fd;

	fd = open("./.ascii", O_RDONLY);
	result = read(fd, &ascii, 2860);
	write(1, ascii, result);
	close(fd);
}

int	main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	(void)env;

	print_ascii();
	minishell(env);
	return (0);
}
