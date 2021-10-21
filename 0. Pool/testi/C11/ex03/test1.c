#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int    check (char *a)
{
    (void) a;
    return 1;
}

int ft_count_if(char **tab, int length, int(*f)(char*))
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (length != i)
    {
        if (f(tab[i]) != 0)
            j++;
        i++;
    }
    return (j);
}

int ft_count_if(char **tab, int length, int(*f)(char*));

int main (void)
{
    char *tab[3];
    int length = 3;
    int(*f)(char*);
    
    //int i = 0;
    tab[0] = "123";
    tab[1] = "456";
    tab[2] = "789";
    //char *result;
    
    f = &check;
    /*result = malloc(sizeof(int) * length);
    if (result == NULL)
        return (0);
    result = ft_any(tab, f);*/
    //while (length != i)
    //{
        printf ("%d\n", ft_count_if(tab, length, f));
       // i++;
    //}
    //free(result);
    return (0);
}

