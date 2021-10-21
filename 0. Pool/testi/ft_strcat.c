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

char *ft_strcat(char *dest, char *src)
{
    unsigned int j;
    unsigned int i;
    
    i = 0;
    j = ft_strlen(dest);
    while (src[i] != '\0')
    {
        dest[j] = src[i];
        j++;
        i++;
    }
    return (dest);
}

char *ft_strcat(char *dest, char *src);

int main(void)
{
    char dest[20] = "12345";
    char src[] = " 789";
    
    //strcat(dest, src);
    //printf ("%s\n", dest);
    //dest[20] = "omaeva mo";
    //ft_strcat(dest, src);
    printf ("%s\n", ft_strcat(dest, src));
    return (0);
}

//#include <string.h> для встроенной strcpy

