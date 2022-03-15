/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:17:19 by seubaek           #+#    #+#             */
/*   Updated: 2021/09/25 11:30:24 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"

typedef struct s_matrix
{
	int	row;
	int	col;
}				t_matrix;

typedef struct s_map
{
	int		width;
	int		height;
	char	**matrix;
}				t_map;

typedef struct s_cmd
{
	int	up;
	int	down;
	int	right;
	int	left;
	int	valid;
}				t_cmd;

typedef struct s_img
{
	void	*img;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_display
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_display;

typedef struct s_player
{
	int	x;
	int	y;
	int	item;
	int	clear;
	int	step;
}				t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}				t_exit;

typedef struct s_game
{
	int			x;
	int			y;
	int			state;
	int			unit;
	t_map		map;
	t_exit		exit;
	t_player	player;
	t_cmd		cmd;
	t_display	display;
	t_img		sprite;
	t_img		player_img;
	t_img		item_img;
	t_img		wall_img;
	t_img		floor_img;
	t_img		exit_img;
}				t_game;

int				get_next_line(int fd, char **line);
char			**create_matrix(int fd, int row, int col, char *path);
t_matrix		row_col_value(int fd);
void			find_element(t_game *game);
int				key_press(int key_code, t_cmd *cmd);
int				key_release(int key_code, t_cmd *cmd);
int				destroy_hook(int key_code, t_game *game);
void			init_player(t_game *game, int x, int y);
void			init_exit(t_game *game, int x, int y);
void			init_game_value(t_game *game);
t_game			init_game(int fd, char *path);
void			load_image2(t_game *game);
void			load_image(t_game *game);
void			up_command(t_game *game);
void			right_command(t_game *game);
void			down_command(t_game *game);
void			left_command(t_game *game);
void			validate_command(t_game *game);
void			ft_mlx_pixel_put(t_display *data, int x, int y, int color);
unsigned int	ft_mlx_get_color(t_img *img, int x, int y);
void			select_sprite(t_game *game, int i, int j);
void			put_sprite_pixel(t_game *game, int i, int j);
void			draw_unit(t_game *game, int i, int j);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);
char			*ft_itoa(int num);
void			ft_exit(char *msg);
int				get_digit(int num);
void			validate_dot_ber(char *str);
void			validate_element(t_game *game);
void			validate_wall(t_game *game);
int				ft_render(t_game *game);

#endif
