#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
    if (power < 0 && power % 2 == 0 && (nb == 1 || nb == -1))
        return (1);
    if (power < 0 && power % 2 != 0 && nb == -1)
        return (-1);
    if (power < 0 && nb != 1 && nb != -1)
        return (0);
    if (power == 0)
        return (1);
    return (nb * ft_recursive_power(nb, power - 1));
}

int ft_recursive_power(int nb, int power);

int main(void)
{
    int nb;
    int power;
    
    nb = 1;
    power = 3;
    printf ("%d\n", ft_recursive_power(nb, power));
    return (0);
}

/*
 while (scanf ("%d", &n) == 1) {
   printf ("Factorial of %d = %d\n", n, ft_iterative_factorial(n));
 }
 */
