#include "minishell.h"

int	is_built_in(char *argv[])
{
	if (ft_strcmp(argv[0], "echo") == 0 || \
		ft_strcmp(argv[0], "cd") == 0 || \
		ft_strcmp(argv[0], "pwd") == 0 || \
		ft_strcmp(argv[0], "unset") == 0 || \
		ft_strcmp(argv[0], "export") == 0 || \
		ft_strcmp(argv[0], "env") == 0 || \
		ft_strcmp(argv[0], "exit") == 0)
		return (1);
	else
		return (0);
}

void	set_redirect_and_pipe(t_cmd *cmd, t_cmd *prev)
{
	if (cmd->fd_in != 0)
		dup2(cmd->fd_in, 0);
	else if (prev && prev->is_pipe == 1)
		dup2(prev->pipe[0], 0);
	if (cmd->fd_out != 1)
		dup2(cmd->fd_out, 1);
	else if (cmd->is_pipe == 1)
		dup2(cmd->pipe[1], 1);
}

int	exec_built_in_func(char *argv[], t_lst **env_lst)
{
	int	ret;

	ret = 0;
	if (ft_strncmp(argv[0], "echo", 4) == 0)
		mini_echo(argv);
	else if (ft_strcmp(argv[0], "cd") == 0)
		ret = mini_cd(argv, *env_lst);
	else if (ft_strcmp(argv[0], "pwd") == 0)
		ret = mini_pwd();
	else if (ft_strcmp(argv[0], "unset") == 0)
		ret = mini_unset(env_lst, argv);
	else if (ft_strcmp(argv[0], "export") == 0)
		ret = mini_export(env_lst, argv);
	else if (ft_strcmp(argv[0], "env") == 0)
		ret = mini_env(*env_lst);
	else if (ft_strcmp(argv[0], "exit") == 0)
		ret = mini_exit(argv);
	return (ret);
}

static void	exec_fork_case(t_cmd *cmd, t_lst **env_lst, t_cmd *prev)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		set_redirect_and_pipe(cmd, prev);
		g_status = exec_built_in_func(cmd->argv, env_lst);
		exit(g_status);
	}
	else if (pid > 0)
	{
		waitpid(pid, &g_status, 0);
		g_status = WEXITSTATUS(g_status);
		if (prev)
			close(prev->pipe[0]);
		close(cmd->pipe[1]);
	}
	else if (pid < 0)
		printf("%s\n", strerror(errno));
}

void	exec_built_in(t_cmd *cmd, t_lst **env_lst, t_cmd *prev)
{
	int	temp[2];

	pipe(temp);
	if (cmd->is_pipe != 0)
		exec_fork_case(cmd, env_lst, prev);
	else
	{
		dup2(0, temp[0]);
		dup2(1, temp[1]);
		if (cmd->fd_in != 0)
			dup2(cmd->fd_in, 0);
		if (cmd->fd_out != 1)
			dup2(cmd->fd_out, 1);
		g_status = exec_built_in_func(cmd->argv, env_lst);
		dup2(temp[0], 0);
		dup2(temp[1], 1);
		close(temp[0]);
		close(temp[1]);
		if (cmd->fd_in != 0)
			close(cmd->fd_in);
		if (cmd->fd_out != 1)
			close(cmd->fd_out);
	}
}
