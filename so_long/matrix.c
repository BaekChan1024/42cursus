/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:29:07 by seubaek           #+#    #+#             */
/*   Updated: 2021/09/24 10:14:37 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_matrix	row_col_value(int fd)
{
	t_matrix	matrix;
	int			roop;
	char		*line;
	int			row;
	int			col;

	roop = 1;
	line = NULL;
	row = 0;
	while (roop)
	{
		roop = get_next_line(fd, &line);
		col = ft_strlen(line);
		free(line);
		row++;
		if (!roop)
			break ;
	}
	matrix.col = col;
	matrix.row = row;
	return (matrix);
}

void	find_element(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.matrix[i][j] == 'C')
				game->player.clear++;
			if (game->map.matrix[i][j] == 'P')
				init_player(game, i, j);
			if (game->map.matrix[i][j] == 'E')
				init_exit(game, i, j);
			j++;
		}
		i++;
	}
}

static char	**create_matrix_sub(int fd, char *line, int col, char **matrix)
{
	int	i;
	int	j;
	int	roop;

	i = 0;
	roop = 1;
	while (roop)
	{
		roop = get_next_line(fd, &line);
		j = 0;
		if ((int)ft_strlen(line) != col)
			ft_exit("직사각형이 아닙니다");
		while (j < col)
		{
			matrix[i][col] = 0;
			matrix[i][j] = line[j];
			j++;
		}
		i++;
		free(line);
		if (!roop)
			break ;
	}
	close(fd);
	return (matrix);
}

char	**create_matrix(int fd, int row, int col, char *path)
{
	char	**matrix;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	matrix = (char **)malloc(sizeof(char *) * row);
	while (i < row)
		matrix[i++] = (char *)malloc(sizeof(char) * col + 1);
	fd = open(path, O_RDONLY);
	matrix = create_matrix_sub(fd, line, col, matrix);
	return (matrix);
}
