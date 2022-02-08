/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:09:07 by ababa             #+#    #+#             */
/*   Updated: 2021/12/24 17:23:20 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_element_check(char	**d_ptr, int count_y, int count_x)
{
	char	*storage;
	int	i;

	i = 1;
	while (d_ptr[i])
	{
		storage = map_element_check_2(d_ptr, count_y, count_x, i);
		i++;
	}
	if (ft_strcmp(storage, "EPXCBB") != 0)
	{
		ft_putstr("Error :\nInvalid map, please check your elements!");
		exit(1);
	}
	//passing i for the 5 variable norminette rule
	map_parsing(d_ptr, count_y, count_x, i);
}

static void	map_border_check(char	**d_ptr, int count_y, int count_x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d_ptr[i])
	{
		while ((i == 0 || i == (count_y - 1)) && j < count_x)
		{
			if (d_ptr[i][j] != '1')
			{
				ft_putstr("Error :\nInvalid map, please close your map!\n");
				exit(1);
			}
			j++;
		}
		j = 0;
		if ((d_ptr[i][0] != '1') || (d_ptr[i][count_x - 1] != '1'))
		{
			ft_putstr("Error :\nInvalid map, please close your map!\n");
			exit(1);
		}
		i++;
	}
	map_element_check(d_ptr, count_y, count_x);
}

static void	map_rect_check_2(size_t *x1, size_t x2, char **d_ptr)
{
	while (d_ptr[*x1])
	{
		if (ft_strlen(d_ptr[*x1]) != x2)
		{
			ft_putstr("Error :\nInvalid map, please submit a rectangular map!");
			exit(1);
		}
		*x1 = *x1 + 1;
	}
	if (*x1 == x2)
	{
		ft_putstr("Error :\nYour map is square shaped, submit a rectangular map\n");
		exit(1);
	}
}

static void	map_rect_check(char	*str)
{
	size_t	x1;
	size_t	x2;
	char	*ptr;
	char	**d_ptr;

	/*x2 predecremented to account for the \n character!*/
	x1 = 0;
	x2 = 0;
	while (str[x1] != '\n')
		x1++;
	ptr = ft_strrchr(str, '\n');
	while (ptr[x2] != '\0')
		x2++;
	if (x1 != --x2)
	{
		ft_putstr("Error :\nInvalid map, please submit a rectangular map!");
		exit(1);
	}
	x1 = 0;
	d_ptr = ft_split(str, '\n');
	map_rect_check_2(&x1, x2, d_ptr);
	map_border_check(d_ptr, x1, x2);
}

int	main(int argc, char *argv[])
{
	int	read_ret;
	int	fd;

	fd = open(argv[1], O_RDWR);
	if (argc != 2)
	{
		ft_putstr("Error :\nInvalid arguments, please try again!\n");
		exit(1);
	}
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
	{
		ft_putstr("Error :\nInvalid file extension\n");
		exit(1);
	}
	if (fd == -1)
	{
		ft_putstr("Error :\nInvalid map file\n");
		exit(1);
	}
	read_ret = read(fd, argv[1], 10000000);
	argv[1][read_ret] = '\0';
	map_rect_check(argv[1]);
}
