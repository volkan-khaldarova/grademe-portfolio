#include <unistd.h>

int	putchar(int c)
{
	char	character;

	character = c;
	write(1, &character, 1);
	return ((int) c);
}
