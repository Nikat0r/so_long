CC = cc

FLAGS = -L/usr/local/lib -lmlx -lXext -lX11 -lm -lz -Wall -Werror -Wextra

FILES = so_long.c so_long_utils.c so_long_utils_2.c ft_split.c ft_itoa.c parsing.c player.c hooking.c enemy.c

FILES_BONUS = bonus/so_long_bonus.c bonus/so_long_utils.c bonus/so_long_utils_2.c bonus/ft_split.c bonus/ft_itoa.c bonus/parsing_bonus.c bonus/player_bonus.c bonus/hooking_bonus.c

NAME = so_long

NAME_BONUS = so_long_bonus

all: $(NAME)

$(NAME) : $(FILES)
	$(CC) $(FILES) $(FLAGS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(FILES_BONUS)
	$(CC) $(FILES_BONUS) $(FLAGS) -o $(NAME_BONUS)

re: fclean all

re_bonus: clean bonus

fclean: clean
	rm -f $(NAME)
clean:
	rm -f $(NAME_BONUS)