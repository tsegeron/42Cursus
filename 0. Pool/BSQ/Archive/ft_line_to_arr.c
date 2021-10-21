#include <unistd.h>

void ft_line_to_arr(int fd, char *line)
{
    int ret;
    int i;
    char c;

    i = 0;
    line = (void *)0;
    while ((ret = read(fd, &c, 1)))
    {
        if (c == '\n')
            break;
        else
        {
            line[i] = c;
            i++;
        }
    }
    line[i] = '\0';
}