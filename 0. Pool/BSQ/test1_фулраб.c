#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> /* open, read, write, lseek, close */
#include <stdlib.h> /* malloc */
#define BUF 4096

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char *ft_strdup(char *src, int l)
{
    int i;
    char *p;
    
    i = 0;
    p = (char*) malloc(l * sizeof(char) - 4);
    if (NULL == p)
        return (NULL);
    while (i != l - 4)
    {
        p[i] = src[i];
        i++;
    }
    p[i] = '\0';
    return (p);
}

int    ft_atoi(char *str)
{
    int    res;
    int    m;
    int    i;

    res = 0;
    m = 1;
    i = 0;
    while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') || \
           (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
        i++;
    while ((str[i] == '-') || (str[i] == '+'))
    {
        if (str[i] == '-')
            m = -1 * m;
        i++;
    }
    while ((str[i] < 58) && (str[i] > 47))
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return (res * m);
}

int ft_symcmp(char s1, char s2, char s3)
{
    if ((s1 > '~' || s1 < 32) || (s2 > '~' || s2 < 32) || (s3 > '~' || s3 < 32))
        return (0); /* check for emptyness */
    if (s1 == s2 || s1 == s3 || s2 == s3)
        return (0);
    else
        return (1);
}

//ft_strlen;
//ft_strdup;
//ft_atoi;
//ft_symcmp;

int main(int ac, char **av)
{
    int fd; // file descriptor
    char str[BUF]; // 1st line
    int i; // for checking 1st line
    int l; // line lenght
    int (*f)(char, char, char); // for comparing symbols in the 1st line
    int dl; // number of lines excluding the 1st line
    char c; // symbol for reading by 1 bite
    int strok = 0; // for checking # of lines
    
    f = &ft_symcmp;
    ac = ac * 2;
    i = 0;
/* ↓ checking 1 line > fd, c, i, str < */
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        write (2, "map error\n", 10);
        return (0);
    }
    while (read(fd, &c, 1))
    {
        str[i] = c;
        if (str[i] == '\n')
        {
            str[i+1] = '\0';
            break ;
        }
        i++;
    }
    //printf("1 string: %s", str); /* check */
    close(fd);
/* ↑ checked 1 line */
    
/* ↓ checking symbols in 1 line > str, l, dl < ft_strlen, ft_strdup, ft_atoi */
    l = ft_strlen(str);
    if (f(str[l - 2], str[l - 3], str[l - 4]) == 0)
        write (2, "map error\n", 10);
    dl = ft_atoi(ft_strdup(str, l));
    if (dl < 1)
        write (2, "map error\n", 10);
    //printf ("dl: %d\n", dl); /* check */
/* ↑ checked symbols in 1 line */
    
/* str[l - 2] = x, str[l - 3] = o, str[l - 4] = . */
    
/* ↓ checking the number of lines > fd, av, c < */
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        write (2, "map error\n", 10);
    while (read(fd, &c, 1))
        if (c == '\n')
            strok++; /* количество строк */
    if (dl != strok - 1)
        write (2, "map error\n", 10); /* проверка количества строк */
    //printf("strok: %d\n", strok); /* check */
    close(fd);
/* ↑ checked the number of lines */
    
/* ↓ checking the length of 1 line > strdlina, fd, av, c, dlina < */
    char strdlina[BUF];
    int dlina = 0;
    
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        write (2, "map error\n", 10);
    while (read(fd, &c, 1))
        if (c == '\n')
            break ;
    while (read(fd, &c, 1))
    {
        strdlina[dlina] = c;
        if (c == '\n')
            break ;
        dlina++;
    }
    //printf("strdlina: %sdlina: %d\n", strdlina, dlina); // check
    close(fd);
/* ↑ checked length of 1 line */
    
    //printf("%c%c\n", str[l - 4], str[l - 3]);
    
/* ↓ parcing lines */
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        write (2, "map error\n", 10);
    char **strs; // char strs[dl + 1][BUF]; // 10, 23
    char *stroka;
    //char strs[dl + 1][BUF];
    int shst = 0;
    int dlst = 0;
    
    strs = (char **) malloc(sizeof(char*) * dl);
    stroka = (char *) malloc(sizeof(char) * dlina);
    if (strs == NULL || stroka == NULL) // check Malloc
    {
        write (2, "Malloc doesn't want to give memory!!\n", 37);
        return (0);
    }
    while (read(fd, &c, 1))
        if (c == '\n')
            break ;
    while (read(fd, &c, 1))
    {
        stroka[shst] = c;
        shst++;
/* ↓ checking symbols from line #1 > c, str, l < */
        if (c != str[l - 4] && c != str[l - 3] && c != '\n' &&  c != '\0')
            return (0);
/* ↑ checked symbols from line #1 */
        if (c == '\n')
        {
            stroka[shst] = '\0';
            strs[dlst] = stroka;
            dlst++;
            shst = 0;
            stroka = (char *) malloc(sizeof(char) * dlina);
        }
    }
    // check >
    dlst = 0;
    /*while (dlst != dl)
    {
        printf("%s", strs[dlst]);
        dlst++;
    }*/
    // check <
    close(fd);
/* ↑ parced lines */
    
/* ↓ checking length of lines */
    //printf("%d,%d,%d\n", dl, dlina, ft_strlen(*strs));
    //printf("%s", *strs);
    while (dlst != dl)
    {
        if (ft_strlen(strs[dlst]) != dlina + 1)
        {
            write (1, "Pizdesh\n", 8);
            //printf("%s", strs[dlst]);
            return (0);
        }
        dlst++;
    }
/* ↑ checked length of lines */
}

/* ↓ loop for all arguments */
/*int param;

param = 1;
while (param != ac)
{
    
}*/
/* ↑ loop for all arguments */
