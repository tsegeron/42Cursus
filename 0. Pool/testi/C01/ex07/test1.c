#include <stdio.h>
void ft_putstr(int *str, int size)
{
    int b;
    int d;
    
    b = 0;
    d = size - 1;
    while (b <= d)
    {
        printf ("%d", str[b]);
        b++;
    }
}

void ft_rev_int_tab(int *tab, int size)
{
    int i;
    int j;
    int c;
    
    i = 0;
    j = size - 1;
    while (tab[i] != j)
    {
        c = tab[i];
        tab[i] = tab[j];
        tab[j] = c;
        i++;
        j--;
    }
    
    ft_putstr (tab, size);
}

void ft_rev_int_tab(int *tab, int size);

int main(void)
{
    int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int size = 9;
    
    ft_rev_int_tab(tab, size);
    
    return (0);
}


