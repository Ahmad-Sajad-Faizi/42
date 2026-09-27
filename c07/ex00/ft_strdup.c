#include <stdlib.h>
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
char	*ft_strdup(char *src)
{
	char	*dup;
	int	i;

	dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str1 = "Hello";
	char *dup1;

	dup1 = ft_strdup(str1);
	printf("original: %s\n", str1);
	printf("Duplicate: %s\n", dup1);
	free(dup1);
	return(0);
}
*/
