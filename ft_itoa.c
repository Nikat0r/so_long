#include "so_long.h"

static int	nlen(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*stringfill(char *str, long n)
{
	int	i;

	i = nlen(n) - 1;
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	while (i >= 0 && n > 9)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[i] = n % 10 + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = malloc (nlen(n) + 1);
	if (str == NULL)
		return (NULL);
	str[nlen(n)] = '\0';
	stringfill(str, n);
	return (str);
}
