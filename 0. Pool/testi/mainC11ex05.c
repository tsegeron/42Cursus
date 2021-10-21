#include <unistd.h>

int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void    ft_putnbr(int nb)
{
    char    a;

    if (nb == -2147483648)
    {
        write (1, "-2", 2);
        ft_putnbr (147483648);
    }
    else
    {
        if (nb < 0)
        {
            nb = -nb;
            write (1, "-", 1);
        }
        a = (nb % 10 + '0');
        nb = nb / 10;
        if (nb != 0)
            ft_putnbr(nb);
        write (1, &a, 1);
    }
}

int    ft_atoi(char *str)
{
    int    res;
    int    m;
    int    i;

    res = 0;
    m = 1;
    i = 0;
    while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') || \
           (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
        i++;
    while ((str[i] == '-') || (str[i] == '+'))
    {
        if (str[i] == '-')
            m = -1 * m;
        i++;
    }
    while ((str[i] < 58) && (str[i] > 47))
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return (res * m);
}

int    check_operator(char *operator)
{
    if (ft_strlen(operator) > 1)
        return (0);
    if (operator[0] == '+')
        return (1);
    if (operator[0] == '-')
        return (2);
    if (operator[0] == '/')
        return (3);
    if (operator[0] == '*')
        return (4);
    if (operator[0] == '%')
        return (5);
    else
        return (0);
}

int    check_divmod_0(int operator, int b)
{
    if (operator == 3 && b == 0)
    {
        write (1, "Stop : division by zero\n", 24);
        return (1);
    }
    if (operator == 5 && b == 0)
    {
        write (1, "Stop : modulo by zero\n", 22);
        return (1);
    }
    return (0);
}

void    print_result(int a, int operator, int b)
{
    int    result;

    if (operator == 1)
        result = a + b;
    if (operator == 2)
        result = a - b;
    if (operator == 3)
        result = a / b;
    if (operator == 4)
        result = a * b;
    if (operator == 5)
        result = a % b;
    ft_putnbr(result);
    write (1, "\n", 1);
}

int    main(int ac, char **av)
{
    int    (*f)(char    *);
    int    (*ft)(char    *);
    int     a;
    int     operator;
    int     b;

    f = &check_operator;
    ft = &ft_atoi;
    if (ac != 4)
        return (0);
    operator = f(av[2]);
    a = ft(av[1]);
    b = ft(av[3]);
    if (operator == 0)
    {
        write (1, "0\n", 2);
        return (0);
    }
    if (check_divmod_0(operator, b) == 1)
        return (0);
    print_result(ft(av[1]), f(av[2]), ft(av[3]));
    return (0);
}
