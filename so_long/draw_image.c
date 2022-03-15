/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:38:48 by seubaek           #+#    #+#             */
/*   Updated: 2021/09/25 11:10:52 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_pixel_put(t_display *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.data + (y * data->img.size_l + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_mlx_get_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->data + (y * img->size_l + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

void	select_sprite(t_game *game, int i, int j)
{
	if (game->map.matrix[i][j] == '1')
		game->sprite = game->wall_img;
	else if (game->map.matrix[i][j] == 'C')
		game->sprite = game->item_img;
	else if (game->map.matrix[i][j] == 'P')
		game->sprite = game->player_img;
	else if (game->map.matrix[i][j] == 'E')
		game->sprite = game->exit_img;
}

void	put_sprite_pixel(t_game *game, int i, int j)
{
	int	x;
	int	y;

	x = (int)((float)game->y / game->unit * game->sprite.width);
	y = (int)((float)game->x / game->unit * game->sprite.height);
	if (ft_mlx_get_color(&game->sprite, x, y) != 0xFF000000)
		ft_mlx_pixel_put(&game->display, j * game->unit + game->y,
			i * game->unit + game->x,
			ft_mlx_get_color(&game->sprite, x, y));
}

void	draw_unit(t_game *game, int i, int j)
{
	game->x = 0;
	while (game->x < game->unit)
	{
		game->y = 0;
		while (game->y < game->unit)
		{
			if (game->player.x == game->exit.x
				&& game->player.y == game->exit.y
				&& i == game->player.x && j == game->player.y)
				game->sprite = game->exit_img;
			else
				game->sprite = game->floor_img;
			put_sprite_pixel(game, i, j);
			select_sprite(game, i, j);
			put_sprite_pixel(game, i, j);
			game->y++;
		}
		game->x++;
	}
}
