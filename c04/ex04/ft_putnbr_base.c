#include <unistd.h>
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
				return(0);
			j++;
		}
		i++;
	}
	return (1);
}
void	ft_putnbr_base_rec(unsigned int nbr, char *base, unsigned int base_len)
{
	if (nbr >= base_len)
		ft_putnbr_base_rec(nbr / base_len, base, base_len);
	write(1, &base[nbr % base_len], 1);
}
void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	unbr;
	unsigned int	base_len;

	if (!check_base(base))
		return ;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		unbr = -nbr;
	}
	else
		unbr = nbr;
	ft_putnbr_base_rec(unbr, base, base_len);
}
#include <stdio.h>
int	main(void)
{
	printf("decimal (20, base 10): ");
	ft_putnbr_base(20, "0123456789");
	printf("\n");
	printf("Binary (20, base 2): ");
	ft_putnbr_base(20, "01");
	printf("\n");
	printf("Hexadecimal (20, base 16): ");
	ft_putnbr_base(20, "0123456789abcdef");
	printf("\n");
	printf("Octal 'poneyvif' (20)");
	ft_putnbr_base(20, "poneyvif");
	printf("\n");
	return(0);
}
