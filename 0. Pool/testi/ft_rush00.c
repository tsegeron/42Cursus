
#include <unistd.h>

void    ft_putchar (char c)
{
    write (1, &c, 1);
}

void rush51 (int l) // для 5:1 строка
{
    ft_putchar('A');
    while (l > 2)
    {
        ft_putchar('B');
        l--;
    }
    ft_putchar('A');
}

void rush15 (int h) // для 1:5 столбик
{
    ft_putchar('A');
    ft_putchar('\n');
    while (h > 2)
    {
        ft_putchar('B');
        ft_putchar('\n');
        h--;
    }
    ft_putchar('C');
}

void rush1__1 (int l, int h, int x) // для промежуточных строк
{
    while (h > 2)
    {
        ft_putchar('B');
        while (l > 2)
        {
            ft_putchar(' ');
            l--;
        }
        ft_putchar('B');
        ft_putchar('\n');
        l = x;
        h--; // промежуточные строки
    }
}

void rushLastStr (int l) // для последней строки
{
    ft_putchar('C');
    while (l > 2)
    {
        ft_putchar('B');
        l--;
    }
    ft_putchar('C'); //последняя строка
}

void rush(int x, int y)
{
    int l;
    int h;
    
    l = x;
    h = y;
    if ((l == 1) && (h == 1)) // для 1:1
        ft_putchar('A');
    else if ((l > 1) && (h == 1)) // для 5:1
        rush51(l);
    else if ((l == 1) && (h > 1)) // для 1:5
        rush15(h);
    else if ((l > 1) && (h > 1)) // для 5:5
    {
        rush51(l);
        ft_putchar('\n'); // первая строка, см
        l = x;
        rush1__1(l, h, x); // промежуточные строки
        l = x;
        h = y;
        rushLastStr (l); // последняя строка
    }
}

void rush(int x, int y);

int main()
{
rush(5, 5);
return (0);
}
