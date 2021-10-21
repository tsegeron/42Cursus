#include <stdio.h>
int ft_is_printable(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!((str[i] <= '~') && (str[i] >= ' ')))
        {
//            printf("ft_is_printable return 0\n");
            return (0);
        }
        i++;
    }
//    printf("ft_is_printable return 1\n");
    return (1);
}

