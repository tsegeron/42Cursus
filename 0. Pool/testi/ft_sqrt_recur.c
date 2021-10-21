#include <stdio.h>

int ft_sqrt(int nb)
{
    unsigned int num;
    
    num = 1;
    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return (nb);
    while (num * num <= (unsigned int) nb)
        ft_sqrt(num++);
    num--;
    if ((num * num) == ((unsigned int) nb))
        return (num);
    else
        return (0);
}

int ft_sqrt(int nb);

int main(void)
{
    int nb;
    
    nb = 2147395600;
    printf ("%d\n", ft_sqrt(nb));
    return (0);
}
