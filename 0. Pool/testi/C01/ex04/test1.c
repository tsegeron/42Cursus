#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b)
{
    int c;
    c = *a / *b;
    *b = *a % *b;
    *a = c;
}

void ft_ultimate_div_mod(int *a, int *b);

int main(void)
{
    int a;
    int b;

    a = 106;
    b = 10;
    //printf ("%d\n", a);
    //printf ("%d\n", b);
    ft_ultimate_div_mod (&a, &b);
    printf ("%d\n", a);
    printf ("%d\n", b);
    return (0);
}

//printf ("%d\n", a);
//printf ("%d\n", b);

