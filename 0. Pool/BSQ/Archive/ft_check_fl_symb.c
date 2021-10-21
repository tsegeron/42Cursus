#include <stdio.h>

int ft_strlen(char *str);

int ft_check_fl_symb(char *str, char *first_line, int lines_len)
{
    int i;
    int flag_of_empty_symb;
    int fl_len;

    i = 0;
    flag_of_empty_symb = 0;
    fl_len = ft_strlen(first_line);
//    printf("first_line[fl_len - 3] is %c\n", first_line[fl_len - 3]);
//    printf("first_line[fl_len - 2] is %c\n", first_line[fl_len - 2]);
//    printf("first_line[fl_len - 1] is %c\n", first_line[fl_len - 1]);
//    printf("first_line is %s\n", first_line);
    while (i < lines_len)
    {
        if (!(str[i] == first_line[fl_len - 3] || str[i] == first_line[fl_len - 2] || str[i] == first_line[fl_len - 1]))
        {
//            printf("invalid symbols\n");
//            printf("invalid symbol is %c\n", str[i]);
            return (0);
        }
        if (str[i] == first_line[fl_len - 3])
            flag_of_empty_symb = 1;
        i++;
    }
//    printf("flag_of_empty_symb = %d\n", flag_of_empty_symb);
    if (i != lines_len)
        return (0);
    return (1 * flag_of_empty_symb);
}

