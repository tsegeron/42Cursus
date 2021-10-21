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

void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *elem2;

    elem2 = ft_create_elem(data);
    elem2->next = (*begin_list);
    begin_list = elem2;
}

int main(void)
{
    int a = 12;
    int b = 24;
    t_list *structura;
    
    structura = ft_create_elem(void *data)
    printf ("%d\n", *(int *)ft_create_elem(&a)->data);
}
