#include <stdlib.h>
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
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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
	int	idx;

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
		idx = get_index(str[i], base);
		if (idx == -1)
			break;
		result = result * base_len + idx;
		i++;
	}
	return (result * sign);
}
char	*ft_putnbr_base(int nbr, char *base)
{
	char	*res;
	int	base_len;
	int	len;
	long	n;

	base_len = ft_strlen(base);
	n = nbr;
	len = 0;
	if (n == 0)
	{
		res = malloc(2);
		if (!res)
			return(NULL);
		res[0] = base[0];
		res[1] = '\0';
		return (res);
	}
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	n = nbr;
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		res[--len] = base[n % base_len];
		n /= base_len;
	}
	return (res);
}
