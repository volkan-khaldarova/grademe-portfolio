#include <stdlib.h>
#include <stddef.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

int		ft_compute_total_len(char **parts, size_t n)
{
	size_t		i;
	size_t		total_len;

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

// str_join returns a fresh string holding the n strings of parts, separated by
// sep. The caller frees it.
char	*str_join(char **parts, size_t n, char sep)
{
	char 	*arr;
	size_t		i;
	size_t		j;
	size_t		word_idx;

	if (n == 0)
	{
		arr = (char *)malloc(sizeof(char) * 1);
		if (!arr)
			return (NULL);
		arr[0] = '\0';
		return (arr);
	}
	arr = (char *)malloc(sizeof(char) * (ft_compute_total_len(parts, n)));
	if (!arr)
		return (NULL);
	word_idx = 0;
	i = 0;
	j = 0;
	while (word_idx < n)
	{
		j = 0;
		while (parts[word_idx][j])
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
	return (arr);
}
