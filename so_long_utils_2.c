#include "so_long.h"

static char	*storage_array(void)
{
	char	*storage;

	storage = malloc(7 * sizeof(char));
	if (storage == NULL)
		return (NULL);
	storage[0] = '\0';
	storage[1] = '\0';
	storage[2] = '\0';
	storage[3] = '\0';
	storage[4] = 'A';
	storage[5] = 'A';
	storage[6] = '\0';
	return (storage);
}

static void	if_conditions(char **d_ptr, int i, int j, char *storage)
{
	if (d_ptr[i][j] == 'E')
		*storage = 'E';
	else if (d_ptr[i][j] == 'C')
		*(storage + 3) = 'C';
	else if (d_ptr[i][j] == 'P')
	{
		*(storage + 1) = 'P';
		*(storage + 4) += 1;
	}		
	else if (d_ptr[i][j] == 'X')
	{
		*(storage + 2) = 'X';
		*(storage + 5) += 1;
	}
	else if (d_ptr[i][j] != '1' && d_ptr[i][j] != '0')
	{
		ft_putstr("Error :\nInvalid map, your map contains wrong elements!\n");
		exit(1);
	}
}

char	*map_element_check_2(char **d_ptr, int count_y, int count_x, int i)
{
	//static for the NULL initialization for the if statement to avoid reintizializing storage each time the function gets called
	static char	*storage;
	int		j;

	if (!storage)
		storage = storage_array();
	j = 1;
	while (i < count_y && j < count_x)
	{
		if_conditions(d_ptr, i, j, storage);
		j++;
	}
	return (storage);
}

void	declarations(t_vars *vars)
{
	vars->enemy.pos_up = vars->enemy.y - 24;
	vars->enemy.pos_down = vars->enemy.y + 24;
	vars->enemy.pos_mid = vars->enemy.y;
	vars->enemy.counter = 0;
	vars->enemy.switch_int = -1;
}

void	sprite_animation(t_vars *vars)
{
	int	width;
	int	height;

	vars->wall_img = mlx_xpm_file_to_image(vars->mlx, "/Users/ababa/Cursus/so_long/Assets/Wall.xpm", &width, &height);
	vars->anim.img1 = mlx_xpm_file_to_image(vars->mlx, "/Users/ababa/Cursus/so_long/Assets/1.xpm", &width, &height);
	vars->anim.img2 = mlx_xpm_file_to_image(vars->mlx, "/Users/ababa/Cursus/so_long/Assets/attack.xpm", &width, &height);
}
