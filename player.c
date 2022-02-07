#include "so_long.h"

static int	collectible_check(char **d_ptr)
{
	int	i;
	int	j;
	
	i = 0;
	while (d_ptr[i])
	{
		j = 0;
		while (d_ptr[i][j] != '\0')
		{
			if (d_ptr[i][j] == 'C')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
static int	button_hook()
{
	exit(1);
}

static int	wasd_hook(int key, t_vars *vars)
{
	void	*floor_img;
	void	*wall_img;
	int	height;
	int 	width;

	floor_img = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/so_long/Assets/Floor.xpm", &width, &height);
	wall_img = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/so_long/Assets/Wall.xpm", &width, &height);
	mlx_string_put(vars->mlx, vars->win, 5, 15, 0xE49B0F, ft_itoa(vars->counter));
	//nested player struct inside vars struct to pass the player info to the hook function without violating the mlx_key_hook function prototype.
	if (key == 119)
	{
		if ((vars->d_ptr[vars->player.i - 1][vars->player.j] == 'E' && collectible_check(vars->d_ptr) == 1) || vars->d_ptr[vars->player.i - 1][vars->player.j] == 'X')
			exit(1);	
		if (vars->d_ptr[vars->player.i - 1][vars->player.j] != '1' && vars->d_ptr[vars->player.i - 1][vars->player.j] != 'E')
		{
			//Replacing every collectible with a floor symbol to help with checking for collectibles for the collectible_check function.
			if (vars->d_ptr[vars->player.i - 1][vars->player.j] == 'C')
				vars->d_ptr[vars->player.i - 1][vars->player.j] = '0';
			vars->player.i -= 1;
			mlx_put_image_to_window(vars->mlx, vars->win, floor_img, vars->player.player_x, vars->player.player_y);
			vars->player.player_y -= 24;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, vars->player.player_x, vars->player.player_y);
			vars->counter++;
			mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 0, 0);	
			mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 24, 0);
			mlx_string_put(vars->mlx, vars->win, 5, 15, 0xE49B0F, ft_itoa(vars->counter));
		}
	}
	else if (key == 97)
	{
		if ((vars->d_ptr[vars->player.i][vars->player.j - 1] == 'E' && collectible_check(vars->d_ptr) == 1) || vars->d_ptr[vars->player.i][vars->player.j - 1] == 'X')
			exit(1);
		if (vars->d_ptr[vars->player.i][vars->player.j - 1] != '1' && vars->d_ptr[vars->player.i][vars->player.j - 1] != 'E')
		{
			if (vars->d_ptr[vars->player.i][vars->player.j - 1] == 'C')
				vars->d_ptr[vars->player.i][vars->player.j - 1] = '0';
			vars->player.j -= 1;
			mlx_put_image_to_window(vars->mlx, vars->win, floor_img, vars->player.player_x, vars->player.player_y);
			vars->player.player_x -= 24;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, vars->player.player_x, vars->player.player_y);
			vars->counter++;
			mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 0, 0);
			mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 24, 0);
			mlx_string_put(vars->mlx, vars->win, 5, 15, 0xE49B0F, ft_itoa(vars->counter));
		}
	}
	else if (key == 115)
	{
		if ((vars->d_ptr[vars->player.i + 1][vars->player.j] == 'E' && collectible_check(vars->d_ptr) == 1) || vars->d_ptr[vars->player.i + 1][vars->player.j] == 'X')
			exit(1);
		if (vars->d_ptr[vars->player.i + 1][vars->player.j] != '1' && vars->d_ptr[vars->player.i + 1][vars->player.j] != 'E')
		{
			if (vars->d_ptr[vars->player.i + 1][vars->player.j] == 'C')
				vars->d_ptr[vars->player.i + 1][vars->player.j] = '0';
			vars->player.i += 1;
			mlx_put_image_to_window(vars->mlx, vars->win, floor_img, vars->player.player_x, vars->player.player_y);
			vars->player.player_y += 24;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, vars->player.player_x, vars->player.player_y);
			vars->counter++;
			mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 0, 0);
			mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 24, 0);
			mlx_string_put(vars->mlx, vars->win, 5, 15, 0xE49B0F, ft_itoa(vars->counter));
		}
	
	}
	else if (key == 100)
	{	if ((vars->d_ptr[vars->player.i][vars->player.j + 1] == 'E' && collectible_check(vars->d_ptr) == 1) || vars->d_ptr[vars->player.i][vars->player.j + 1] == 'X')
			exit(1);	
		if (vars->d_ptr[vars->player.i][vars->player.j + 1] != '1' && vars->d_ptr[vars->player.i][vars->player.j + 1] != 'E')
		{
			if (vars->d_ptr[vars->player.i][vars->player.j + 1] == 'C')
				vars->d_ptr[vars->player.i][vars->player.j + 1] = '0';
			vars->player.j += 1;
			mlx_put_image_to_window(vars->mlx, vars->win, floor_img, vars->player.player_x, vars->player.player_y);
			vars->player.player_x += 24;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, vars->player.player_x, vars->player.player_y);
			vars->counter++;
			mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 0, 0);
			mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 24, 0);
			mlx_string_put(vars->mlx, vars->win, 5, 15, 0xE49B0F, ft_itoa(vars->counter));	
		}
	
	}
	else if (key == 65307)
		exit(1);
	return 0;
}
void	player_hooking(t_vars *vars)
{
	vars->counter = 0;
	mlx_hook(vars->win, 17, 0, button_hook, NULL);
	mlx_key_hook(vars->win, wasd_hook, vars);
	mlx_loop(vars->mlx);
}