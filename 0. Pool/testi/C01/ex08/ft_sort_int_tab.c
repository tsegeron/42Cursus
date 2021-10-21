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
