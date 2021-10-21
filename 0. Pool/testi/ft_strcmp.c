#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2)
{
    unsigned int i;

    i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int ft_strcmp(char *s1, char *s2);

int main(void)
{
    char s1[] = "023lolol";
    char s2[] = "523ololo";
    
    printf ("%d\n", strcmp (s1, s2));
    printf ("%d", ft_strcmp (s1, s2));
    return (0);
}
// если 1 строка идет первее то -1
