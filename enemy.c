#include "so_long.h"

static void	top_blocked(t_vars *vars, int height)
{
	vars->enemy.switch_int = 1;
	if (vars->enemy.y == vars->enemy.pos_down)
	{
		if (vars->d_ptr[vars->enemy.i - 1][vars->enemy.j] == 'P')
			exit(1);
		vars->enemy.y -= height;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = '0';
		vars->enemy.i--;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = 'X';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->backg, vars->enemy.x, vars->enemy.y + height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, vars->enemy.x, vars->enemy.y);
	}
	else if (vars->enemy.y == vars->enemy.pos_mid)
	{
		if (vars->d_ptr[vars->enemy.i + 1][vars->enemy.j] == 'P')
			exit(1);
		vars->enemy.y += height;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = '0';
		vars->enemy.i++;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = 'X';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->backg, vars->enemy.x, vars->enemy.y - height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, vars->enemy.x, vars->enemy.y);
	}
}

static void	bot_blocked(t_vars *vars, int height)
{
	vars->enemy.switch_int = 2;
	if (vars->enemy.y == vars->enemy.pos_up)
	{	
		if (vars->d_ptr[vars->enemy.i + 1][vars->enemy.j] == 'P')
			exit(1);
		vars->enemy.y += height;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = '0';
		vars->enemy.i++;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = 'X';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->backg, vars->enemy.x, vars->enemy.y - height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, vars->enemy.x, vars->enemy.y);
	}
	else if (vars->enemy.y == vars->enemy.pos_mid)
	{		
		if (vars->d_ptr[vars->enemy.i - 1][vars->enemy.j] == 'P')
			exit(1);
		vars->enemy.y -= height;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = '0';
		vars->enemy.i--;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = 'X';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->backg, vars->enemy.x, vars->enemy.y + height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, vars->enemy.x, vars->enemy.y);
	}
}

static void	enemy_pos_mid(t_vars *vars, int height)
{
	if (vars->enemy.counter == 1)
	{	
		if (vars->d_ptr[vars->enemy.i - 1][vars->enemy.j] == 'P')
			exit(1);
		vars->enemy.y -= height;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = '0';
		vars->enemy.i--;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = 'X';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->backg, vars->enemy.x, vars->enemy.y + height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, vars->enemy.x, vars->enemy.y);
		vars->enemy.counter = 0;		
	}
	else if (vars->enemy.counter == 0)
	{		
		if (vars->d_ptr[vars->enemy.i + 1][vars->enemy.j] == 'P')
			exit(1);
		vars->enemy.y += height;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = '0';
		vars->enemy.i++;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = 'X';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->backg, vars->enemy.x, vars->enemy.y - height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, vars->enemy.x, vars->enemy.y);
		vars->enemy.counter = 1;
	}

}

static void	enemy_pos_up_down(t_vars *vars, int height)
{
	if (vars->enemy.y == vars->enemy.pos_down)
	{			
		if (vars->d_ptr[vars->enemy.i - 1][vars->enemy.j] == 'P')
			exit(1);
		vars->enemy.y -= height;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = '0';
		vars->enemy.i--;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = 'X';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->backg, vars->enemy.x, vars->enemy.y + height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, vars->enemy.x, vars->enemy.y);
	}
	else if (vars->enemy.y == vars->enemy.pos_up)
	{		
		if (vars->d_ptr[vars->enemy.i + 1][vars->enemy.j] == 'P')
			exit(1);
		vars->enemy.y += height;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = '0';
		vars->enemy.i++;
		vars->d_ptr[vars->enemy.i][vars->enemy.j] = 'X';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->backg, vars->enemy.x, vars->enemy.y - height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, vars->enemy.x, vars->enemy.y);
	}
}

void	enemy_movement(t_vars *vars)
{
	int	height;
	int	width;

	//switch_int is to avoid the third condition from being true after moving the X from its original position
	//adding switch_int conditions to ensure only one condition is gonna get satisfied 
	vars->enemy.img = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/so_long/Assets/Enemy.xpm", &width, &height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img, vars->enemy.x, vars->enemy.y);
	vars->backg = mlx_xpm_file_to_image(vars->mlx, "/home/nikator/Desktop/so_long/Assets/Floor.xpm", &width, &height);
	if ((vars->d_ptr[vars->enemy.i - 1][vars->enemy.j] != '0' && vars->d_ptr[vars->enemy.i + 1][vars->enemy.j] == '0' && vars->enemy.switch_int != 0) || vars->enemy.switch_int == 1)
		top_blocked(vars, height);
	else if ((vars->d_ptr[vars->enemy.i - 1][vars->enemy.j] == '0' && vars->d_ptr[vars->enemy.i + 1][vars->enemy.j] != '0' && vars->enemy.switch_int != 0) || vars->enemy.switch_int == 2)
		bot_blocked(vars, height);
	else if ((vars->d_ptr[vars->enemy.i - 1][vars->enemy.j] == '0' && vars->d_ptr[vars->enemy.i + 1][vars->enemy.j] == '0' && vars->enemy.switch_int != 1 && vars->enemy.switch_int != 2) || vars->enemy.switch_int == 0)
	{
		vars->enemy.switch_int = 0;
		if (vars->enemy.y == vars->enemy.pos_mid)
			enemy_pos_mid(vars, height);
		else if (vars->enemy.y == vars->enemy.pos_down || vars->enemy.y == vars->enemy.pos_up)
			enemy_pos_up_down(vars, height);
	}
}
