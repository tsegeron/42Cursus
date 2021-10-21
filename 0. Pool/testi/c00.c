#include <unistd.h>

void    ft_putchar (char c)
{
    write (1, &c, 1);
}

void    shownums (int a, int b)
{
    ft_putchar (48 + a / 10);
    ft_putchar (48 + a % 10);
    ft_putchar (' ');
    ft_putchar (48 + b / 10);
    ft_putchar (48 + b % 10);
    if (!(a == 98 && b == 99))
    {
        ft_putchar(',');
        ft_putchar(' ');
    }
    else
        write (1, "\n", 1);
}

void    ft_print_comb2(void)
{
    int    a;
    int    b;

    a = 0;
    while (a <= 98)
    {
        b = a + 1;
        while (b <= 99)
        {
            shownums (a, b);
            b++;
        }
        a++;
    }
}

int    main (void)
{
    ft_print_comb2();
    return (0);
}
