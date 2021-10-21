#include <stdio.h>

int    ft_strlen(char *str)
{
    int    l;

    l = 0;
    while (str[l] != '\0')
        l++;
    return (l);
}

char *ft_strcapitalize(char *str)
{
    int i;
    int l;
    
    str[0] = str[0] - 32;
    i = 1;
    l = ft_strlen(str);
    while (str [i] != '\0')
    {
        if (((str[i-1] > '~') || (str[i-1] < '!')) && (str[i] >= 'a' && str[i] <= 'z'))
        {
            str[i] = str[i] -32;
            i++;
        }
        else
            i++;
    }
    return (str);
}

char *ft_strcapitalize(char *str);

int main(void)
{
    char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    
    ft_strcapitalize(str);
    printf ("%s", str);
}
