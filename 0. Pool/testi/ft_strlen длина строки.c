#include <stdio.h>

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int ft_strlen(char *str);

int main(void)
{

    char str[] = "12345";

    printf ("%d", ft_strlen(str));
}
