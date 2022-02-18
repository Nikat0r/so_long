/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:24:28 by ababa             #+#    #+#             */
/*   Updated: 2022/02/18 11:24:31 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	cc(char **d_ptr)
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

void	w_hook(t_vars *v, void *f, void *wall_img)
{
	if ((v->d_ptr[v->p.i - 1][v->p.j] == 'E' && cc(v->d_ptr) == 1)
		|| v->d_ptr[v->p.i - 1][v->p.j] == 'X')
		exit(0);
	if (v->d_ptr[v->p.i - 1][v->p.j] != '1'
		&& v->d_ptr[v->p.i - 1][v->p.j] != 'E')
	{	
		v->p.i -= 1;
		mlx_put_image_to_window(v->mlx, v->win, f, v->p.x, v->p.y);
		v->p.y -= 24;
		v->d_ptr[v->p.i + 1][v->p.j] = '0';
		v->d_ptr[v->p.i][v->p.j] = 'P';
		mlx_put_image_to_window(v->mlx, v->win, f, v->p.x, v->p.y);
		mlx_put_image_to_window(v->mlx, v->win, v->p.img, v->p.x, v->p.y);
		v->counter++;
		v->ptr = ft_itoa(v->counter);
		mlx_put_image_to_window(v->mlx, v->win, wall_img, 0, 0);
		mlx_put_image_to_window(v->mlx, v->win, wall_img, 24, 0);
		mlx_string_put(v->mlx, v->win, 5, 5, 0xE49B0F, v->ptr);
		free(v->ptr);
		enemy_movement(v);
	}
}

void	a_hook(t_vars *v, void *f, void *wall_img)
{
	if ((v->d_ptr[v->p.i][v->p.j - 1] == 'E'
		&& cc(v->d_ptr) == 1) || v->d_ptr[v->p.i][v->p.j - 1] == 'X')
		exit(0);
	if (v->d_ptr[v->p.i][v->p.j - 1] != '1'
		&& v->d_ptr[v->p.i][v->p.j - 1] != 'E')
	{	
		v->p.j -= 1;
		mlx_put_image_to_window(v->mlx, v->win, f, v->p.x, v->p.y);
		v->p.x -= 24;
		v->d_ptr[v->p.i][v->p.j + 1] = '0';
		v->d_ptr[v->p.i][v->p.j] = 'P';
		mlx_put_image_to_window(v->mlx, v->win, f, v->p.x, v->p.y);
		mlx_put_image_to_window(v->mlx, v->win, v->p.img, v->p.x, v->p.y);
		v->counter++;
		v->ptr = ft_itoa(v->counter);
		mlx_put_image_to_window(v->mlx, v->win, wall_img, 0, 0);
		mlx_put_image_to_window(v->mlx, v->win, wall_img, 24, 0);
		mlx_string_put(v->mlx, v->win, 5, 5, 0xE49B0F, v->ptr);
		free(v->ptr);
		enemy_movement(v);
	}
}

void	s_hook(t_vars *v, void *f, void *wall_img)
{
	if ((v->d_ptr[v->p.i + 1][v->p.j] == 'E'
		&& cc(v->d_ptr) == 1) || v->d_ptr[v->p.i + 1][v->p.j] == 'X')
		exit(0);
	if (v->d_ptr[v->p.i + 1][v->p.j] != '1'
		&& v->d_ptr[v->p.i + 1][v->p.j] != 'E')
	{		
		v->p.i += 1;
		mlx_put_image_to_window(v->mlx, v->win, f, v->p.x, v->p.y);
		v->p.y += 24;
		v->d_ptr[v->p.i - 1][v->p.j] = '0';
		v->d_ptr[v->p.i][v->p.j] = 'P';
		mlx_put_image_to_window(v->mlx, v->win, f, v->p.x, v->p.y);
		mlx_put_image_to_window(v->mlx, v->win, v->p.img, v->p.x, v->p.y);
		v->counter++;
		v->ptr = ft_itoa(v->counter);
		mlx_put_image_to_window(v->mlx, v->win, wall_img, 0, 0);
		mlx_put_image_to_window(v->mlx, v->win, wall_img, 24, 0);
		mlx_string_put(v->mlx, v->win, 5, 5, 0xE49B0F, v->ptr);
		free(v->ptr);
		enemy_movement(v);
	}	
}

void	d_hook(t_vars *v, void *f, void *wall_img)
{	
	if ((v->d_ptr[v->p.i][v->p.j + 1] == 'E'
		&& cc(v->d_ptr) == 1) || v->d_ptr[v->p.i][v->p.j + 1] == 'X')
		exit(0);
	if (v->d_ptr[v->p.i][v->p.j + 1] != '1'
		&& v->d_ptr[v->p.i][v->p.j + 1] != 'E')
	{
		v->p.j += 1;
		mlx_put_image_to_window(v->mlx, v->win, f, v->p.x, v->p.y);
		v->p.x += 24;
		v->d_ptr[v->p.i][v->p.j - 1] = '0';
		v->d_ptr[v->p.i][v->p.j] = 'P';
		mlx_put_image_to_window(v->mlx, v->win, f, v->p.x, v->p.y);
		mlx_put_image_to_window(v->mlx, v->win, v->p.img, v->p.x, v->p.y);
		v->counter++;
		v->ptr = ft_itoa(v->counter);
		mlx_put_image_to_window(v->mlx, v->win, wall_img, 0, 0);
		mlx_put_image_to_window(v->mlx, v->win, wall_img, 24, 0);
		mlx_string_put(v->mlx, v->win, 5, 5, 0xE49B0F, v->ptr);
		free(v->ptr);
		enemy_movement(v);
	}
}
