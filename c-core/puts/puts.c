#include <unistd.h>

int	puts(const char *s)
{
	unsigned int		i;

	i = 0;
	if (s[0] == '\0')
	{
		write(1, "\n", 1);
		return (0);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (i);
}
