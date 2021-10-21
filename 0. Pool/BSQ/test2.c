#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> /* open, read, write, lseek, close */
#include <stdlib.h> /* malloc */
#include "ft_list.h"

/* ↓ all prototypes */

int ft_strlen(char *str);
char *ft_strdup(char *src, int l);
int ft_atoi(char *str);
int ft_symcmp(char s1, char s2, char s3);
int ft_1_line_symbols_check(char str[BUF], t_list *var);
char ft_first_line_check(char *av[1], t_list *var);
int ft_number_of_lines_check(char *av[1]);
int ft_length_of_1_map_line(char *av[1]);
int ft_real_parcing_lines(fd, c, t_list *var);
int ft_parcing_lines(char *av[1], t_list *var);
int ft_length_of_lines_check(t_list *var);
int pseudo_main(int ac, char **av, t_list *var);

/* ↑ all prototypes */
/* --------------------------------------------------------- */
/* ↓ all functions */

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
    while ((str[i] < 58) && (str[i] > 47))
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    while ((str[i] == '-') || (str[i] == '+'))
    {
        if (str[i] == '-')
            m = -1 * m;
        i++;
    }
    if (m == -1)
        return (0);
    return (res);
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

int ft_1_line_symbols_check(char str[BUF], t_list *var)
{
    int dl;
    
    var->l = ft_strlen(str);
    if (ft_symcmp(str[var->l - 2], str[var->l - 3], str[var->l - 4]) == 0)
    {
        write (2, "map error\n", 10);
        return (1);
    }
    dl = ft_atoi(ft_strdup(str, var->l));
    if (dl < 1)
    {
        write (2, "map error\n", 10);
        return (1);
    }
    return (0);
}

char ft_first_line_check(char *av[1], t_list *var)
{
    int fd;
    char c;
    char str[BUF];
    char i;
    
    i = 0;
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (write (2, "couldn't open\n", 14));
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
    close(fd);
    if (ft_1_line_symbols_check(str, var) == 0)
        return (str);
    return (NULL);
}

int ft_number_of_lines_check(char *av[1])
{
    int fd;
    char c;
    int strok;
    
    strok = 0;
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        write (2, "couldn't open\n", 14);
    while (read(fd, &c, 1))
        if (c == '\n')
            strok++; /* количество строк */
    close(fd);
    if (dl != strok - 1)
    {
        write (2, "map error\n", 10); /* проверка количества строк */
        return (0);
    }
    return (strok);
}

int ft_length_of_1_map_line(char *av[1])
{
    char c;
    int dlina;
    int fd;
    
    dlina = 0;
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        write (2, "couldn't open\n", 14);
        return (0);
    }
    while (read(fd, &c, 1))
        if (c == '\n')
            break ;
    while (read(fd, &c, 1))
    {
        if (c == '\n')
            break ;
        dlina++;
    }
    close(fd);
    return (dlina);
}
int ft_real_parcing_lines(fd, c, t_list *var)
{
    while (read(fd, &c, 1))
        if (c == '\n')
            break ;
    while (read(fd, &c, 1))
    {
        var->stroka[var->shst] = c;
        var->shst++;
        if (c != var->str[var->l - 4] && c != var->str[var->l - 3]
            && c != '\n' &&  c != '\0')
            return (0);
        if (c == '\n')
        {
            var->stroka[var->shst] = '\0';
            var->strs[var->dlst] = var->stroka;
            var->dlst++;
            var->shst = 0;
            var->stroka = (char *) malloc(sizeof(char) * var->dlina);
        }
    }
}

int ft_parcing_lines(char *av[1], t_list *var)
{
    int fd;
    char c;
    
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        write (2, "couldn't open\n", 14);
        return (0);
    }
    var->shst = 0;
    var->dlst = 0;
    var->strs = (char **) malloc(sizeof(char*) * var->dl);
    var->stroka = (char *) malloc(sizeof(char) * var->dlina);
    if (var->strs == NULL || var->stroka == NULL)
    {
        write (2, "Malloc doesn't want to give memory!!\n", 37);
        return (0);
    }
    ft_real_parcing_lines(fd, c, var);
    if (ft_real_parcing_lines(fd, c, var) == 0)
        return (0);
    close(fd);
}

int ft_length_of_lines_check(t_list *var)
{
    while (var->dlst != var->dl)
    {
        if (ft_strlen(var->strs[var->dlst]) != var->dlina + 1)
        {
            write (1, "map error\n", 10);
            return (0);
        }
        var->dlst++;
    }
    return (1);
}

int pseudo_main(int ac, char **av, t_list *var)
{
    char *str;
    
    str = ft_first_line_check(&av[1], t_list *var);
    if (str == NULL)
        return (0);
    var->dl = ft_atoi(ft_strdup(var->str, var->l));
    var->ob = var->str[var->l - 3];
    var->fr = var->str[var->l - 4];
    var->sq = var->str[var->l - 2];
    var->strok = ft_number_of_lines_check(&av[1]);
    if (var->strok == 0)
        return (0);
    var->dlina = ft_length_of_1_map_line(&av[1]);
    if (var->dlina == 0)
        return (0);
    ft_parcing_lines(&av[1], var);
    ft_length_of_lines_check(var);
}

int main(int ac, char **av)
{
    t_list *var;
    
    var = malloc(sizeof(t_list))
    if (!var)
        return (0);
    pseudo_main(ac, av, var);
}

/* ↑ all functions */
