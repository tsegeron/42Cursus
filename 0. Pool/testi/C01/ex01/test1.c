#include <stdio.h>

void ft_ultimate_ft(int *********nbr)
{
*********nbr = 42;
}

void ft_ultimate_ft(int *********nbr);


int main(void)
{
    int a;
    int *nbr9;
    int **nbr8;
    int ***nbr7;
    int ****nbr6;
    int *****nbr5;
    int ******nbr4;
    int *******nbr3;
    int ********nbr2;
    int *********nbr;
    
    a = 11;
    nbr9 = &a;
    nbr8 = &nbr9;
    nbr7 = &nbr8;
    nbr6 = &nbr7;
    nbr5 = &nbr6;
    nbr4 = &nbr5;
    nbr3 = &nbr4;
    nbr2 = &nbr3;
    nbr = &nbr2;
    
    printf ("%d\n", a);
    ft_ultimate_ft (nbr);
    printf ("%d\n", a);
    
    return (0);
}

// printf

