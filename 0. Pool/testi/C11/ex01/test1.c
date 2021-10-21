#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_min_2(int a)
{
    return (a * 2);
}

int    *ft_map(int *tab, int length, int(*f)(int))
{
    int    i;
    int    *changed_tab;

    i = 0;
    changed_tab = malloc(sizeof(int) * (length));
    if (changed_tab == NULL)
        return ((void *)0);
    while (i != length)
    {
        changed_tab[i] = f(tab[i]);
        i++;
    }
    return (changed_tab);
}

int *ft_map(int *tab, int length, int(*f)(int));

int main (void)
{
    int tab[] = {15, 12, 21};
    int length = 3;
    int(*f)(int);
    int i = 0;
    int *result;
    
    f = &ft_min_2;
    result = malloc(sizeof(int) * length);
    if (result == NULL)
        return (0);
    result = ft_map(tab, length, f);
    while (length != i)
    {
        printf ("%d\n", result[i]);
        i++;
    }
    free(result);
    return (0);
}

