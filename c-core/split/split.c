#include <stdlib.h>
#include <stddef.h>

static int		is_separator(char c, char *charset)
{
	int		i;

	i = 0;
	if (c == '\0')
		return (1);
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return(1);
		i++;
	}
	return (0);
}

static int		count_words(char *str, char *charset)
{
	int		i;
	int		count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i], charset) == 1)
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
} 

static  char		*word_dup(char *str, int start, int finish)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	len = finish - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char **split(char *str, char *charset)
{
	int		words;
	char	**arr;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	if (!str || !charset)
		return (NULL);
	words = count_words(str, charset);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_separator(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
		{
			start = i;
			while (str[i] != '\0' && is_separator(str[i], charset) == 0)
				i++;
			arr[j] = word_dup(str, start, i);
			j++;
		}
	}
	arr[j] = 0;
	return (arr);
}

