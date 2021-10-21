#include <stdio.h>
int ft_strlen(char *str);
int ft_check_fl_symb(char *str, char *first_line, int lines_len);

int ft_check_lines_in_map(char **map, char *first_line, int lines_count, int lines_len)
{
    int i;

    i = 0;
    while (i < lines_count)
    {
        if (map[i][lines_len] != '\n')
        {
//            printf("\\n is not at the end of lines\n");
            return (0);
        }
        if (ft_strlen(map[i]) != lines_len + 1)
        {
//            printf("ft_strlen(map[%d]) != %d\n", i, lines_len);
//            printf("ft_strlen(map[%d]) = %d\n", i, ft_strlen(map[i]));
            return (0);
        }
        if (!(ft_check_fl_symb(map[i], first_line, lines_len)))
        {
//            printf("ft_check_fl_symb return 0\n");
            return (0);
        }
        i++;
    }
    if (i != lines_count)
    {
//        printf("\\n is not at the end of lines\n");
//        printf("i = %d\n", i);
//        printf("lines_count = %d\n", lines_count);
        return (0);
    }
    return (1);
}

