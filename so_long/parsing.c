/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:15:00 by seubaek           #+#    #+#             */
/*   Updated: 2021/09/24 10:47:44 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_game *game)
{
	game->player_img.img = mlx_xpm_file_to_image(game->display.mlx,
			"img/player.xpm", &game->player_img.width,
			&game->player_img.height);
	game->item_img.img = mlx_xpm_file_to_image(game->display.mlx,
			"img/item.xpm", &game->item_img.width,
			&game->item_img.height);
	game->wall_img.img = mlx_xpm_file_to_image(game->display.mlx,
			"img/wall.xpm", &game->wall_img.width, &game->wall_img.height);
	game->floor_img.img = mlx_xpm_file_to_image(game->display.mlx,
			"img/floor.xpm", &game->floor_img.width, &game->floor_img.height);
	game->exit_img.img = mlx_xpm_file_to_image(game->display.mlx,
			"img/exit.xpm", &game->exit_img.width, &game->exit_img.height);
}

void	load_image2(t_game *game)
{
	game->player_img.data = mlx_get_data_addr(game->player_img.img,
			&game->player_img.bpp, &game->player_img.size_l,
			&game->player_img.endian);
	game->item_img.data = mlx_get_data_addr(game->item_img.img,
			&game->item_img.bpp, &game->item_img.size_l,
			&game->item_img.endian);
	game->wall_img.data = mlx_get_data_addr(game->wall_img.img,
			&game->wall_img.bpp, &game->wall_img.size_l,
			&game->wall_img.endian);
	game->floor_img.data = mlx_get_data_addr(game->floor_img.img,
			&game->floor_img.bpp, &game->floor_img.size_l,
			&game->floor_img.endian);
	game->exit_img.data = mlx_get_data_addr(game->exit_img.img,
			&game->exit_img.bpp, &game->exit_img.size_l,
			&game->exit_img.endian);
}

void	init_game_value(t_game *game)
{
	game->cmd.valid = 1;
	game->player.x = -1;
	game->player.y = -1;
	game->exit.x = -1;
	game->exit.y = -1;
	game->player.step = 0;
	game->player.item = 0;
	game->player.clear = 0;
	game->state = 1;
	game->display.mlx = mlx_init();
}

t_game	init_game(int fd, char *path)
{
	t_matrix	matrix;
	t_game		game;

	validate_dot_ber(path);
	init_game_value(&game);
	matrix = row_col_value(fd);
	game.unit = 40;
	game.map.height = matrix.row;
	game.map.width = matrix.col;
	game.map.matrix = create_matrix(fd, matrix.row, matrix.col, path);
	find_element(&game);
	load_image(&game);
	load_image2(&game);
	validate_element(&game);
	validate_wall(&game);
	return (game);
}
