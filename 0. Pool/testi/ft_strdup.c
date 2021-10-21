#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
        i++;
    
    return (i);
}

char *ft_strdup(char *src)
{
    int i;
    char *p;
    
    i = 0;
    p = (char*) malloc(ft_strlen(src) * sizeof(char) + 1);
    if (NULL == p)
        return (NULL);
        
    while (src[i] != '\0')
    {
        p[i] = src[i];
        i++;
    }
    p[i] = '\0';
    return (p);
}

char *ft_strdup(char *src);

int main(void)
{
    char src[] = "horosho";
    
    //ft_strdup (src);
    printf ("%s", ft_strdup (src));
}

//#include <string.h> для встроенной strcpy

