/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:59:17 by ababa             #+#    #+#             */
/*   Updated: 2022/02/18 11:12:54 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*storage_array(void)
{
	char	*storage;

	storage = malloc(7 * sizeof(char));
	if (storage == NULL)
		return (NULL);
	storage[0] = '\0';
	storage[1] = '\0';
	storage[2] = '\0';
	storage[3] = '\0';
	storage[4] = 'A';
	storage[5] = 'A';
	storage[6] = '\0';
	return (storage);
}

static void	if_conditions(char **d_ptr, int i, int j, char *storage)
{
	if (d_ptr[i][j] == 'E')
		*storage = 'E';
	else if (d_ptr[i][j] == 'C')
		*(storage + 3) = 'C';
	else if (d_ptr[i][j] == 'P')
	{
		*(storage + 1) = 'P';
		*(storage + 4) += 1;
	}		
	else if (d_ptr[i][j] == 'X')
	{
		*(storage + 2) = 'X';
		*(storage + 5) += 1;
	}
	else if (d_ptr[i][j] != '1' && d_ptr[i][j] != '0')
	{
		ft_putstr("Error :\nInvalid map, your map contains wrong elements!\n");
		exit(1);
	}
}

	/*static for the NULL initialization for the if statement to avoid 
	  reinitialzing storage each time the function gets called*/

char	*map_element_check_2(char **d_ptr, int count_y, int count_x, int i)
{
	static char	*storage;
	int			j;

	if (!storage)
		storage = storage_array();
	j = 1;
	while (i < count_y && j < count_x)
	{
		if_conditions(d_ptr, i, j, storage);
		j++;
	}
	return (storage);
}

void	declarations(t_vars *vars)
{
	vars->e.pos_up = vars->e.y - 24;
	vars->e.pos_down = vars->e.y + 24;
	vars->e.pos_mid = vars->e.y;
	vars->e.counter = 0;
	vars->e.s_i = -1;
}

	/*a is the animation struct and f1/f2 are the two frames*/

void	sprite_animation(t_vars *vars)
{
	int	w;
	int	h;

	vars->wall = mlx_xpm_file_to_image(vars->mlx, "/Users/ababa/w.xpm", &w, &h);
	vars->a.f1 = mlx_xpm_file_to_image(vars->mlx, "/Users/ababa/1.xpm", &w, &h);
	vars->a.f2 = mlx_xpm_file_to_image(vars->mlx, "/Users/ababa/a.xpm", &w, &h);
}
