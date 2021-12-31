#include "so_long.h"

void	map_parsing(char **d_ptr, int count_y, count_x)
{
	t_vars	vars;
	int	i;
	int	j;
	int	img_height;
	int	img_width;

	//make a struct for coordinates
	i = 0;
	j = 0;
	vars.mlx = mlx_init();
	vars.img = mlx_xpm_file_to_image(vars.mlx, "", &img_width, im&g_height);
	vars.win = mlx_new_window(vars.mlx, img_width * count_x, img_height * count_y, "so_long");
	while (d_ptr[i])
	{
		while (d_ptr[i][j])
		{
			// add a condition to x = 0 to put the first image on the windown at x = 0
			if (d_ptr[i][j] == '1')
				vars.img = mlx_xpm_file_to_image(vars.mlx, "", &img_width, &img_height);
			else if (d_ptr[i][j] == '0')
				vars.img = mlx_xpm_file_to_image(vars.mlx, "", &img_width, &img_height);
			else if (d_ptr[i][j] == 'E')
				vars.img = mlx_xpm_file_to_image(vars.mlx, "", &img_width, &img_height);
			else if (d_ptr[i][j] == 'C')
				vars.img = mlx_xpm_file_to_image(vars.mlx, "", &img_width, &img_height);
			else if (d_ptr[i][j] == 'P')
				vars.img = mlx_xpm_file_to_image(vars.mlx, "", &img_width, &img_height);
			j++;
		}
		i++;
	}
}
