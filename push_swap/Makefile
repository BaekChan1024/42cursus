# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 19:01:47 by seungchanba       #+#    #+#              #
#    Updated: 2021/08/01 21:56:56 by seubaek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
NAME = push_swap
RM = rm -f

FILES = ./a_to_b\
		./all_command\
		./b_to_a\
		./case_five\
		./case_three_a\
		./case_three_b\
		./case_under_three\
		./check_arg\
		./command\
		./deque\
		./deque2\
		./push_swap\
		./utils\
		./utils2\
		./value

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
	$(RM) $(OBJ) $(NAME) push_swap.h.gch

re: fclean all

.PHONY: all clean fclean re
