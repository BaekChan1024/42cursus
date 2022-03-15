/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:16:27 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/24 20:54:04 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_command(char *argv, t_cmd *cmd)
{
	char **dummy;

	dummy = ft_split(argv, ' ');
	cmd->cmd[0] = ft_strjoin("/bin/", dummy[0]);
	cmd->cmd[1] = ft_strjoin("/usr/bin/", dummy[0]);
	cmd->cmd[2] = ft_strjoin("/usr/sbin/", dummy[0]);
	cmd->cmd[3] = ft_strjoin("/sbin/", dummy[0]);
	cmd->cmd[4] = ft_strjoin("/usr/local/bin/", dummy[0]);
	cmd->argv = (char *const *)dummy;
}

void	run_command(char *cmd)
{
	int		i;
	t_cmd	cmd_new;

	i = 0;
	init_command(cmd, &cmd_new);
	while (i < 5)
		execve(cmd_new.cmd[i++], cmd_new.argv, NULL);
	perror(cmd_new.argv[0]);
}
