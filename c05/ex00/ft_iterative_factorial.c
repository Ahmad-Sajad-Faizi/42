int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0 || nb > 12)
		return (0);
	result = 1;
	while (nb > 1)
	{
		result *= nb;
		nb--;
	}
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("5! = %d\n", ft_iterative_factorial(5));
	printf("0! = %d\n", ft_iterative_factorial(0));
	printf("-1! = %d\n", ft_iterative_factorial(-1));
	printf("12! = %d\n", ft_iterative_factorial(12));
	return(0);
}
*/
