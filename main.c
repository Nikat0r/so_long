#include "so_long.h"

int main()
{
	int	count_x = 40;
	int	count_y = 15;
	t_vars	vars;
	int	i;
	int	j;
	int	img_height;
	int	img_width;

	//make a struct for coordinates
	i = 0;
	j = 0;
	vars.mlx = mlx_init();
	vars.img = mlx_xpm_file_to_image(vars.mlx, "/home/nikator/Desktop/Assets/Floor.xpm", &img_width, &img_height);
	vars.win = mlx_new_window(vars.mlx, img_width*count_x, img_height*count_y, "so_long");
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_loop(vars.mlx);

}