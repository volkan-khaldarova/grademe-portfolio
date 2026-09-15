#include <unistd.h>
#include <stdlib.h>

/* Function to print a single character */
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

/* Function to print a single line of the box */
void    print_line(int width, char edge, char fill)
{
    int i;

    i = 0;
    while (i < width)
    {
        if (i == 0 || i == width - 1)
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

/* Function to generate the box */
void    draw_box(int width, int height)
{
    int y;

    if (width <= 0 || height <= 0)
    {
        return;
    }
    y = 0;
    while (y < height)
    {
        if (y == 0 || y == height - 1)
        {
            print_line(width, '+', '-');
        }
        else
        {
            print_line(width, '|', ' ');
        }
        y++;
    }
}

/* Main execution block */
int main(int argc, char **argv)
{
    int width;
    int height;

    if (argc == 3)
    {
        width = atoi(argv[1]);
        height = atoi(argv[2]);
        draw_box(width, height);
    }
    else
    {
        write(1, "wrong number of arguments\n", 26);
    }
    return (0);
}