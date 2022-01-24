all :
	gcc so_long.c so_long_utils.c ft_split.c ft_itoa.c parsing.c player.c -L/usr/local/lib -lmlx -lXext -lX11 -lm -lz -Wall -Werror -Wextra   -o so_long
clean:
	rm so_long