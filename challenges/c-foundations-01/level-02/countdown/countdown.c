#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	char		i;

	i = '9';
	while (i >= '0')
	{
		ft_putchar(i);
		i--;
	}
	ft_putchar('\n');

	return (0);
}
