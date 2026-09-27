#include <stdlib.h>
int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}	
	return (arr);
}
/*
#include <stdio.h>
int	main(void)
{
	int *range;
	int min = 3;
	int max = 8;
	int i = 0;

	range = ft_range(min, max);
	if (range == NULL)
		printf("Returned NULL\n");
	else
	{
		printf("Range from %d to %d: ", min, max);
		while (i < (max - min))
		{
			printf("%d ", range[i]);
			i++;
		}
		printf("\n");
		free(range);
	}
	return (0);
}
*/
