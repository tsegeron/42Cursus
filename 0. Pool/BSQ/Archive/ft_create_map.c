#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
//#define BUF_SIZE 1
#include <stdio.h>

char **ft_read_map(char *map_dir);

char **ft_create_map(void)
{
//    char buf[BUF_SIZE + 1];
    char c;
    int fd;
    char **map;
    int ret;

    ret = 1;
    fd = open("./manual_map.txt", O_RDWR | O_TRUNC | O_CREAT, 0666);
    while (ret)
    {
        ret = read(0, &c, 2);
        write(1, &c, 1);
        write(fd, &c, 1);
    }
    close(fd);
    map = ft_read_map("./manual_map.txt");
    return (map);
}

