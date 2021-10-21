#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 1

int ft_fline_len(int fd)
{
    char buf[BUF_SIZE];
    int  ret;
    int  len;

    len = 0;

    while ((ret = (int)read(fd, &buf, BUF_SIZE)))
    {
        if (buf[0] == '\n')
            break;
        len++;
    }
//    printf("ft_fline_len return %d\n", len);
    return (len + 1);
}
