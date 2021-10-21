#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int ft_map_len(int fd);

char *ft_map_to_arr(char *map_dir)
{
    int len;
    int fd;
    char *map;
    int i;
    char c;

    i = 0;
    map = (void *)0;
    fd = open(map_dir, O_RDONLY);
    len = ft_map_len(fd);
    close(fd);
    if (len > 7)
    {
        map = (char *) malloc(len);
        fd = open(map_dir, O_RDONLY);
        while (i < len)
        {
            read(fd, &c, 1);
            map[i] = c;
            i++;
        }
    }
    return (map);
}