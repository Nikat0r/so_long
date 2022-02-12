#include "so_long_bonus.h"

/*static int	enemy_movement(t_vars *vars)
{
	int	height;
	int	width;
	int 	pos_up;
	int	pos_down;

	vars->enemy.img = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/enemy/1.xpm", &width, &height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, vars->enemy.x, vars->enemy.y);
	vars->backg = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/Assets/Floor.xpm", &width, &height);
	pos_up = vars->enemy.y - height;
	pos_down = vars->enemy.y + height;
	if ((vars->d_ptr[vars->enemy.i - 1][vars->enemy.j] == 'C' || vars->d_ptr[vars->enemy.i - 1][vars->enemy.j] == '0') && (vars->d_ptr[vars->enemy.i + 1][vars->enemy.j] == 'C' || vars->d_ptr[vars->enemy.i + 1][vars->enemy.j] == '0'))
	{
		while (vars->enemy.y <= pos_down)
		{
			vars->enemy.y += height;
			usleep(1000);
			//clearing the image before and after to smoothen the movement
			mlx_put_image_to_window(vars->mlx, vars->win, vars->backg, vars->enemy.x, vars->enemy.y - height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, vars->enemy.x, vars->enemy.y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->backg, vars->enemy.x, vars->enemy.y - height);
			if (vars->enemy.y == pos_down)
			{
				while (vars->enemy.y >= pos_up)
				{
					vars->enemy.y -= height;
					usleep(1000);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->backg, vars->enemy.x, vars->enemy.y + height);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, vars->enemy.x, vars->enemy.y);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->backg, vars->enemy.x, vars->enemy.y + height);
					if (vars->enemy.y == pos_up)
						break;
				}
			}
		}
	}
	//mlx_loop(vars->mlx);
	return 0;
}*/
static void	map_parsing_3(char **d_ptr, t_vars *vars, t_parsing *parsing)
{
	if (d_ptr[parsing->i][parsing->j] == 'C')
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/so_long/Assets/Sword.xpm", &parsing->width, &parsing->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, parsing->x, parsing->y);
	}
	else if (d_ptr[parsing->i][parsing->j] == 'X')
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/so_long/Assets/Enemy.xpm", &parsing->width, &parsing->height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, parsing->x, parsing->y);
	}
	else if (d_ptr[parsing->i][parsing->j] == 'P')
	{
		vars->player.img = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/so_long/Assets/Knight.xpm", &parsing->width, &parsing->height);
		vars->player.j = parsing->j;
		vars->player.i = parsing->i;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, parsing->x, parsing->y);
		vars->player.player_x = parsing->x;
		vars->player.player_y = parsing->y;
	}
}

static void	map_parsing_2(char **d_ptr, t_vars *vars, int count_x, t_parsing *parsing)
{
	while (parsing->j < count_x)
	{
		if (d_ptr[parsing->i][parsing->j] == '1')
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/so_long/Assets/Wall.xpm", &parsing->width, &parsing->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, parsing->x, parsing->y);
		}
		else if (d_ptr[parsing->i][parsing->j] == '0')
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/so_long/Assets/Floor.xpm", &parsing->width, &parsing->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, parsing->x, parsing->y);
		}
		else if (d_ptr[parsing->i][parsing->j] == 'E')
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/so_long/Assets/Door.xpm", &parsing->width, &parsing->height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, parsing->x, parsing->y);
		}
		else
			map_parsing_3(d_ptr, vars, parsing);
		parsing->j++;
		parsing->x += parsing->width;
	}
}

void	map_parsing(char **d_ptr, int count_y, int count_x)
{
	t_vars		vars;
	t_parsing	parsing;

	parsing.i = 0;
	parsing.y = 0;
	vars.mlx = mlx_init();
	vars.img = mlx_xpm_file_to_image(vars.mlx, "/home/nikator/Desktop/so_long/Assets/Floor.xpm", &parsing.width, &parsing.height);
	vars.win = mlx_new_window(vars.mlx, count_x * parsing.width, count_y * parsing.height, "so_long");
	while (parsing.i < count_y)
	{
		parsing.j = 0;
		parsing.x = 0;
		map_parsing_2(d_ptr, &vars, count_x, &parsing);
		parsing.y += parsing.height;
		parsing.i++;
	}
	/*passing by reference to change the actual values of the player info to account for the wasd_hook function!
	Including d_ptr in vars to be able to pass it to wasd_hook.*/
	vars.d_ptr = d_ptr;
	player_hooking(&vars);
}
