/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:14:19 by ababa             #+#    #+#             */
/*   Updated: 2021/12/23 17:09:11 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*ft_strrchr(const char *str, int c)
{
	int				len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	while (len > 0)
	{
		if (str[len] == (char) c)
		{
			return ((char *)(str + len));
		}
		len--;
	}
	if (str[len] == (char) c)
	{
		return ((char *)(str + len));
	}
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
