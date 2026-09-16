#include <stdlib.h>
#include <stddef.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_compute_total_len(char **parts, size_t n)
{
	size_t		i;
	int			total_len;

	i = 0;
	total_len = 0;
	if (!parts)
		return (0);
	while (i < n)
	{
		total_len += ft_strlen(parts[i]);
		i++;
	}
	total_len += n - 1;
	return (total_len + 1);
}

char	*str_join(char **parts, size_t n, char sep)
{
	size_t		i;
	size_t		j;
	size_t		word_idx;
	char		*arr;

	word_idx = 0;
	arr = NULL;
	if (n == 0)
	{
		arr = (char *)malloc(sizeof(char) * 1);
		if (!arr)
			return (NULL);
		arr[0] = '\0'; 
		return (arr);
	}
	arr = (char *)malloc(sizeof(char) * ft_compute_total_len(parts, n));
	if (!arr)
		return (NULL);
	i = 0;
	while (word_idx < n)
	{
		j = 0;
		while (parts[word_idx][j] != '\0')
		{
			arr[i] = parts[word_idx][j];
			i++;
			j++;
		}
		if (word_idx < n - 1)
		{
			arr[i] = sep;
			i++;
		}
		word_idx++;
	}
	arr[i] = '\0';
	return(arr);
}

