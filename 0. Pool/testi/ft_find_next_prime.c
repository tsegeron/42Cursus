#include <stdio.h>

int ft_is_prime(int nb)
{
    unsigned int num;
    
    num = nb - 1;
    if (nb <= 1)
        return (0);
    while (nb / num != (unsigned int) nb)
    {
        if ((nb / num * num) == ((unsigned int) nb))
            return (0);
        else
            num--;
    }
    return (1);
}

int ft_find_next_prime(int nb)
{
    if (ft_is_prime(nb) == 1)
        return(nb);
    while (ft_is_prime(nb) != 1)
        nb++;
    return (nb);
}

int ft_find_next_prime(int nb);

int main(void)
{

    int n;
    while (scanf ("%d", &n) == 1)
    {
      printf ("Next prime %d\n", ft_find_next_prime(n));
    }
    return (0);
}
