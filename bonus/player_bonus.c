#include "so_long_bonus.h"

static int	button_hook(void)
{
	exit(1);
}

static int	wasd_hook(int key, t_vars *vars)
{
	void	*floor_img;
	void	*wall_img;
	int	height;
	int	width;

	floor_img = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/so_long/Assets/Floor.xpm", &width, &height);
	wall_img = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/so_long/Assets/Wall.xpm", &width, &height);
	mlx_string_put(vars->mlx, vars->win, 5, 15, 0xE49B0F, ft_itoa(vars->counter));
	//nested player struct inside vars struct to pass the player info to the hook function without violating the mlx_key_hook function prototype.
	if (key == 119)
		w_hook(vars, floor_img, wall_img);
	else if (key == 97)
		a_hook(vars, floor_img, wall_img);
	else if (key == 115)
		s_hook(vars, floor_img, wall_img);
	else if (key == 100)
		d_hook(vars, floor_img, wall_img);
	else if (key == 65307)
		exit(1);
	return (0);
}

void	player_hooking(t_vars *vars)
{
	vars->counter = 0;
	mlx_hook(vars->win, 17, 0, button_hook, NULL);
	mlx_key_hook(vars->win, wasd_hook, vars);
	mlx_loop(vars->mlx);
}