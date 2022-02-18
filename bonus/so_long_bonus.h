/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:22:02 by ababa             #+#    #+#             */
/*   Updated: 2022/02/18 11:22:07 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_player{
	int		i;
	int		j;
	int		y;
	int		x;
	void	*img;
}	t_player;

typedef struct s_a{
	void	*f1;	
	void	*f2;
}	t_a;

typedef struct s_enemy{
	int		i;
	int		j;
	int		x;
	int		y;
	int		pos_down;
	int		pos_up;
	int		pos_mid;
	int		counter;
	int		s_i;
	void	*img;
}	t_enemy;

typedef struct s_vars{
	void		*mlx;
	void		*win;
	void		*i;
	void		*backg;
	char		**d_ptr;
	int			counter;
	char		*ptr;
	void		*wall;
	void		*f;
	t_a			a;
	t_player	p;
	t_enemy		e;
}	t_vars;

typedef struct s_parsing{
	int	i;
	int	j;
	int	x;
	int	y;
	int	w;
	int	h;
}	t_parsing;
void	ft_putchar(char c);
size_t	ft_strlen(const char *str);
void	ft_putstr(char	*str);
char	*ft_strrchr(const char *str, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
void	map_parsing(char **d_ptr, int count_y, int count_x);
void	player_hooking(t_vars *vars);

char	*map_element_check_2(char **d_ptr, int count_y, int count_x, int i);
void	w_hook(t_vars *vars, void *floor_img, void *wall_img);
void	a_hook(t_vars *vars, void *floor_img, void *wall_img);
void	s_hook(t_vars *vars, void *floor_img, void *wall_img);
void	d_hook(t_vars *vars, void *floor_img, void *wall_img);
void	enemy_movement(t_vars *vars);
void	declarations(t_vars *vars);
void	sprite_animation(t_vars *vars);

#endif
