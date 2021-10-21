#include "ft_list.h"

int ft_list_size(t_list *begin_list);
{
    int     num;

    if (begin_list == NULL)
        return (0);
    num = 1;
    while (begin_list->next != NULL)
    {
        begin_list = begin_list->next;
        num++;
    }
    return (num);
}
