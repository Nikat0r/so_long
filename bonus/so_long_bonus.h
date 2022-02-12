#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_player{
	int	i;
	int	j;
	int	player_y;
	int	player_x;
	void	*img;
}	t_player;

typedef struct s_vars{
	void		*mlx;
	void		*win;
	void		*img;
	char		**d_ptr;
	int			counter;
	t_player	player;	
}	t_vars;

typedef struct s_parsing{
	int	i;
	int	j;
	int	x;
	int	y;
	int	width;
	int	height;
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

#endif
