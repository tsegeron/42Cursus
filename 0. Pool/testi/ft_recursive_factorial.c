#include <stdio.h>

/*
int ft_recursive_factorial(int nb)
{
    return (((nb == 0) || (nb == 1)) ? 1 : \
            nb > 1 ? (nb * ft_recursive_factorial(nb - 1)) : 0);
}
*/

int    ft_recursive_factorial(int nb)
{
    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return (1);
    return (nb * ft_recursive_factorial(nb - 1));
}

int ft_recursive_factorial(int nb);

int main(void)
{
    int n;
    while (scanf ("%d", &n) == 1) {
      printf ("Factorial of %d = %d\n", n, ft_recursive_factorial(n));
    }
    return (0);
}

/*
while (nb != 1)
{
    fact = fact * nb;
    nb--;
}
*/
