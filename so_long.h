/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:14:29 by ababa             #+#    #+#             */
/*   Updated: 2021/12/24 11:25:22 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"
typedef struct{
	int	i;
	int	j;
	int	player_y;
	int	player_x;
	void	*img;
}	t_player;

typedef struct{
	void	*mlx;
	void	*win;
	void	*img;
	void	*backg;
	char	**d_ptr;
	int	counter;
	t_player player;	
}	t_vars;

typedef struct{
	int	x;
	int	y;
}	t_cords;

void	ft_putchar(char	c);
void	ft_putstr(char	*str);
char	*ft_strrchr(const char *str, int c);
int	ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
void	map_parsing(char **d_ptr, int count_y, int count_x);
void	player_hooking(t_vars *vars);

#endif


