#include <stdio.h>

int    ft_strlen(char *str)
{
    int    l;

    l = 0;
    while (str[l] != '\0')
        l++;
    return (l);
}


unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int i, sizes;
    
    i = 0;
    size = ft_strlen(dest);
    sizes = ft_strlen(src);
    size == 0 ? (return (size)) : sizes
    while (size <= sizes ? i != size : size > sizes ? i !=sizes)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
/*    if (ls < l && ls < n)
    {
        while (i != l)
        {
            dest[i] = '\0';
            i++;
        }
    }
 */

 return (dest);
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

int main(void)
{
    char dest[] = "poroshok";
    char src[] = "horosho";
    unsigned int size;
    
    ft_strlcpy (dest, src, size);
    printf ("%s", dest);
}
