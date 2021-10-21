#include <unistd.h>

void ft_swap(int *a, int *b)
{
    int d;
    d = *a;
    *a = *b;
    *b = d;
}

void    ft_sort_int_tab(int *tab, int size)
{
    int a;
    int b;
    int c;

    a = 0;
    c = size - 1;
    while (a < c)
    {
        b = a + 1;
        while (b <= c)
        {
            if (tab[a] > tab[b])
            ft_swap(&tab[a], &tab[b]);
            b++;
        }
        a++;
    }
}

void ft_sort_int_tab(int *tab, int size);

int main(void)
{
    int tab[] = {23, 1, 6, 2, 36, 5, 14, 9, 25};
    int size = 9;
    
    ft_sort_int_tab(tab, size);
    
    return (0);
}
