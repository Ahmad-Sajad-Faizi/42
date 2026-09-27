#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

t_stock_str	*ft_strs_to_tab(int argc, char **argv)
{
	t_stock_str	*arr;
	int			i;

	arr = malloc(sizeof(t_stock_str) * (argc + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		arr[i].size = ft_strlen(argv[i]);
		arr[i].str = argv[i];
		arr[i].copy = ft_strdup(argv[i]);
		if (!arr[i].copy)
		{
			while (i > 0)
			{
				i--;
				free(arr[i].copy);
			}
			free(arr);
			return (NULL);
		}
		i++;
	}
	arr[i].size = 0;
	arr[i].str = 0;
	arr[i].copy = 0;
	return (arr);
}
