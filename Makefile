CC = cc

FLAGS = -L/usr/local/lib -lmlx -lXext -lX11 -lm -lz -Wall -Werror -Wextra

FILES = so_long.c so_long_utils.c so_long_utils_2.c ft_split.c ft_itoa.c parsing.c player.c hooking.c

#FILES_BONUS =

NAME = so_long

#NAME_BONUS = server_bonus client_bonus

all: $(NAME)

$(NAME) : $(FILES)
	$(CC) $(FILES) $(FLAGS) -o $(NAME)

#bonus: $(NAME_BONUS)

#$(NAME_BONUS):
#	$(CC) $(FLAGS) $(SERVER_BONUS) -o server_bonus
#	$(CC) $(FLAGS) $(CLIENT_BONUS) -o client_bonus

re: fclean all

#re_bonus: clean bonus

fclean: #clean
	rm -f $(NAME)
#clean:
#	rm -f $(NAME_BONUS)