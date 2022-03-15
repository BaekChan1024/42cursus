/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:22:26 by seubaek           #+#    #+#             */
/*   Updated: 2021/09/25 11:23:25 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	game = init_game(fd, argv[1]);
	game.display.win = mlx_new_window(game.display.mlx,
			game.map.width * game.unit,
			game.map.height * game.unit, "so_long");
	game.display.img.img = mlx_new_image(game.display.mlx,
			game.map.width * game.unit, game.map.height * game.unit);
	game.display.img.data = mlx_get_data_addr(game.display.img.img,
			&game.display.img.bpp, &game.display.img.size_l,
			&game.display.img.endian);
	mlx_hook(game.display.win, 2, 1L << 0, key_press, &(game.cmd));
	mlx_hook(game.display.win, 3, 1L << 1, key_release, &(game.cmd));
	mlx_hook(game.display.win, 17, 1L << 17, destroy_hook, &game);
	mlx_loop_hook(game.display.mlx, ft_render, &game);
	mlx_loop(game.display.mlx);
	close(fd);
	return (0);
}
