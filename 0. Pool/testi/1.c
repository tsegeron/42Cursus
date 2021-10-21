#include <stdio.h>


void ft_ft(int *nbr)
{
*nbr = 42;
}

void ft_ft(int *nbr);


int main(void)
{
    int a;
    int *nbr;
    
    a = 11;
    nbr = &a;
    printf ("%d\n", a);
    ft_ft (nbr);
    printf ("%d\n", *nbr);
   
    return (0);
}

// printf
