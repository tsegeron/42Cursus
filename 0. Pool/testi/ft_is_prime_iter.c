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

int ft_is_prime(int nb);

int main(void)
{

    int n;
    while (scanf ("%d", &n) == 1)
    {
      printf ("Is it prime? %d\n", ft_is_prime(n));
    }
    return (0);
}
