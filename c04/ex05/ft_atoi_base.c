int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);	
}
int	check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return(1);
}
int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	base_len;
	int	index;

	if (!check_base(base))
		return (0);
	base_len = ft_strlen(base);
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (1)
	{
		index = get_index(str[i], base);
		if (index == -1)
			break;
		result = result * base_len + index;
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("Decimal ('20', base 10): %d\n", ft_atoi_base("20", "0123456789"));
	printf("Binary ('10100', base 2): %d\n", ft_atoi_base("20", "01"));
	printf("Hexadecimal ('13', base 16): %d\n", ft_atoi_base("13", "0123456798abcdef"));
	printf("Octal 'poneyvif' ('pf'): %d\n", ft_atoi_base("pf", "poneyvif"));
	return(0);
}
*/
