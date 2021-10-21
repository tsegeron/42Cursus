#include <stdio.h>

void ft_swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void ft_swap(int *a, int *b);


int main(void)
{
    int a;
    int b;
    
    a = 1;
    b = 0;
    printf ("%d\n", a);
    printf ("%d\n", b);
    ft_swap (&a, &b);
    printf ("%d\n", a);
    printf ("%d\n", b);
    
    return (0);
}
