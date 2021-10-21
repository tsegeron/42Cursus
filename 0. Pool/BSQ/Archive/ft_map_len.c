#include <unistd.h>
#define BUF_SIZE 20

int ft_map_len(int fd)
{
    char buf[BUF_SIZE];
    int ret;
    int len;

    len = 0;

    while ((ret = (int)read(fd, &buf, BUF_SIZE)))
    {
        len += ret;
    }
    return (len);
}