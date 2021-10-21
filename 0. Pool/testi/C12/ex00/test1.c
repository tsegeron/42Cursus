#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

t_list *ft_create_elem(void *data)
{
    t_list *elem1;
    
    elem1 = malloc(sizeof(t_list));
    if (elem1 == NULL)
        return (0);
    elem1->data = data;
    elem1->next = NULL;
    return (elem1);
}

int main(void)
{
    int a = 12;
    
    printf ("%d\n", *(int *)ft_create_elem(&a)->data);
}
