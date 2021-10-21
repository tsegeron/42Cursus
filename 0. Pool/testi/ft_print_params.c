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
    int    m;

    m = 1;
    while (m != a)
    {
        ft_putstr(b[m]);
        write (1, "\n", 1);
        m++;
    }
    return (0);
}
