#include <unistd.h>

void ft_rec(int nbr, int l, char *base)
{
    int a;
    
    if (nbr < 0 && nbr > -2147483648)
    {
        write (1, "-", 1);
        nbr = -nbr;
    }
    a = (nbr % l);
    nbr = nbr / l;
    if (nbr != 0)
        ft_rec(nbr, l, base);
    write (1, &base[a], 1);
}

void ft_putnbr_base(int nbr, char *base)
{
    int l;
    int c;
    int z;
    
    l = 0;
    c = 1;
    z = 0;
    while (base[l] != '\0')
    {
        if ((base[l] == '+') || (base[l] == '-'))
        z = 1;
        while (base[c] != '\0')
        {
            if ((base[l] == base[c]) || \
                 (base[c] == ((base[l] == '+') || (base[l] == '-'))))
                z = 1;
            c++;
        }
        l++;
        c = l + 1;
    }
    if (z != 1 && l != 1)
        ft_rec(nbr, l, base);
}

void ft_putnbr_base(int nbr, char *base);

int main(void)
{
    int nbr;
    char base[] = "01234567";
    
    nbr = -2147483648;
    ft_putnbr_base(nbr, base);
    //printf ("%d\n", atoi(base));
    //printf ("%d\n", ft_atoi(base));
    return (0);
}

