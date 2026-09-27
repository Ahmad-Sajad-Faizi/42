#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_2digits(int nb)
{
	ft_putchar((nb / 10) + '0');
	ft_putchar((nb % 10) + '0');
}
void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putnbr_2digits(a);
			ft_putchar(' ');
			ft_putnbr_2digits(b);
			if (!(a == 98 && b == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			b++;
		}
		a++;
	}
}
/*
int	main(void)
{
	ft_print_comb2();
	ft_putchar('\n');
	return(0);
}
*/
