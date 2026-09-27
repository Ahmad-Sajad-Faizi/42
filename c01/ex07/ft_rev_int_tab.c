void	ft_rev_int_tab(int *tab, int size)
{
	int index;
	int end;
	int tmp;

	index = 0;
	end = size - 1;
	while (index < end)
	{
		tmp = tab[index];
		tab[index] = tab[end];
		tab[end] = tmp;
		index++;
		end--;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	int size = 5;
	int i;

	printf("Original array: ");
	i = 0;
       	while (i < size)
	{
        printf("%d ", arr[i]);
        i++;
	}
	printf("\n");

	ft_rev_int_tab(arr, size);

	printf("Reversed array: ");
	i = 0;
	while (i < size)
	{
        printf("%d ", arr[i]);
        i++;
	}
	printf("\n");

	return (0);
}
*/
