/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:24:12 by ababa             #+#    #+#             */
/*   Updated: 2022/02/18 11:24:14 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	map_parsing_3(char **d_ptr, t_vars *v, t_parsing *p)
{
	if (d_ptr[p->i][p->j] == 'C')
	{
		v->i = mlx_xpm_file_to_image(v->mlx, "./i/s.xpm", &p->w, &p->h);
		mlx_put_image_to_window(v->mlx, v->win, v->i, p->x, p->y);
	}
	else if (d_ptr[p->i][p->j] == 'X')
	{	
		v->e.i = p->i;
		v->e.j = p->j;
		v->e.x = p->x;
		v->e.y = p->y;
		declarations(v);
		v->e.img = mlx_xpm_file_to_image(v->mlx, "./i/e.xpm", &p->w, &p->h);
		mlx_put_image_to_window(v->mlx, v->win, v->e.img, p->x, p->y);
	}
	else if (d_ptr[p->i][p->j] == 'P')
	{
		v->p.img = mlx_xpm_file_to_image(v->mlx, "./i/k.xpm", &p->w, &p->h);
		v->p.j = p->j;
		v->p.i = p->i;
		mlx_put_image_to_window(v->mlx, v->win, v->p.img, p->x, p->y);
		v->p.x = p->x;
		v->p.y = p->y;
	}
}

static void	map_parsing_2(char **d_ptr, t_vars *v, int count_x, t_parsing *p)
{
	while (p->j < count_x)
	{
		if (d_ptr[p->i][p->j] == '1')
		{
			v->i = mlx_xpm_file_to_image(v->mlx, "./i/w.xpm", &p->w, &p->h);
			mlx_put_image_to_window(v->mlx, v->win, v->i, p->x, p->y);
		}
		else if (d_ptr[p->i][p->j] == '0')
		{
			v->i = mlx_xpm_file_to_image(v->mlx, "./i/f.xpm", &p->w, &p->h);
			mlx_put_image_to_window(v->mlx, v->win, v->i, p->x, p->y);
		}
		else if (d_ptr[p->i][p->j] == 'E')
		{
			v->i = mlx_xpm_file_to_image(v->mlx, "./i/d.xpm", &p->w, &p->h);
			mlx_put_image_to_window(v->mlx, v->win, v->i, p->x, p->y);
		}
		else
			map_parsing_3(d_ptr, v, p);
		p->j++;
		p->x += p->w;
	}
}

	/*passing by reference to change the actual values of the player info to 
	account for the wasd_hook function!
	Including d_ptr in vars to be able to pass it to wasd_hook.*/
void	map_parsing(char **d_ptr, int count_y, int count_x)
{
	t_vars		v;
	t_parsing	p;

	p.i = 0;
	p.y = 0;
	v.mlx = mlx_init();
	v.f = mlx_xpm_file_to_image(v.mlx, "./i/f.xpm", &p.w, &p.h);
	v.win = mlx_new_window(v.mlx, count_x * p.w, count_y * p.h, "solong");
	while (p.i < count_y)
	{
		p.j = 0;
		p.x = 0;
		map_parsing_2(d_ptr, &v, count_x, &p);
		p.y += p.h;
		p.i++;
	}
	v.d_ptr = d_ptr;
	player_hooking(&v);
}
