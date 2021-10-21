#include <stdio.h>
#include <stdlib.h>

int    *ft_range(int min, int max)
{
    int    i;
    int    *p;

    i = 0;
    if (min >= max)
        return (0);
    p = (int *) malloc((max - min - 1) * sizeof(int));
    if (NULL == p)
        return (0);
    while (i != max - min)
    {
        p[i] = min + i;
        i++;
    }
    return (p);
}

int *ft_range(int min, int max);

int main(void)
{
    int *chisla;
    int i;
    int min;
    int max;
    
    i = 0;
    min = 4;
    max = 1;
    //char src[] = "horosho";
    //ft_strdup (src);
    chisla = ft_range(min, max);
    while (i != max - min)
    {
        printf ("%d ", chisla[i]);
        i++;
    }
}

//#include <string.h> для встроенной strcpy


