#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

int ft_fline_len(int fd);

char *ft_fline_to_arr(char *map_dir, t_list *var)
{
    int fd;
    char *fline;
    int i;
    char c;

    i = 0;
    fline = (void *)0;
    fd = open(map_dir, O_RDONLY);
    var->len = ft_fline_len(fd);
    close(fd);
    if (var->len > 3)
    {
        fline = (char *) malloc(var->len);
        fd = open(map_dir, O_RDONLY);
        while (i < var->len - 1)
        {
            read(fd, &c, 1);
            fline[i] = c;
            i++;
        }
        fline[i] = '\0';
        close(fd);
    }
//    printf("ft_fline_to_arr return %s\n", fline);
    return (fline);
}

