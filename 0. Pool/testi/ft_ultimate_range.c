#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int i;
    int *p;
    
    i = 0;
    if (min >= max)
    {
        *range = 0;
        return (0);
    }
    p = (int*) malloc((max - min) * sizeof(int));
    if (NULL == p)
    {
        *range = 0;
        return (-1);
    }
    *range = p;
    while (i != max - min)
    {
        p[i] = min + i;
        i++;
    }
    return (max - min);
}

int ft_ultimate_range(int **range, int min, int max);

int main(void)
{
    int *range;
    //int *chisla;
    //int i = 0;
    int min = 0;
    int max = 2147483647;
    
    //char src[] = "horosho";
    //ft_strdup (src);
    //ft_ultimate_range(range, min, max);
    //while (i != max - min)
    //{
        printf ("%d", ft_ultimate_range(&range, min, max));
    //}
}

//#include <string.h> для встроенной strcpy
//2147483647


