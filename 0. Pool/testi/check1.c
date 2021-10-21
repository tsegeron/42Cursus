#include <stdio.h>
#include <string.h>

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int    count;

    count = 0;
    if (size == 0)
        size = 1;
    while (*dest != '\0')
    {
        dest++;
        count++;
    }
    while (*src != '\0')
    {
        if (count < size - 1)
        {
            *dest = *src;
            dest++;
        }
        src++;
        count++;
    }
    *dest = '\0';
    return (count);
}

int main ()
{
    char i[20] = "1234567";
    char j[] = " 890";
    
    printf("%u\n", ft_strlcat(i,j,20));
    //printf("%ul\n", strlcat(i,j,20));
}
