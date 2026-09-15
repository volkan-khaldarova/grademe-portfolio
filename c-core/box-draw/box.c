#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_line(int	witdh, char edge, char fill)
{
	int		i;

	i = 0;
	while (i < witdh)
	{
		if (i == 0 || i == witdh - 1)
		{
			ft_putchar(edge);
		}
		else
		{
			ft_putchar(fill);
		}
		i++;
	}
	ft_putchar('\n');
}

void	draw_box(int witdh, int height)
{
	int		y;

	y = 0;
	if (witdh <= 0 || height <= 0)
		return ;
	while (y < height)
	{
		if (y == 0 || y == height - 1)
		{
			print_line(witdh, '+', '-');
		}
		else
		{
			print_line(witdh, '|', ' ');
		}
		y++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		draw_box(atoi(argv[1]), atoi(argv[2]));
	}
	else
	{
		write(1, "wrong number of arguments\n", 26);
	}
	return (0);
}