#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_list.h"

void ft_square_max(char **strs, int **tab, t_list *var);
int ft_min(int a, int b, int c);
void ft_find_max(char **strs, int **tab, t_list *var);
void ft_find_max_ij(char **strs, int **tab, t_list *var);
void ft_print_max_square(char **strs, t_list *var);

int ft_do_max_square(char **strs, t_list *var)
{
    int **tab;
    int *tabl;
    int i;
    int j;
    
    tab = (int **)malloc(sizeof(int *) * var->lines_count);
    tabl = (int *)malloc(sizeof(int) * var->lines_len);
    if (!tab || !tabl)
        return (0);
    i = 0;
    while (i != var->lines_count)
    {
        j = 0;
        while (j != var->lines_len)
        {
            if (strs[i][j] == var->fr)
                tabl[j] = 1;
            else if (strs[i][j] == var->ob)
                tabl[j] = 0;
            j++;
        }
        tab[i] = tabl;
        tabl = (int *)malloc(sizeof(int) * var->lines_len);
        i++;
    }
    ft_square_max(strs, tab, var);
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

void ft_square_max(char **strs, int **tab, t_list *var)
{
    int i;
    int j;
    
    i = 1;
    while (i != var->lines_count)
    {
        j = 1;
        while (j != var->lines_len)
        {
            if (tab[i][j] != 0)
                tab[i][j] = ft_min(tab[i - 1][j], tab[i][j - 1], tab[i - 1][j - 1]) + 1;
            else
                tab[i][j] = 0;
            j++;
        }
        i++;
    }
    ft_find_max(strs, tab, var);
}

void ft_find_max(char **strs, int **tab, t_list *var)
{
    int i;
    int j;
    
    var->max = tab[0][0];
    i = 0;
    while (i != var->lines_count)
    {
        j = 0;
        while (j != var->lines_len)
        {
            if (tab[i][j] > var->max)
                var->max = tab[i][j];
            j++;
        }
        i++;
    }
    //ft_find_max_ij(strs, tab, var);
    i=0;
    while (i != var->lines_count)
    {
        j = 0;
        while (j != var->lines_len)
        {
            printf("%d", tab[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    strs = NULL;
}

void ft_find_max_ij(char **strs, int **tab, t_list *var)
{
    var->is = 0;
    var->js = 0;
    while (tab[var->is][var->js] != var->max)
    {
        while (var->is != var->lines_count)
        {
            var->js = 0;
            while (var->js != var->lines_len)
            {
                if (tab[var->is][var->js] == var->max)
                    break ;
                var->js++;
            }
            if (tab[var->is][var->js] == var->max)
            break ;
            var->is++;
        }
        if (tab[var->is][var->js] == var->max)
        break ;
    }
    ft_print_max_square(strs, var);
}

void ft_print_max_square(char **strs, t_list *var)
{
    int i;
    int j;
    
    i = 0;
    while (i != var->lines_count)
    {
        j = 0;
        while (j != var->lines_len)
        {
            if ((i >= var->is - var->max && j >= var->js - var->max) && (i <= var->is && j <= var->js))
                write (1, &var->sq, 1);
            else
                write (1, &strs[i][j], 1);
            j++;
        }
        write (1, "\n", 1);
        i++;
    }
}
