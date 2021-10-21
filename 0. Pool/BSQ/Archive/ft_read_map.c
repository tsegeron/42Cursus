#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

int ft_num_from_valid_fline(char *fline);
char *ft_fline_to_arr(char *, t_list *);
int ft_get_lines_len(char *map_dir);
char **ft_file_to_arr(char *map_dir, char **map, t_list *var);
int ft_valid_map(char **map, char *first_line, t_list *var);

char **ft_read_map(char *map_dir, t_list *var)
{
    char **map;
    char *f_line;

    var->lines_count = 0;
    f_line = ft_fline_to_arr(map_dir, var);
    var->sq = f_line[var->len - 1];
    var->ob = f_line[var->len - 2];
    var->fr = f_line[var->len - 3];
    printf("%c,%c,%c", var->sq,var->ob,var->fr);
    var->lines_len = ft_get_lines_len(map_dir);
    if (f_line && (var->lines_count = ft_num_from_valid_fline(f_line)))
        map = (char **) malloc((var->lines_count + 1) * sizeof(char *));
    else
        return ((void *) 0);
    map = ft_file_to_arr(map_dir, map, var);
    if (ft_valid_map(map, f_line, var))
    {
        return (map);
    }
    else
    {
        printf("map is invalid\n");
        return ((void *)0);
    }
}
