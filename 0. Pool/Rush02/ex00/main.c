#include <unistd.h>
#include "ft_do_op.h"

void    ft_putnbr(long long int nb)
{
    char    a;

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

void    print_result(long long int a, int operator, long long int b)
{
    long long int    result;

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

long long int    ft_atoi(char *str)
{
    long long int    res;
    int                m;
    int                i;

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

long long int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

long long int    check_operator(char *operator)
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

int    check_divmod_0(int operator, long long int b)
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
    else
        return (0);
}


int	main(int ac, char **av)
{
	long long	int	(*f)(char	*);
	long long	int	(*ft)(char	*);
	long long int	a;
	int				operator;
	long long int	b;

	f = &check_operator;
	ft = &ft_atoi;
	if (ac != 2 || ac != 3 )
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
	print_result(a, operator, b);
	return (0);
}

// ins integer -> 0 to 4294967295 | if not -> return (write (1, "Error\n", 6));
//
