all :
	gcc -L/usr/local/lib -lmlx -lXext -lX11 -lm -lz so_long.c so_long_utils.c ft_split.c -o so_long
clean:
	rm so_long