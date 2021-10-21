#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_list.h"

char **ft_file_to_arr(char *map_dir, char **map, t_list *var)
{
    char c;
    int ret;
    int fd;
    int i;

    i = 0;
    map = (char **)malloc((var->lines_count + 1) * sizeof(char *));
    fd = open(map_dir, O_RDONLY);
    while ((ret = (int)read(fd, &c, 1)))
    {
        if (c == '\n')
            break;
    }
    while (i < var->lines_count)
    {
        map[i] = (char *)malloc((var->lines_len + 2) * sizeof(char));
        ret = (int)read(fd, map[i], var->lines_len + 1);
        map[i][var->lines_len + 1] = '\0';
        i++;
    }
    map[i] = (void *)0;
    close(fd);
    return (map);
}
