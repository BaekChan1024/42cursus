# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 17:25:37 by seubaek           #+#    #+#              #
#    Updated: 2021/06/10 16:32:19 by seubaek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
NAME = libftprintf.a
AR = ar rc
RM = rm -f

FILES = ft_printf \
		utils1 \
		utils2 \
		utils3 \
		utils4 \
		ft_check_cond \
		ft_check \
		ft_cond1 \
		ft_cond2 \
		ft_output \


PRINTF_DIR = ./

PRINTF = $(addprefix $(PRINTF_DIR), $(addsuffix .c, $(FILES)))

OBJ =   $(addprefix $(PRINTF_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: clean all
