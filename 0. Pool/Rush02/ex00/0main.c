#include <unistd.h>
#include <fcntl.h> /* open, read, write, lseek, close */
#include <stdlib.h> /* malloc */

/* needed prototypes */

void ft_putstr(char *str);
long long ft_atoi(char *str);

/* ---------------------------------------------------------------- */


/* needed variables */

long long num; /* to check incoming integer fot the limits */
int fd; /* file descriptor for open */
int ret; /* for read */


/* ---------------------------------------------------------------- */


/* functions */
/* check number of arguments */
if (ac != 2 || ac != 3 )
    return (0);
if (ac == 2)
    num = ft_atoi(av[1]);
else
    num = ft_atoi(av[2]);
//if (num > 4294967295 || num < 0)
//    return (write (1, "Error\n", 6));

/* check dictionary if we have new one */
if (ac == 3)
    fd = open(av[1], O_RDONLY);
else
    fd = open("numbers.dict", O_RDONLY);
if (fd == -1)
{
    ft_putstr(2, "Dict Error\n");
    return (1);
}

/* check smth */
while (read(fd, av[1], 1))
{
    ret = 1 + read(fd, av[1], 1);
}
if (ret == 1)
    return (1);
if (ret == -1)
{
    ft_putstr(2, MSG_READ);
    return (1);
}

/* ---------------------------------------------------------------- */

/* subject *//*

ins integer -> 0 to 4294967295 | if not -> return (write (1, "Error\n", 6));


*//* -------------------------------------------------------------- */

/*
 while ((n = read (fd, buf, sizeof buf)) > 0)  // read 65k chars
     for (i = 0; i < n; i++)            //count newlines in buf
         if (buf[i] == '\n')
             nlines++;
 if (buf[i - 1] != '\n')       // account for non-POSIX line end
     nlines++;

 close (fd);
 */
