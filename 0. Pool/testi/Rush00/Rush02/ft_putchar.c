#include <unistd.h>

void    ft_putchar (char c) // функция для вывода
{
    write (1, &c, 1);
}
