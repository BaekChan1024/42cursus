/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:39:37 by seubaek           #+#    #+#             */
/*   Updated: 2021/09/24 11:15:42 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render(t_game *game)
{
	int		i;
	int		j;
	char	*s;

	validate_command(game);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			draw_unit(game, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->display.mlx,
		game->display.win, game->display.img.img, 0, 0);
	s = ft_itoa(game->player.step);
	mlx_string_put(game->display.mlx, game->display.win, 10, 10, 0x00FFFF, s);
	free(s);
	mlx_do_sync(game->display.mlx);
	return (0);
}

void	init_player(t_game *game, int x, int y)
{
	if (!(game->player.x < 0 && game->player.y < 0))
		ft_exit("다중 플레이어 입니다.");
	game->player.x = x;
	game->player.y = y;
}

void	init_exit(t_game *game, int x, int y)
{
	if (!(game->exit.x < 0 && game->exit.y < 0))
		ft_exit("출구가 여러개 입니다.");
	game->exit.x = x;
	game->exit.y = y;
}
