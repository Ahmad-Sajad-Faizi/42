void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while(i < size - 1)
	{
		j = 0;
		while(j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int arr[] = {5, 2, 8, 1, 9, 3};
	int size = 6;
	int i;

	printf("Before: ");
	i = 0;
	while(i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

	ft_sort_int_tab(arr, size);

	printf("After:  ");
	i = 0;
	while(i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

	return (0);
}
*/
