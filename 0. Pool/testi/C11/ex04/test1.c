#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int    check1 (char *a)
{
    (void) a;
    return 1;
}

int    ft_sort_int_tab(int tab1, int tab2)
{
    if (tab1 - tab2 < 0)
        return (-1);
    if (tab1 - tab2 == 0)
        return (0);
    else
        return (1);
}

int check(int *tab, int length, int(*f)(int, int))
{
    int i;
    
    i = 0;
    if (tab[i] >= tab[length - 1])
    {
        while (i != length - 1)
        {
            if (f(tab[i], tab[i + 1]) >= 0)
                i++;
            else
                return(0);
        }
    }
    return (1);
}

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
    int i;
    
    i = 0;
    if (length <= 2)
        return (1);
    if (tab[i] <= tab[length - 1])
    {
        while (i != length - 1)
        {
            if (f(tab[i], tab[i + 1]) <= 0)
                i++;
            else
                return(0);
        }
    }
    else
    {
        if (check(tab, length, f) == 0)
            return (0);
    }
    return (1);
}

int ft_is_sort(int *tab, int length, int(*f)(int, int));

int main (void)
{
    int tab[3] = {12, 12, 13};
    int length = 3;
    int(*f)(int, int);
    
    //int i = 0;
    //tab[0] = {123};
    //tab[1] = {456};
    //tab[2] = {789};
    //char *result;
    
    f = &ft_sort_int_tab;
    /*result = malloc(sizeof(int) * length);
    if (result == NULL)
        return (0);
    result = ft_any(tab, f);*/
    //while (length != i)
    //{
        printf ("%d\n", ft_is_sort(tab, length, f));
       // i++;
    //}
    //free(result);
    return (0);
}
