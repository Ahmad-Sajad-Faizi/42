char *ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return 0;
}
/*
#include <stdio.h>
int main(void)
{
	char *s = "Hello World";
	printf("%s\n", ft_strstr(s, "World"));
	printf("%s\n", ft_strstr(s, "ell"));
	printf("%s\n", ft_strstr(s, "abc"));
	return 0;
}
*/
