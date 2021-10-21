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

char *ft_strjoin(int size, char **strs, char *sep)
{
if (ft_strlen(strs)
    
    
    
    
    
    
    
    
 
}

char *ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
    int size = 3;
    char *strs;
    char sep = "__";
    
    strs[0] = "123";
    strs[1] = "456";
    strs[2] = "789";
    
    
    //char src[] = "horosho";
    //ft_strdup (src);
    //ft_ultimate_range(range, min, max);
    //while (i != max - min)
    //{
        printf ("%s", ft_strjoin(size, &strs, sep));
    //}
}

//#include <string.h> для встроенной strcpy
//2147483647
// не понял
    

