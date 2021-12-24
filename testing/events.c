/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:23:05 by ababa             #+#    #+#             */
/*   Updated: 2021/12/21 18:45:08 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		//mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	return 0;
}
int mouse_hook(int x, int y, t_vars *vars)
{
	if ((0 < x && x < 1920) && (0 < y && y < 1080))
		printf("Hello");
	else
		printf("Bye");
	//printf("x = %d | y = %d\n", x , y);
	return 0;
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 6, 1L<<6, mouse_hook, &vars);
	mlx_hook(vars.win, 2, 1L<<0 ,ft_close, &vars);
	mlx_loop_hook(vars.mlx,mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
