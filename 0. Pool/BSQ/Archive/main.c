#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_list.h"

char **ft_read_map(char *map_dir, t_list *var);
char **ft_create_map(void);
void ft_do_max_square(char **strs, t_list *var);

int main(int argc, char **argv)
{
    t_list *var;
    char **map;
    int  i;
    int  j;

    var = malloc(sizeof(t_list));
    j = 1;
    if (argc == 1)
    {
        map = ft_create_map();
        if (map)
            printf("Manual map is created");
    }
    while (j < argc)
    {
        map = ft_read_map(argv[j], var);
        i = 0;
        if (map)
        {
            while (map[i])
            {
                printf("%s", map[i]);
                i++;
            }
        }
        j++;
    }
    write (1, "\n", 1);
    ft_do_max_square(map, var);
    return (0);
}
