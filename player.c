/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:29:58 by ababa             #+#    #+#             */
/*   Updated: 2022/02/17 18:19:48 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	button_hook(void)
{
	exit(0);
}
	/*nested player struct inside vars struct to pass the player info to the 
	 hook function without violating the mlx_key_hook function prototype.*/

static int	wasd_hook(int key, t_vars *vars)
{
	void	*f;
	void	*w;
	int		height;
	int		width;

	f = mlx_xpm_file_to_image(vars->mlx, "/Users/ababa/f.xpm", &width, &height);
	w = mlx_xpm_file_to_image(vars->mlx, "/Users/ababa/w.xpm", &width, &height);
	vars->ptr = ft_itoa(vars->counter);
	mlx_put_image_to_window(vars->mlx, vars->win, w, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, w, 24, 0);
	mlx_string_put(vars->mlx, vars->win, 5, 5, 0xE49B0F, vars->ptr);
	free(vars->ptr);
	if (key == 13)
		w_hook(vars, f, w);
	else if (key == 0)
		a_hook(vars, f, w);
	else if (key == 1)
		s_hook(vars, f, w);
	else if (key == 2)
		d_hook(vars, f, w);
	else if (key == 53)
		exit(0);
	return (0);
}

static int	animation(t_vars *vars)
{
	static int	counter;

	sprite_animation(vars);
	if (counter <= 10)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, 48, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->a.f1, 48, 0);
	}	
	else if (counter <= 20)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, 48, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->a.f2, 48, 0);
	}
	if (counter == 20)
		counter = 0;
	counter++;
	return (0);
}

void	player_hooking(t_vars *vars)
{
	vars->counter = 0;
	mlx_hook(vars->win, 17, 0, button_hook, NULL);
	mlx_key_hook(vars->win, wasd_hook, vars);
	mlx_loop_hook(vars->mlx, animation, vars);
	mlx_loop(vars->mlx);
}
