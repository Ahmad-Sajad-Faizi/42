char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return(dest);
}
/*
#include <stdio.h>
int main(void)
{
	char src[] = "This is just a text.";
	char dest[50];
	printf("src: %s\n", src);
	ft_strncpy(dest, src, 8);
	printf("dest: %s\n",dest);
	return(0);
}
*/
