#include <stdio.h>

int    ft_strlen(char *str)
{
    int    l;

    l = 0;
    while (str[l] != '\0')
        l++;
    return (l);
}

int ft_str_is_uppercase(char *str)
{
    int i;
    int l;
    
    i = 0;
    l = ft_strlen(str);
    while (str [i] != '\0')
    {
    if ((str[i] >= 'A' && str[i] <= 'Z'))
        i++;
    else
        break ;
    }
    if (i == l)
        return 1;
    else
        return 0;
}

int ft_str_is_uppercase(char *str);

int main(void)
{
    char str[] = "DADA1";
    
    ft_str_is_uppercase(str);
    printf ("%d", ft_str_is_uppercase(str));
}


