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

static void	map_element_check(char	**d_ptr, char	*str, int count_y, int count_x)
{
	char	storage[5];
	int		i;
	int		j;
	
	i = 1;
	storage[0]='\0';
	storage[1]='\0';
	storage[2]='\0';
	storage[3]='A';

	//silencing the warning
	//free(str);
	while (d_ptr[i])
	{
		j = 1;
		while (i < count_y && j < count_x)
		{
			if (d_ptr[i][j] == 'E')
				storage[0] = 'E';
			else if (d_ptr[i][j] == 'P')
			{
				storage[1] = 'P';
				storage[3] += 1;
			}
			else if (d_ptr[i][j] == 'C')
				storage[2] = 'C';
			else if (d_ptr[i][j] != '1' && d_ptr[i][j] != '0')
			{
				ft_putstr("Invalid map, your map contains wrong elements!");
				exit(1);
			}
			j++;	
		}
		i++;
	}
	storage[4] = '\0';
	if (ft_strcmp(storage, "EPCB") != 0)
	{
		ft_putstr("Invalid map, please check your elements!");
		exit(1);
	}
	map_parsing(d_ptr, count_y, count_x);
}

static void	map_border_check(char	**d_ptr, char	*str, int count_y, int count_x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d_ptr[i])
	{
		while ((i == 0 || i == count_y) && j < count_x)
		{
			if (d_ptr[i][j] != '1')
			{
				ft_putstr("Invalid map, please close your map!");
				exit(1);
			}
			j++;
		}
		j = 0;
		if ((d_ptr[i][0] != '1') || (d_ptr[i][count_x - 1] != '1'))
		{
			ft_putstr("Invalid map, please close your map!");
			exit(1);
		}
		i++;
	}
	map_element_check(d_ptr, str, count_y, count_x);
}

static void	map_rect_check(char	*str)
{
	size_t	x1;
	size_t	x2;
	char	*ptr;
	char	**d_ptr;

	x1 = 0;
	x2 = 0;
	while (str[x1] != '\n')
		x1++;
	ptr = ft_strrchr(str, '\n');
	while (ptr[x2] != '\0')
		x2++;
	//x2 predecremented to account for the \n character!
	if (x1 != --x2)
	{
		ft_putstr("Invalid map, please submit a rectangular map!");
		exit(1);
	}
	x1 = 0;
	d_ptr = ft_split(str, '\n');
	while (d_ptr[x1])
	{
		if (ft_strlen(d_ptr[x1]) != x2)
		{
			ft_putstr("Invalid map, please submit a rectangular map!");
			exit(1);
		}
		x1++;
	}
	if (x1 == x2)
	{
		ft_putstr("Your map is square shaped, please submit a rectangular map!");
		exit(1);
	}
	map_border_check(d_ptr, str, --x1, x2);
	//x1 predecremented because it's gonna be used as an index!
}

int	main(int argc, char *argv[])
{
	int read_ret;

	if (argc != 2)
	{
		ft_putstr("Invalid arguments, please try again!\n");
		exit(1);
	}
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
	{
		ft_putstr("Invalid file extension\n");
		exit(1);
	}
	int	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		ft_putstr("Invalid map file\n");
		exit(1);
	}
	read_ret = read(fd, argv[1], 10000000);
	argv[1][read_ret] = '\0';
	map_rect_check(argv[1]);
}
