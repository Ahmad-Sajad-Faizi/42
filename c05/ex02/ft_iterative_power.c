int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return(1);
	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("2^3= %d\n", ft_iterative_power(2, 3));
	printf("5^0= %d\n", ft_interative_power(5, 0));
	return(0);
}
*/
