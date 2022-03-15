/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:00:45 by seubaek           #+#    #+#             */
/*   Updated: 2021/09/25 11:21:54 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_command(t_game *game)
{
	if (game->cmd.up && !game->cmd.down && !game->cmd.left && !game->cmd.right)
	{
		if (!(game->map.matrix[game->player.x - 1][game->player.y] == '1'))
		{
			game->player.step++;
			if (game->map.matrix[game->player.x - 1][game->player.y] == 'C')
				game->player.item++;
			if (game->player.x == game->exit.x
				&& game->player.y == game->exit.y)
				game->map.matrix[game->player.x][game->player.y] = 'E';
			else
				game->map.matrix[game->player.x][game->player.y] = '0';
			game->player.x--;
			if (game->map.matrix[game->player.x][game->player.y] == 'E'
				&& game->player.item >= game->player.clear)
				exit(0);
			game->map.matrix[game->player.x][game->player.y] = 'P';
			game->cmd.up = 0;
		}
	}
}

void	right_command(t_game *game)
{
	if (game->cmd.right && !game->cmd.left && !game->cmd.up && !game->cmd.down)
	{
		if (!(game->map.matrix[game->player.x][game->player.y - 1] == '1'))
		{
			game->player.step++;
			if (game->map.matrix[game->player.x][game->player.y - 1] == 'C')
				game->player.item++;
			if (game->player.x == game->exit.x
				&& game->player.y == game->exit.y)
				game->map.matrix[game->player.x][game->player.y] = 'E';
			else
				game->map.matrix[game->player.x][game->player.y] = '0';
			game->player.y--;
			if (game->map.matrix[game->player.x][game->player.y] == 'E'
				&& game->player.item >= game->player.clear)
				exit(0);
			game->map.matrix[game->player.x][game->player.y] = 'P';
			game->cmd.right = 0;
		}
	}
}

void	down_command(t_game *game)
{
	if (game->cmd.down && !game->cmd.left && !game->cmd.right && !game->cmd.up)
	{
		if (!(game->map.matrix[game->player.x + 1][game->player.y] == '1'))
		{
			game->player.step++;
			if (game->map.matrix[game->player.x + 1][game->player.y] == 'C')
				game->player.item++;
			if (game->player.x == game->exit.x
				&& game->player.y == game->exit.y)
				game->map.matrix[game->player.x][game->player.y] = 'E';
			else
				game->map.matrix[game->player.x][game->player.y] = '0';
			game->player.x++;
			if (game->map.matrix[game->player.x][game->player.y] == 'E'
				&& game->player.item >= game->player.clear)
				exit(0);
			game->map.matrix[game->player.x][game->player.y] = 'P';
			game->cmd.down = 0;
		}
	}
}

void	left_command(t_game *game)
{
	if (game->cmd.left && !game->cmd.right && !game->cmd.up && !game->cmd.down)
	{
		if (!(game->map.matrix[game->player.x][game->player.y + 1] == '1'))
		{
			game->player.step++;
			if (game->map.matrix[game->player.x][game->player.y + 1] == 'C')
				game->player.item++;
			if (game->player.x == game->exit.x
				&& game->player.y == game->exit.y)
				game->map.matrix[game->player.x][game->player.y] = 'E';
			else
				game->map.matrix[game->player.x][game->player.y] = '0';
			game->player.y++;
			if (game->map.matrix[game->player.x][game->player.y] == 'E'
				&& game->player.item >= game->player.clear)
				exit(0);
			game->map.matrix[game->player.x][game->player.y] = 'P';
			game->cmd.left = 0;
		}
	}
}

void	validate_command(t_game *game)
{
	if (game->state)
	{
		up_command(game);
		down_command(game);
		left_command(game);
		right_command(game);
	}
}
