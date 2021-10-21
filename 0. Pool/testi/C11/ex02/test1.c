#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int    check (char *a)
{
    (void) a;
    return 0;
}

int ft_any(char **tab, int(*f)(char*))
{
    int i;
    
    i = 0;
    while (tab[i])
    {
        if (f(tab[i]) != 0)
            return (1);
        i++;
    }
    return (0);
}

int ft_any(char **tab, int(*f)(char*));

int main (void)
{
    char *tab[3];
    int(*f)(char*);
    
    //int i = 0;
    tab[0] = "sdf";
    tab[1] = "saf";
    tab[2] = "asf";
    //char *result;
    
    f = &check;
    /*result = malloc(sizeof(int) * length);
    if (result == NULL)
        return (0);
    result = ft_any(tab, f);*/
    //while (length != i)
    //{
        printf ("%d\n", ft_any(tab, f));
       // i++;
    //}
    //free(result);
    return (0);
}

