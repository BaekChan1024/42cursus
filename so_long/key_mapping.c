/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:12:11 by seubaek           #+#    #+#             */
/*   Updated: 2021/09/25 10:24:41 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key_code, t_cmd *cmd)
{
	if (key_code == 53)
		exit(0);
	if ((key_code == 13 || key_code == 1 || key_code == 0 || key_code == 2)
		&& cmd->valid)
	{
		if (key_code == 13)
			cmd->up = 1;
		if (key_code == 1)
			cmd->down = 1;
		if (key_code == 0)
			cmd->right = 1;
		if (key_code == 2)
			cmd->left = 1;
		cmd->valid = 0;
	}
	return (0);
}

int	key_release(int key_code, t_cmd *cmd)
{
	if (key_code == 13 || key_code == 1 || key_code == 0 || key_code == 2)
	{
		if (key_code == 13)
			cmd->up = 0;
		if (key_code == 1)
			cmd->down = 0;
		if (key_code == 0)
			cmd->right = 0;
		if (key_code == 2)
			cmd->left = 0;
		cmd->valid = 1;
	}
	return (0);
}

int	destroy_hook(int key_code, t_game *game)
{
	(void)key_code;
	(void)game;
	exit(0);
	return (0);
}
