/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 09:34:35 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/17 17:55:44 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		validate_newline(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	init_line(char **save, char **line, int idx)
{
	(*save)[idx] = '\0';
	*line = ft_strdup(*save);
}

int		reset_save(char **save, char **line, int idx)
{
	char	*temp;
	int		len;

	init_line(save, line, idx);
	len = ft_strlen(*save + idx + 1);
	if (len == 0)
	{
		free(*save);
		*save = 0;
		return (1);
	}
	temp = ft_strdup(*save + idx + 1);
	free(*save);
	*save = temp;
	return (1);
}

int		last_value(char **save, char **line)
{
	int idx;

	if (*save && ((idx = validate_newline(*save)) >= 0))
		return(reset_save(save, line, idx));
	if (*save)
	{
		*line = *save;
		*save = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[FOPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			idx;
	int			read_byte;

	if ((line == 0) || (fd < 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((read_byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_byte] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
		if (((idx = validate_newline(save[fd]))) >= 0)
			return (reset_save(&save[fd], line, idx));
	}
	if (read_byte < 0)
		return (-1);
	return (last_value(&save[fd], line));
}

