#include "../hdrs/push_swap.h"

void	gt_set_statuses(sts *s, t_list *start)
{
	int	i_end;
	int	i_tmp;

	i_end = start->i;
	i_tmp = start->i;
	start->gt_status = 0;
	start = start->next;
	if (!start)
		start = s->a;
	while (start->i != i_end)
	{
		if (start->i > i_tmp)
		{
			i_tmp = start->i;
			start->gt_status = 0;
		}
		else
			start->gt_status = 1;
		start = start->next;
		if (!start)
			start = s->a;
	}
}

void	do_stuff(sts *s)
{
	t_list *ptr_start;

	ptr_start = gt_find_start(s);
	gt_set_statuses(s, ptr_start);
//	do_magic(s);

}
