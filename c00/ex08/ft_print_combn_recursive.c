#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}
void	ft_print_combn_recursive(int n, int start, int combo[], int index, int *first)
{
	int	i;
	if (index == n)
	{
		if (!*first)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		*first = 0;
		i = 0;
		while (i < n)
		{
			ft_putchar(combo[i] + '0');
			i++;
		}
		return;
	}
	i = start;
	while (i <= 9 - (n - index))
	{
		combo[index] = i;
		ft_print_combn_recursive(n, i + 1, combo, index + 1, first);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	comb[9];
	int	first;
	first = 1;
	if (n > 0 && n < 10)
		ft_print_combn_recursive(n, 0, comb, 0, &first);
}
/*
int main(void)
{
    ft_print_combn(2);
    ft_putchar('\n');
    return (0);
}
*/
