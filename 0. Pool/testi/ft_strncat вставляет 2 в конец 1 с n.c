#include <stdio.h>
#include <string.h>

unsigned int ft_strlen(char *dest)
{
    unsigned int l;
    
    l = 0;
    while (dest[l] != '\0')
        l++;
    
    return (l);
}

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    unsigned int j;
    unsigned int i;
    
    i = 0;
    j = ft_strlen(dest);
    while (src[i] != '\0' && i != nb)
    {
        dest[j] = src[i];
        j++;
        i++;
    }
    return (dest);
}

char *ft_strncat(char *dest, char *src, unsigned int nb);

int main(void)
{
    char dest[20] = "12345";
    char src[] = " 789";
    unsigned int nb;
    
    nb = 6;
    //strcat(dest, src);
    //printf ("%s\n", dest);
    //dest[20] = "omaeva mo";
    //ft_strcat(dest, src);
    printf ("%s\n", ft_strncat(dest, src, nb));
    return (0);
}

//#include <string.h> для встроенной strcpy


