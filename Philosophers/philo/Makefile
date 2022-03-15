# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 16:09:36 by seubaek           #+#    #+#              #
#    Updated: 2022/02/13 19:17:09 by seubaek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = philo.h
NAME = philo
RM = rm -f

FILES = main \
		utils \
		philo \
		print \
		routine \
		time \

PHILO_DIR = ./

PHILO = $(addprefix $(PHILO_DIR), $(addsuffix .c, $(FILES)))

OBJ =   $(addprefix $(PHILO_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ 

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re: clean all
