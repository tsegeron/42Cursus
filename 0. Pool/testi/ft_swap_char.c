#include <unistd.h>

void    ft_swap(char **a, char **b)
{
    char    *c;

    c = *a;
    *a = *b;
    *b = c;
}

/*
 int    main(int a, char **b)
 {
     int m;
     int n;
     
     m = 1;
     n = 2;
     while (m != a)
     {
         while (n != a && ft_strcmp(b[m], b[n]) > 0)
         {
             ft_swap(&b[m], &b[n]);
             n++;
         }
         m++;
         n = m + 1;
     }
     m = 1;
     while (m != a)
     {
         ft_putstr(b[m]);
         write (1, "\n", 1);
         m++;
     }
     return (0);
 }
 */
