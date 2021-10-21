#include <stdio.h>
int ft_strlen(char *str);
int ft_is_unique(char *str);
int ft_is_printable(char *str);
int ft_check_num_in_fl(char *str);

int ft_num_from_valid_fline(char *fline)
{
    int lines_count;

    lines_count = 0;
    if (ft_strlen(fline) < 4)
        return (0);
    if (!(ft_is_unique(fline)))
        return (0);
    if (!(ft_is_printable(fline)))
        return (0);
    if (!(lines_count = ft_check_num_in_fl(fline)))
        return (0);
//    printf("ft_num_from_valid_fline return %d\n", lines_count);
    return (lines_count);
}
