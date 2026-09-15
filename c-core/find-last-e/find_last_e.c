#include <unistd.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		int		i;
		int		occurrence;

		i = 0;
		occurrence = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == 'e')
			{
				occurrence++;
			}
			i++;
		}
		if (occurrence > 0)
		{
			write(1, "e\n", 2);
		}
		else
		{
			write(1, "\n", 1);
		}

	}
	else
	{
		write(1, "e\n", 2);
	}
}