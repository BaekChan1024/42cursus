/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:10:52 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/24 20:54:58 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		input_redirection(const char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	return (0);
}

int		output_redirection(const char *file)
{
	int fd;

	if ((fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	return (0);
}

void	connect_pipe(int *pipefd, int fd)
{
	dup2(pipefd[fd], fd);
	close(pipefd[0]);
	close(pipefd[1]);
}

int		main(int argc, char **argv)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if (argc != 5)
		return (0);
	pipe(pipefd);
	pid = fork();
	if (pid > CHILD)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) == 0)
			exit(1);
		connect_pipe(pipefd, STDIN_FILENO);
		output_redirection(argv[FILE_2]);
		run_command(argv[CMD_2]);
	}
	else if (pid == CHILD)
	{
		connect_pipe(pipefd, STDOUT_FILENO);
		input_redirection(argv[FILE_1]);
		run_command(argv[CMD_1]);
	}
	return (0);
}
