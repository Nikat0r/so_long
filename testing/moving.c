/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:54:06 by ababa             #+#    #+#             */
/*   Updated: 2021/12/23 18:57:06 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct	s_vars{
	void	*mlx;
	void	*img_wall;
	//void	*img_floor;
	void	*win;
}			t_vars;


int	key_hook(int keynote)
{
	if (keynote == 53)
		exit(0);
	return 0;
}

int main(void)
{
	t_vars	vars;

	char	*path_wall = "Users/ababa/Desktop/so_long assets/Wall.xpm";
	//char	*path_floor = "Users/ababa/Desktop/so_long assets/floor.xpm";
	int img_height;
	int img_width;
	int x = 0, y = 0;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 720, 480, "hello");
	vars.img_wall = mlx_xpm_file_to_image(vars.mlx, path_wall, &img_width, &img_height);
	
	while (x < 720 && y < 480)
	{
		if (x == 0)
			mlx_put_image_to_window(vars.mlx, vars.win, vars.img_wall, x, y);
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img_wall, x += img_width, y);
		if (x == 720)
		{	
			x = 0;
			y += img_height;
		}
	}
	img_height = 0;
	img_width = 0;
//	vars.img_floor = mlx_xpm_file_to_image(vars.mlx, path_floor, &img_width, &img_height);
//	mlx_put_image_to_window(vars.mlx, vars.win, vars.img_floor, 50, 50);
	mlx_key_hook(vars.win, key_hook, &vars);	
	mlx_loop(vars.mlx);
}
