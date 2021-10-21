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

char *ft_strstr(char *str, char *to_find)
{
    unsigned int i;
    unsigned int j;
    unsigned int k;
    unsigned int m;
    unsigned int n;
    unsigned int o;
    int char result;
    
    i = 0;
    j = 0;
    o = 0;
    *result = str;
    m = ft_strlen(str);
    n = ft_strlen(to_find);
    while (str[i] < to_find[j])
        i++;
    k = i;
    while (j != n)
    {
        if (str[k] == to_find[j])
        {
            j++;
            k++;
        }
        else
            return (NULL);
    }
    while (o < i)
    {
        str[o] = to_find[i]
    }
    return (*result);
}

char *ft_strstr(char *str, char *to_find);

int main(void)
{
    char str[] = "123457789";
    char to_find[] = "45";
    
    printf ("%s\n", strstr (str, to_find));
    
    printf ("%s\n", ft_strstr(str, to_find));
    return (0);
}

//#include <string.h> для встроенной strcpy

//недоделан
