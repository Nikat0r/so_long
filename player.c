/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:29:58 by ababa             #+#    #+#             */
/*   Updated: 2022/02/17 17:55:00 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	button_hook(void)
{
	exit(0);
}

static int	wasd_hook(int key, t_vars *vars)
{
	void	*floor_img;
	void	*wall_img;
	int		height;
	int		width;

	floor_img = mlx_xpm_file_to_image(vars->mlx, "/Users/ababa/Cursus/so_long/Assets/Floor.xpm", &width, &height);
	wall_img = mlx_xpm_file_to_image(vars->mlx, "/Users/ababa/Cursus/so_long/Assets/Wall.xpm", &width, &height);
	vars->ptr = ft_itoa(vars->counter);
	mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, wall_img, 24, 0);
	mlx_string_put(vars->mlx, vars->win, 5, 5, 0xE49B0F, vars->ptr);
	free(vars->ptr);
	//nested player struct inside vars struct to pass the player info to the hook function without violating the mlx_key_hook function prototype.
	if (key == 13)
		w_hook(vars, floor_img, wall_img);
	else if (key == 0)
		a_hook(vars, floor_img, wall_img);
	else if (key == 1)
		s_hook(vars, floor_img, wall_img);
	else if (key == 2)
		d_hook(vars, floor_img, wall_img);
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
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img, 48, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->anim.img1, 48, 0);
	}	
	else if (counter <= 20)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img, 48, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->anim.img2, 48, 0);
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