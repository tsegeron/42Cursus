#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i;

    i = 0;
    while (i != n && s1[i] == s2[i] && s1[i] != '\0')
    {
        i++;
    }
    return (s1[i] - s2[i]);
}

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main(void)
{
    char s1[] = "ololol";
    char s2[] = "ololol12";
    unsigned int n;
    
    n = 8;
    printf ("%d\n", strncmp (s1, s2, n));
    printf ("%d", ft_strncmp (s1, s2, n));
    return (0);
}
