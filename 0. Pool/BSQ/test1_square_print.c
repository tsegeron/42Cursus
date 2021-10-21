#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> /* open, read, write, lseek, close */
#include <stdlib.h> /* malloc */
#define BUF 4096

int **ft_square(char **strs, int dl, int dlina, char fr, char ob);
int **ft_square_max(int **tab, int y, int x);
int ft_min(int a, int b, int c);
int ft_find_max(int **tab, int y, int x);
int ft_find_max_ij(int **tab, int y, int x, int max);

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
    /*while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') || \
           (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
        i++;
    while ((str[i] == '-') || (str[i] == '+'))
    {
        if (str[i] == '-')
            m = -1 * m;
        i++;
    }*/
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
    close(fd);
/* ↑ checked 1 line > переписали 1 строку */
    
/* ↓ checking symbols in 1 line > str, l, dl < ft_strlen, ft_strdup, ft_atoi */
    char ob;
    char fr;
    char sq;
    
    l = ft_strlen(str);
    if (f(str[l - 2], str[l - 3], str[l - 4]) == 0)
        write (2, "map error\n", 10);
    dl = ft_atoi(ft_strdup(str, l));
    ob = str[l - 3];
    fr = str[l - 4];
    sq = str[l - 2];
    if (dl < 1)
        write (2, "map error\n", 10);
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
    close(fd);
/* ↑ checked the number of lines > посчитали количество строк */
    
/* ↓ checking the length of 1 map-line > strdlina, fd, av, c, dlina < */
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
    close(fd);
/* ↑ checked length of 1 map-line */
    
/* ↓ parcing lines > fd, strs, stroka, shst, dlst, dl, dlina, c, str, l < */
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        write (2, "map error\n", 10);
    char **strs;
    char *stroka;
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
/* ↓ comparing symbols from line #1 with lines > c, str, l < */
        if (c != str[l - 4] && c != str[l - 3] && c != '\n' &&  c != '\0')
            return (0);
/* ↑ compared symbols from line #1 with lines */
        if (c == '\n')
        {
            stroka[shst] = '\0';
            strs[dlst] = stroka;
            dlst++;
            shst = 0;
            stroka = (char *) malloc(sizeof(char) * dlina);
        }
    }
    dlst = 0;
    while (dlst != dl)
    {
        printf("%s", strs[dlst]);
        dlst++;
    }
    close(fd);
/* ↑ parced lines */
    
/* ↓ checking length of lines */
    while (dlst != dl)
    {
        if (ft_strlen(strs[dlst]) != dlina + 1)
        {
            write (1, "Pizdesh\n", 8);
            return (0);
        }
        dlst++;
    }
/* ↑ checked length of lines */
    printf ("%d,%d\n", dl, dlina);
    ft_square(strs, dl, dlina, fr, ob);
    return (0);
}

int **ft_square(char **strs, int dl, int dlina, char fr, char ob)
{
    int **tab;
    int *tabl;
    int i;
    int j;
    
    tab = (int **)malloc(sizeof(int *) * dl);
    tabl = (int *)malloc(sizeof(int) * dlina);
    if (!tab || !tabl)
        return ((void *)0);
    i = 0;
    while (i != dl)
    {
        j = 0;
        while (j != dlina)
        {
            if (strs[i][j] == fr)
                tabl[j] = 1;
            else if (strs[i][j] == ob)
                tabl[j] = 0;
            j++;
        }
        tab[i] = tabl;
        tabl = (int *)malloc(sizeof(int) * dlina);
        i++;
    }//
    i = 0;
    j = 0;
    while (i != dl)
    {
        while (j != dlina)
        {
            printf("%d", tab[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }//
    printf("\n");//
    ft_square_max(tab, dl, dlina);
    return (0);
}

int ft_min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

int **ft_square_max(int **tab, int y, int x)
{
    int i;
    int j;
    
    i = 1;
    while (i != y)
    {
        j = 1;
        while (j != x)
        {
            if (tab[i][j] != 0)
                tab[i][j] = ft_min(tab[i - 1][j], tab[i][j - 1], tab[i - 1][j - 1]) + 1;
            else
                tab[i][j] = 0;
            j++;
        }
        i++;
    }//
    i = 0;
    j = 0;
    while (i != y)
    {
        while (j != x)
        {
            printf("%d", tab[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }//
    printf("\n");
    ft_find_max(tab, y, x);
    return (0);
}

int ft_find_max(int **tab, int y, int x)
{
    int max;
    int i;
    int j;
    
    max = tab[0][0];
    i = 0;
    while (i != y)
    {
        j = 0;
        while (j != x)
        {
            if (tab[i][j] > max)
                max = tab[i][j];
            j++;
        }
        i++;
    }//
    printf("%d\n", max);
    ft_find_max_ij(tab, y, x, max);
    return (0);
}

int ft_find_max_ij(int **tab, int y, int x, int max)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (tab[i][j] != max)
    {
        while (i != y)
        {
            j = 0;
            while (j != x)
            {
                if (tab[i][j] == max)
                    break ;
                j++;
            }
            if (tab[i][j] == max)
            break ;
            i++;
        }
        if (tab[i][j] == max)
        break ;
    }
    printf("%d.%d", i+1, j+1);
    return (0);
}

void ft_print_max_square(char **strs, int max, int is, int js, char sq, int y, int x)
{
    int i;
    int j;
    
    i = 0;
    while (i != y)
    {
        j = 0;
        while (j != x)
        {
            if ((i >= is - max && j >= js - max) && (i <= is && j <= js))
                write (1, &sq, 1);
            else
                write (1, &strs[i][j] 1);
            j++;
        }
        i++
    }
}




/* ↓ loop for all arguments */
/*int param;

param = 1;
while (param != ac)
{
    
}*/
/* ↑ loop for all arguments */
