#include "ft_list.h"

int ft_strlen(char *str);
int ft_is_unique(char *str);
int ft_is_printable(char *str);
int ft_check_num_in_fl(char *str);
int ft_check_lines_in_map(char **map, char *first_line, int lines_count, int lines_len);

int ft_valid_map(char **map, char *first_line, t_list *var)
{
    if (ft_strlen(first_line) < 4)
        return (0);
    if (!(ft_is_unique(first_line)))
        return (0);
    if (!(ft_is_printable(first_line)))
        return (0);
    if (!(ft_check_num_in_fl(first_line)))
        return (0);
    if (!(ft_check_lines_in_map(map, first_line, var->lines_count, var->lines_len)))
        return (0);
    return (1);
}
