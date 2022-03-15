/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:11:51 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/24 20:55:16 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define CHILD 0

typedef struct	s_cmd
{
	const char		*cmd[5];
	char * const	*argv;
}				t_cmd;

# define FILE_1	1
# define FILE_2	4
# define CMD_1	2
# define CMD_2	3

char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);

void			init_command(char *argv, t_cmd *cmd);
void			run_command(char *cmd);
void			connect_pipe(int *pipefd, int fd);
int				output_redirection(const char *file);
int				input_redirection(const char *file);

#endif
