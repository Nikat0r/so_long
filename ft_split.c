/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:24:44 by ababa             #+#    #+#             */
/*   Updated: 2021/12/24 11:25:04 by ababa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_word_count(char *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			word_count++;
			i--;
		}
		i++;
	}
	return (word_count);
}

static char	*ft_strndup(char *s, int n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(n + 1);
	if (ptr == NULL)
		return (ptr);
	while (s[i] && i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	**filling(char **ptr, char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] != c && s[j] != '\0')
				j++;
			ptr[k] = ft_strndup(&s[i], j - i);
			k++;
			i = --j;
		}
		i++;
	}
	ptr[k] = NULL;
	return (ptr);
}

char	**ft_split(char *s, char c)
{	
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	return (filling(ptr, s, c));
}