#include <stdio.h>

void ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        printf ("%c", str[i]);
        i++;
    }
}

void ft_putstr(char *str);

int main(void)
{
    char str[] = "Hello world";

    ft_putstr (str);
    return (0);
}
