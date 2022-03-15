/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:27:31 by seubaek           #+#    #+#             */
/*   Updated: 2021/09/25 10:42:01 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_dot_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!ft_strnstr(str, ".ber", len) || 4 != ft_strlen(ft_strnstr(str,
				".ber", len)))
		ft_exit(".ber 형식에 파일이어야 합니다.");
}

void	validate_element(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->map.height - 1)
	{
		j = 1;
		while (j < game->map.width - 1)
		{
			if (game->map.matrix[i][j] != 'P' && game->map.matrix[i][j] != 'E'
			&& game->map.matrix[i][j] != '1' && game->map.matrix[i][j] != '0'
			&& game->map.matrix[i][j] != 'C' && game->map.matrix[i][j] != 'F')
				ft_exit("다른 요소가 들어갔습니다");
			j++;
		}
		i++;
	}
}

void	validate_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
		if (game->map.matrix[0][i++] != '1')
			ft_exit("벽으로 둘러쌓여 있어야 합니다.");
	i = 0;
	while (i < game->map.height)
		if (game->map.matrix[i++][game->map.width - 1] != '1')
			ft_exit("벽으로 둘러쌓여 있어야 합니다.");
	i = 0;
	while (i < game->map.height)
		if (game->map.matrix[i++][0] != '1')
			ft_exit("벽으로 둘러쌓여 있어야 합니다.");
	i = 0;
	while (i < game->map.width)
		if (game->map.matrix[game->map.height - 1][i++] != '1')
			ft_exit("벽으로 둘러쌓여 있어야 합니다.");
}
