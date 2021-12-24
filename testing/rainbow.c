#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	x = 0;
	int y = 0;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 480, "Hello world!");
	img.img = mlx_new_image(mlx, 720, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (x < 720)
	{
		my_mlx_pixel_put(&img, x, y, 0xFF0000);
		x++;
		if (x == 719)
		{
			x = 0;
			y++;
		}
		if (y == 50)
			break;
	}
	while (x < 720)
	{
		my_mlx_pixel_put(&img, x, y, 0xFFA500);
		x++;
		if (x == 719)
		{
			x = 0;
			y++;
		}
		if (y == 100)
			break;
	}
	while (x < 720)
	{
		my_mlx_pixel_put(&img, x, y, 0xFFFF00);
		x++;
		if (x == 719)
		{
			x = 0;
			y++;
		}
		if (y == 150)
			break;
	}
	while (x < 720)
	{
		my_mlx_pixel_put(&img, x, y, 0x008000);
		x++;
		if (x == 719)
		{
			x = 0;
			y++;
		}
		if (y == 200)
			break;
	}
	while (x < 720)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF);
		x++;
		if (x == 719)
		{
			x = 0;
			y++;
		}
		if (y == 250)
			break;
	}
	while (x < 720)
	{
		my_mlx_pixel_put(&img, x, y, 0x4B0082);
		x++;
		if (x == 719)
		{
			x = 0;
			y++;
		}
		if (y == 300)
			break;
	}
	while (x < 720)
	{
		my_mlx_pixel_put(&img, x, y, 0xEE82EE);
		x++;
		if (x == 719)
		{
			x = 0;
			y++;
		}
		if (y == 350)
			break;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
