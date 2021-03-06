#include "minishell.h"

static int	print_error(char *path)
{
	printf("minishell: %s: command not found\n", path);
	return (127);
}

static void	modify_g_status(void)
{
	if (g_status == 2)
		g_status = 130;
	else if (g_status == 3)
		g_status = 131;
	else
		g_status = WEXITSTATUS(g_status);
}

static char	*validate_path(char *arg, char **path_arr)
{
	int	ret;
	struct stat	f_stat;
	int	idx;

	idx = 0;
	while (path_arr[idx])
	{
		ret = stat(path_arr[idx], &f_stat);
		if (ret == 0)
			return (path_arr[idx]);
		idx++;
	}
	return (arg);
}

void	execute_path(t_cmd *cmd, t_cmd *prev, char **env_arr, char **path_arr)
{
	int	pid;
	char	*path;

	path = validate_path(cmd->argv[0], path_arr);
	pid = fork();
	if (pid > 0)
	{
		handle_signal_child();
		waitpid(pid, &g_status, 0);
		modify_g_status();
		if (prev)
			close(prev->pipe[0]);
		close(cmd->pipe[1]);
		handle_signal();
	}
	else if (pid == 0)
	{
		set_redirect_and_pipe(cmd, prev);
		if (execve(path, cmd->argv, env_arr) == -1)
			exit(print_error(path));
	}
	else
		printf("%s\n", strerror(errno));
}