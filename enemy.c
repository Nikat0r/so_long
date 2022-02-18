/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:54:10 by ababa             #+#    #+#             */
/*   Updated: 2022/02/18 11:12:18 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	top_blocked(t_vars *v, int h)
{
	v->e.s_i = 1;
	if (v->e.y == v->e.pos_down)
	{
		if (v->d_ptr[v->e.i - 1][v->e.j] == 'P')
			exit(1);
		v->e.y -= h;
		v->d_ptr[v->e.i][v->e.j] = '0';
		v->e.i--;
		v->d_ptr[v->e.i][v->e.j] = 'X';
		mlx_put_image_to_window(v->mlx, v->win, v->backg, v->e.x, v->e.y + h);
		mlx_put_image_to_window(v->mlx, v->win, v->e.img, v->e.x, v->e.y);
	}
	else if (v->e.y == v->e.pos_mid)
	{
		if (v->d_ptr[v->e.i + 1][v->e.j] == 'P')
			exit(1);
		v->e.y += h;
		v->d_ptr[v->e.i][v->e.j] = '0';
		v->e.i++;
		v->d_ptr[v->e.i][v->e.j] = 'X';
		mlx_put_image_to_window(v->mlx, v->win, v->backg, v->e.x, v->e.y - h);
		mlx_put_image_to_window(v->mlx, v->win, v->e.img, v->e.x, v->e.y);
	}
}

static void	bot_blocked(t_vars *v, int h)
{
	v->e.s_i = 2;
	if (v->e.y == v->e.pos_up)
	{	
		if (v->d_ptr[v->e.i + 1][v->e.j] == 'P')
			exit(1);
		v->e.y += h;
		v->d_ptr[v->e.i][v->e.j] = '0';
		v->e.i++;
		v->d_ptr[v->e.i][v->e.j] = 'X';
		mlx_put_image_to_window(v->mlx, v->win, v->backg, v->e.x, v->e.y - h);
		mlx_put_image_to_window(v->mlx, v->win, v->e.img, v->e.x, v->e.y);
	}
	else if (v->e.y == v->e.pos_mid)
	{		
		if (v->d_ptr[v->e.i - 1][v->e.j] == 'P')
			exit(1);
		v->e.y -= h;
		v->d_ptr[v->e.i][v->e.j] = '0';
		v->e.i--;
		v->d_ptr[v->e.i][v->e.j] = 'X';
		mlx_put_image_to_window(v->mlx, v->win, v->backg, v->e.x, v->e.y + h);
		mlx_put_image_to_window(v->mlx, v->win, v->e.img, v->e.x, v->e.y);
	}
}

static void	enemy_pos_mid(t_vars *v, int h)
{
	if (v->e.counter == 1)
	{	
		if (v->d_ptr[v->e.i - 1][v->e.j] == 'P')
			exit(1);
		v->e.y -= h;
		v->d_ptr[v->e.i][v->e.j] = '0';
		v->e.i--;
		v->d_ptr[v->e.i][v->e.j] = 'X';
		mlx_put_image_to_window(v->mlx, v->win, v->backg, v->e.x, v->e.y + h);
		mlx_put_image_to_window(v->mlx, v->win, v->e.img, v->e.x, v->e.y);
		v->e.counter = 0;
	}
	else if (v->e.counter == 0)
	{		
		if (v->d_ptr[v->e.i + 1][v->e.j] == 'P')
			exit(1);
		v->e.y += h;
		v->d_ptr[v->e.i][v->e.j] = '0';
		v->e.i++;
		v->d_ptr[v->e.i][v->e.j] = 'X';
		mlx_put_image_to_window(v->mlx, v->win, v->backg, v->e.x, v->e.y - h);
		mlx_put_image_to_window(v->mlx, v->win, v->e.img, v->e.x, v->e.y);
		v->e.counter = 1;
	}
}

static void	enemy_pos_up_down(t_vars *v, int h)
{
	if (v->e.y == v->e.pos_down)
	{			
		if (v->d_ptr[v->e.i - 1][v->e.j] == 'P')
			exit(1);
		v->e.y -= h;
		v->d_ptr[v->e.i][v->e.j] = '0';
		v->e.i--;
		v->d_ptr[v->e.i][v->e.j] = 'X';
		mlx_put_image_to_window(v->mlx, v->win, v->backg, v->e.x, v->e.y + h);
		mlx_put_image_to_window(v->mlx, v->win, v->e.img, v->e.x, v->e.y);
	}
	else if (v->e.y == v->e.pos_up)
	{		
		if (v->d_ptr[v->e.i + 1][v->e.j] == 'P')
			exit(1);
		v->e.y += h;
		v->d_ptr[v->e.i][v->e.j] = '0';
		v->e.i++;
		v->d_ptr[v->e.i][v->e.j] = 'X';
		mlx_put_image_to_window(v->mlx, v->win, v->backg, v->e.x, v->e.y - h);
		mlx_put_image_to_window(v->mlx, v->win, v->e.img, v->e.x, v->e.y);
	}
}
	/*switch_int is to avoid the third condition from being true
	after moving the X from its original position
	adding switch_int conditions to ensure 
	only one condition is gonna get satisfied*/

void	enemy_movement(t_vars *v)
{
	int	h;
	int	w;

	v->e.img = mlx_xpm_file_to_image(v->mlx, "./i/e.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->e.img, v->e.x, v->e.y);
	v->backg = mlx_xpm_file_to_image(v->mlx, "./i/f.xpm", &w, &h);
	if ((v->d_ptr[v->e.i - 1][v->e.j] != '0'
		&& v->d_ptr[v->e.i + 1][v->e.j] == '0'
		&& v->e.s_i != 0) || v->e.s_i == 1)
		top_blocked(v, h);
	else if ((v->d_ptr[v->e.i - 1][v->e.j] == '0'
		&& v->d_ptr[v->e.i + 1][v->e.j] != '0'
		&& v->e.s_i != 0) || v->e.s_i == 2)
		bot_blocked(v, h);
	else if ((v->d_ptr[v->e.i - 1][v->e.j] == '0'
		&& v->d_ptr[v->e.i + 1][v->e.j] == '0'
		&& v->e.s_i != 1 && v->e.s_i != 2) || v->e.s_i == 0)
	{
		v->e.s_i = 0;
		if (v->e.y == v->e.pos_mid)
			enemy_pos_mid(v, h);
		else if (v->e.y == v->e.pos_down || v->e.y == v->e.pos_up)
			enemy_pos_up_down(v, h);
	}
}
