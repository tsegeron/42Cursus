#include <unistd.h>

void    ft_putstr(char *str)
{
    int    i;

    i = 0;
    while (str[i] != '\0')
    {
        write (1, &str[i], 1);
        i++;
    }
}

int    main(int a, char **b)
{
    if (a != 0)
        ft_putstr(*b);
    write (1, "\n", 1);
    return (0);
}
