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

void ft_putnbr(int nb);

int main(void)
{
    int nb;
    
    nb = -2147483648;
    ft_putnbr(nb);
    return (0);
}
