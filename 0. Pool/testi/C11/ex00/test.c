#include <unistd.h>

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void ft_putnbr(int nb)
{
    char a;
    if (nb == -2147483648)
    {
        write (1, "-2", 2);
        ft_putnbr (147483648);
    }
    else
    {
        if (nb < 0)
        {
            nb = -nb;
            ft_putchar('-');
        }
        a = (nb % 10 + '0');
        nb = nb / 10;
        if (nb != 0)
            ft_putnbr(nb);
        ft_putchar(a);
    }
}

void ft_foreach(int *tab, int length, void(*f)(int))
{
    int i;
    
    i = 0;
    while (length != i)
    {
        f(tab[i]);
        i++;
    }
}

void ft_foreach(int *tab, int length, void(*f)(int));

int main (void)
{
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int length;
    void(*f)(int);
    
    length = 8;
    f = &ft_putnbr;
    ft_foreach(tab, length, f);
    return (0);
}
