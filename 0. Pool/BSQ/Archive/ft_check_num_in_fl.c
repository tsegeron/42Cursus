#include <stdio.h>
int ft_modified_atoi(char *str, int stop);
int ft_strlen(char *str);

int ft_check_num_in_fl(char *str)
{
    int len;
    int num_in_fl;

    len = ft_strlen(str);
    num_in_fl = ft_modified_atoi(str, len - 3);
//    printf("ft_check_num_in_fl return %d\n", num_in_fl);
    return (num_in_fl);
}