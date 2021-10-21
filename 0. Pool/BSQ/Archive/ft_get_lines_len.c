#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 1

int ft_get_lines_len(char *map_dir)
{
    char buf[BUF_SIZE];
    int  ret;
    int  len;
    int  fd;

    len = 0;
    fd = open(map_dir, O_RDONLY);
    while ((ret = (int)read(fd, &buf, BUF_SIZE)))
    {
         if (buf[0] == '\n')
             break;
    }
    while ((ret = (int)read(fd, &buf, BUF_SIZE)))
    {
        if (buf[0] == '\n')
            break;
        len++;
    }
    close(fd);
//    printf("ft_get_lines_len return %d\n", len);
    return (len);
}
