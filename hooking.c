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

void	w_hook(t_vars *vars, void *floor_img, void *wall_img)
{
	if ((vars->d_ptr[vars->player.i - 1][vars->player.j] == 'E' && collectible_check(vars->d_ptr) == 1) || vars->d_ptr[vars->player.i - 1][vars->player.j] == 'X')
		exit(1);
	if (vars->d_ptr[vars->player.i - 1][vars->player.j] != '1' && vars->d_ptr[vars->player.i - 1][vars->player.j] != 'E')
	{	
		vars->player.i -= 1;
		mlx_put_image_to_window(vars->mlx, vars->win, floor_img, vars->player.player_x, vars->player.player_y);
		vars->player.player_y -= 24;
		vars->d_ptr[vars->player.i + 1][vars->player.j] = '0';
		vars->d_ptr[vars->player.i][vars->player.j] = 'P';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, vars->player.player_x, vars->player.player_y);
		vars->counter++;
		mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 0, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 24, 0);
		mlx_string_put(vars->mlx, vars->win, 5, 15, 0xE49B0F, ft_itoa(vars->counter));
		enemy_movement(vars);
	}
}

void	a_hook(t_vars *vars, void *floor_img, void *wall_img)
{
	if ((vars->d_ptr[vars->player.i][vars->player.j - 1] == 'E' && collectible_check(vars->d_ptr) == 1) || vars->d_ptr[vars->player.i][vars->player.j - 1] == 'X')
		exit(1);
	if (vars->d_ptr[vars->player.i][vars->player.j - 1] != '1' && vars->d_ptr[vars->player.i][vars->player.j - 1] != 'E')
	{
		vars->player.j -= 1;
		mlx_put_image_to_window(vars->mlx, vars->win, floor_img, vars->player.player_x, vars->player.player_y);
		vars->player.player_x -= 24;
		vars->d_ptr[vars->player.i][vars->player.j + 1] = '0';
		vars->d_ptr[vars->player.i][vars->player.j] = 'P';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, vars->player.player_x, vars->player.player_y);
		vars->counter++;
		mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 0, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 24, 0);
		mlx_string_put(vars->mlx, vars->win, 5, 15, 0xE49B0F, ft_itoa(vars->counter));
		enemy_movement(vars);
	}
}
void	s_hook(t_vars *vars, void *floor_img, void *wall_img)
{
	if ((vars->d_ptr[vars->player.i + 1][vars->player.j] == 'E' && collectible_check(vars->d_ptr) == 1) || vars->d_ptr[vars->player.i + 1][vars->player.j] == 'X')
		exit(1);
	if (vars->d_ptr[vars->player.i + 1][vars->player.j] != '1' && vars->d_ptr[vars->player.i + 1][vars->player.j] != 'E')
	{		
		vars->player.i += 1;
		mlx_put_image_to_window(vars->mlx, vars->win, floor_img, vars->player.player_x, vars->player.player_y);
		vars->player.player_y += 24;
		vars->d_ptr[vars->player.i - 1][vars->player.j] = '0';
		vars->d_ptr[vars->player.i][vars->player.j] = 'P';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, vars->player.player_x, vars->player.player_y);
		vars->counter++;
		mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 0, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 24, 0);
		mlx_string_put(vars->mlx, vars->win, 5, 15, 0xE49B0F, ft_itoa(vars->counter));
		enemy_movement(vars);
	}	
}
void	d_hook(t_vars *vars, void *floor_img, void *wall_img)
{
	if ((vars->d_ptr[vars->player.i][vars->player.j + 1] == 'E' && collectible_check(vars->d_ptr) == 1) || vars->d_ptr[vars->player.i][vars->player.j + 1] == 'X')
		exit(1);	
	if (vars->d_ptr[vars->player.i][vars->player.j + 1] != '1' && vars->d_ptr[vars->player.i][vars->player.j + 1] != 'E')
	{
		vars->player.j += 1;
		mlx_put_image_to_window(vars->mlx, vars->win, floor_img, vars->player.player_x, vars->player.player_y);
		vars->player.player_x += 24;
		vars->d_ptr[vars->player.i][vars->player.j - 1] = '0';
		vars->d_ptr[vars->player.i][vars->player.j] = 'P';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, vars->player.player_x, vars->player.player_y);
		vars->counter++;
		mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 0, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 24, 0);
		mlx_string_put(vars->mlx, vars->win, 5, 15, 0xE49B0F, ft_itoa(vars->counter));
		enemy_movement(vars);
	}
}