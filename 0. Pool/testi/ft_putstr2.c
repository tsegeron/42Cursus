#include <unistd.h>

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

void ft_putstr(char *str);

int main(void)
{
    char str[] = "Hello world";

    ft_putstr (str);
    return (0);
}
