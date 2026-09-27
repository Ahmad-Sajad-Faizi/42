#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_separator(*str, charset) && !in_word)
		{	
			in_word = 1;
			count++;
		}
		else if (is_separator(*str, charset))
			in_word = 0;
		str++;
	}
	return (count);
}

char	*word_dup(char *str, int start, int end)
{
	char	*word;
	int		i;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		words;
	int		i;
	int		start;
	int		end;

	words = count_words(str, charset);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	start = 0;
	while (str[start])
	{
		if (is_separator(str[start], charset))
		{
			start++;
			continue ;
		}
		end = start;
		while (str[end] && !is_separator(str[end], charset))
		end++;
		arr[i] = word_dup(str, start, end);
		if (!arr[i])
		{
			while (--i >= 0)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		i++;
		start = end;
	}
	arr[i] = NULL;
	return (arr);
}
/*
#include <stdio.h>
int main(void)
{
	char *str = "Hello,World;42 Piscine!C07";
	char *charset = ",; !";
	char **split;
	int i = 0;

        printf("Splitting '%s' by charset '%s'\n", str, charset);
	split = ft_split(str, charset);
	if (split == NULL)
	{
		printf("Returned NULL\n");
	        return (1);
	}
	while (split[i] != NULL)
	{
		printf("Word %d: '%s'\n", i, split[i]);
		free(split[i]);
		i++;
	}
        free(split);
	printf("\nTesting empty string and multiple delimiters:\n");
	split = ft_split(",,, ;;;", ",; ");
	if (split != NULL)
	{
		i = 0;
	        while (split[i] != NULL)
	        {
		        printf("Word %d: '%s'\n", i, split[i]);
		        free(split[i]);
		        i++;
		}
	        if (i == 0)
		        printf("No words found (Expected).\n");
		free(split);
	}
	return (0);
}
*/
