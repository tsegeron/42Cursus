#include <stdio.h>
int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
    {
        len++;
    }
//    printf("ft_strlen return %d\n", len);
    return (len);
}