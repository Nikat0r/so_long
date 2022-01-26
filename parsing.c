#include "so_long.h"

static int	enemy_movement(t_vars *vars)
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
}
void	map_parsing(char **d_ptr, int count_y, int count_x)
{
	t_vars		vars;
	t_cords		cords;

	int	i;
	int	j;
	int	img_height;
	int	img_width;

	i = 0;
	cords.y = 0;
	//Including d_ptr in vars to be able to pass it to wasd_hook.
	vars.d_ptr = d_ptr;
	vars.mlx = mlx_init();
	vars.backg = mlx_xpm_file_to_image(vars.mlx, "/home/nikator/Desktop/Assets/Floor.xpm", &img_width, &img_height);
	vars.win = mlx_new_window(vars.mlx, count_x * img_width, count_y * img_height, "so_long");
	while (i < count_y)
	{
		j = 0;
		cords.x = 0;
		while (j < count_x)
		{
			if (d_ptr[i][j] == '1')
			{
				vars.img = mlx_xpm_file_to_image(vars.mlx, "/home/nikator/Desktop/Assets/Wall.xpm", &img_width, &img_height);
				mlx_put_image_to_window(vars.mlx, vars.win, vars.img, cords.x, cords.y);
			}
			else if (d_ptr[i][j] == '0')
			{
				vars.img = mlx_xpm_file_to_image(vars.mlx, "/home/nikator/Desktop/Assets/Floor.xpm", &img_width, &img_height);
				mlx_put_image_to_window(vars.mlx, vars.win, vars.img, cords.x, cords.y);
			}
			else if (d_ptr[i][j] == 'E')
			{
				vars.img = mlx_xpm_file_to_image(vars.mlx, "/home/nikator/Desktop/Assets/Door.xpm", &img_width, &img_height);
				mlx_put_image_to_window(vars.mlx, vars.win, vars.img, cords.x, cords.y);
			}
			else if (d_ptr[i][j] == 'C')
			{
				vars.img = mlx_xpm_file_to_image(vars.mlx, "/home/nikator/Desktop/Assets/Sword.xpm", &img_width, &img_height);
				mlx_put_image_to_window(vars.mlx, vars.win, vars.backg, cords.x, cords.y);
				mlx_put_image_to_window(vars.mlx, vars.win, vars.img, cords.x, cords.y);
			}
			else if (d_ptr[i][j] == 'X')
			{
				vars.enemy.i = i;
				vars.enemy.j = j;
				vars.enemy.x = cords.x;
				vars.enemy.y = cords.y;
				mlx_expose_hook(vars.win, enemy_movement, &vars);
				//enemy_movement(vars, cords, i, j);
			}
			else if (d_ptr[i][j] == 'P')
			{
				vars.player.img = mlx_xpm_file_to_image(vars.mlx, "/home/nikator/Desktop/Assets/Knight.xpm", &img_width, &img_height);
				vars.player.j = j;
				vars.player.i = i;
				mlx_put_image_to_window(vars.mlx, vars.win, vars.backg, cords.x, cords.y);
				mlx_put_image_to_window(vars.mlx, vars.win, vars.player.img, cords.x, cords.y);
				vars.player.player_x = cords.x;
				vars.player.player_y = cords.y;
			}
			j++;
			cords.x += img_width;
		}
		cords.y += img_height;
		i++;
	}
	//passing by reference to change the actual values of the player info to account for the wasd_hook function!
	//Including d_ptr in vars to be able to pass it to wasd_hook.
	player_hooking(&vars);
}
