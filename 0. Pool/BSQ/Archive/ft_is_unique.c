#include <stdio.h>
int ft_is_unique(char *str) {
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    if ((str[i - 1] != str[i - 2]) && (str[i - 1] != str[i - 3]) && (str[i - 2] != str[i - 3]))
    {
//        printf("ft_is_unique return 1\n");
        return (1);
    }
    else
    {
//        printf("ft_is_unique return 0\n");
        return (0);
    }
}

