#include <unistd.h>
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return(s1[i] - s2[i]);
}
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
void	ft_sort_strs(char **strs, int size)
{
	int	i;
	int	j;
	char *tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (ft_strcmp(strs[j], strs[j + 1]) > 0)
			{
				tmp = strs[j];
				strs[j] = strs[j + 1];
				strs[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
int	main(int argc, char **argv)
{
	int	i;
	
	if (argc > 1)
	{
		ft_sort_strs(&argv[1], argc - 1);
		i = 1;
		while (i < argc)
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
