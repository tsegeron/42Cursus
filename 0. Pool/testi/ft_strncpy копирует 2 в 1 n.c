#include <stdio.h>

int    ft_strlen(char *str)
{
    int    l;

    l = 0;
    while (str[l] != '\0')
        l++;
    return (l);
}


char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int i, l, ls;
    
    i = 0;
    l = ft_strlen(dest);
    ls = ft_strlen(src);
    while (n <= ls ? i != n : i != ls)
    {
        dest[i] = src[i];
        i++;
    }
    if (ls < l && ls < n)
    {
        while (i != l)
        {
            dest[i] = '\0';
            i++;
        }
    }
    return (dest);
}

char *ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
    char dest[] = "olololo";
    char src[] = "horosho";
    unsigned int n;
    
    n = 7;
    ft_strncpy (dest, src, n);
    printf ("%s", dest);
}

//#include <string.h> для встроенной strcpy

/*
 #include <string.h>

 int main(void)
 {
     char dest[] = "olololo";
     char src[] = "horo";
     unsigned int n;
     
     n = 8;
     strncpy (dest, src, n);
     printf ("%s", dest);
 }
 */
