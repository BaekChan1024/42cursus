/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:56:25 by seubaek           #+#    #+#             */
/*   Updated: 2021/09/24 10:47:33 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_newline(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	init_line(char **save, char **line, int idx)
{
	(*save)[idx] = '\0';
	*line = ft_strdup(*save);
}

static int	reset_save(char **save, char **line, int idx)
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

static int	last_value(char **save, char **line)
{
	int	idx;

	idx = validate_newline(*save);
	if (*save && (idx >= 0))
		return (reset_save(save, line, idx));
	if (*save)
	{
		*line = *save;
		*save = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[FOPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			idx;
	int			read_byte;

	if ((line == 0) || (fd < 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while (1)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte <= 0)
			break ;
		buf[read_byte] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
		idx = validate_newline(save[fd]);
		if (idx >= 0)
			return (reset_save(&save[fd], line, idx));
	}
	if (read_byte < 0)
		return (-1);
	return (last_value(&save[fd], line));
}
