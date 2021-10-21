#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int fact;
    
    fact = 1;
    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return (1);
    while (nb != 1)
    {
        fact = fact * nb;
        nb--;
    }
    return (fact);
}

int ft_iterative_factorial(int nb);

int main(void)
{
    int n;
    while (scanf ("%d", &n) == 1) {
      printf ("Factorial of %d = %d\n", n, ft_iterative_factorial(n));
    }
    return (0);
}
