int	ft_sqrt(int nb)
{
	int	guess;

	if (nb <= 0)
		return (0);
	guess = 1;
	while (guess * guess < nb && guess < 46340)
		guess++;
	if (guess * guess == nb)
		return (guess);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("sqrt (9) = %d\n", ft_sqrt(9));
	return(0);
}
*/
