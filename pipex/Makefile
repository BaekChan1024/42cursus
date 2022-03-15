# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 19:24:45 by seubaek           #+#    #+#              #
#    Updated: 2021/06/24 20:33:46 by seubaek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = pipex.h
NAME = pipex
RM = rm -f

FILES = ./pipex\
		./command\
		./libft/ft_split\
		./libft/ft_strjoin

SRC = $(addsuffix .c, $(FILES))

OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME) pipex.h.gch

re: fclean all
