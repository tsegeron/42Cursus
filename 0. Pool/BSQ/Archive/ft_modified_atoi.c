#include <stdio.h>
int ft_modified_atoi(char *str, int stop)
{
    int	minus_status;
    int	result;
    int i;

    minus_status = 1;
    result = 0;
    i = 0;
//    printf("ft_modified_atoi get stop = %d\n", stop);
//    printf("ft_modified_atoi get str = %s\n", str);
    while (str[i] == 32 || (str[i] < 14 && str[i] > 8) || str[i] == 45 \
                                                       || str[i] == 43)
    {
        if (str[i] == 45)
            minus_status *= -1;
        i++;
    }
    while (str[i] > 47 && str[i] < 58)
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    while (str[i] == 32 || (str[i] < 14 && str[i] > 8))
        i++;
    if (i == stop && minus_status == 1)
    {
//        printf("ft_modified_atoi return %d\n", result);
        return (result);
    }
//    printf("ft_modified_atoi return %d\n", 0);
    return (0);
}
