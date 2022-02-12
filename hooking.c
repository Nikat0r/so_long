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

void	a_hook(t_vars *vars, void *floor_img, void *wall_img)
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
void	s_hook(t_vars *vars, void *floor_img, void *wall_img)
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
void	d_hook(t_vars *vars, void *floor_img, void *wall_img)
{
	if ((vars->d_ptr[vars->player.i][vars->player.j + 1] == 'E' && collectible_check(vars->d_ptr) == 1) || vars->d_ptr[vars->player.i][vars->player.j + 1] == 'X')
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