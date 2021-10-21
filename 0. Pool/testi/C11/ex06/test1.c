#include <unistd.h>
#include <stdlib.h>

void    ft_swap(char **a, char **b)
{
    char    *c;

    c = *a;
    *a = *b;
    *b = c;
}

int ft_strcmp(char *s1, char *s2)
{
    unsigned int i;

    i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i])
    {
        i++;
    }
    return (s1[i] - s2[i]);
}

void    ft_putstr(char *str)
{
    int    i;

    i = 0;
    while (str[i] != '\0')
    {
        write (1, &str[i], 1);
        i++;
    }
}

void ft_sort_string_tab(char **tab)
{
    int m;
    int n;
    
    m = 0;
    n = 1;
    while (tab[m] != NULL)
    {
        while (tab[n] != NULL)
        {
            if (ft_strcmp(tab[m], tab[n]) > 0)
                ft_swap(&tab[m], &tab[n]);
            n++;
        }
        m++;
        n = m + 1;
    }
    m = 0;
    while (tab[m] != NULL)
    {
        ft_putstr(tab[m]);
        write (1, "\n", 1);
        m++;
    }
}

int main(void)
{
    char *tab[5];
    
    tab[0] = "789";
    tab[1] = "056";
    tab[2] = "123";
    tab[3] = "!wetg";
    tab[4] = NULL;
    ft_sort_string_tab(tab);
}

