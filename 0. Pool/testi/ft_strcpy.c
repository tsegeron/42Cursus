#include <stdio.h>

char *ft_strcpy(char *dest, char *src)
{
    int i;
    
    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return (dest);
}

char *ft_strcpy(char *dest, char *src);

int main(void)
{
    char dest[] = "olololo";
    char src[] = "horosho";
    
    ft_strcpy (dest, src);
    printf ("%s", dest);
}
// #include <stdlib.h> для malloc
// #include <string.h> для встроенной strcpy
