# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 09:43:53 by seubaek           #+#    #+#              #
#    Updated: 2021/09/23 11:08:28 by seubaek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = so_long.h
NAME = so_long
RM = rm -f
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit -lm
FILE = ./command\
		./draw_image\
		./get_next_line\
		./key_mapping\
		./main\
		./matrix\
		./parsing\
		./rendering\
		./utils\
		./utils2\
		./validate_parsing

SRC = $(addsuffix .c, $(FILE))
OBJ = $(addsuffix .o, $(FILE))

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C mlx
		$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) -o $(NAME)

clean:
	make clean -C mlx
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
