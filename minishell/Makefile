NAME = minishell

RLDIR = /opt/homebrew/opt/readline

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LINK = -L $(RLDIR)/lib -L ./libft/ -lft -lreadline
INCLUDE = -I ./libft -I ./include -I $(RLDIR)/include

SRC_DIR = ./src/
SRC_NAME = minishell.c signal.c set_env.c lst_utils.c \
			parsing.c parse_utils.c quote_utils.c \
			parse_doller.c parse_quotes.c parse_none.c \
			tocken.c tocken_utils.c free.c\
			utils.c init_cmd.c init_argv.c check_redirection.c \
			built_in.c mini_echo.c mini_pwd.c mini_unset.c \
			mini_export.c mini_env.c mini_cd.c mini_exit.c\
			parse_path.c execute_func.c

SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))
OBJ = $(SRC:.c=.o)
LIB = ./libft/libft.a

all: $(NAME)
$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(LINK) $(OBJ) -o $@
$(LIB):
	make -C ./libft/ all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C ./libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all

.PHONY : all clean fclean re
