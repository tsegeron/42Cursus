#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod = a % b;
}

void ft_div_mod(int a, int b, int *div, int *mod);

int main(void)
{
    int a;
    int b;
    int div;
    int mod;
    
    a = 106;
    b = 10;
    //printf ("%d\n", a);
    //printf ("%d\n", b);
    ft_div_mod (a, b, &div, &mod);
    
    return (0);
}

//printf ("%d\n", a);
//printf ("%d\n", b);
