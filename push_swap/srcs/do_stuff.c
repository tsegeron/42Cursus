#include "../hdrs/push_swap.h"

static void	find_index_0(sts *s, int *tmp, t_list **tmp1)
{
	*tmp1 = s->a;
	while (s->a->i != 0)
		s->a = s->a->next;
	*tmp = s->a->i;
	s->a->ip_status = 0;
	s->count_true2 = 0;
	s->a = s->a->next;
	if (!s->a)
		s->a = *tmp1;
}

void	ip_set_statuses(sts *s)
{
	int		tmp;
	t_list	*tmp1;

	find_index_0(s, &tmp, &tmp1);

	while (s->a->i != 0)
	{
		if (s->a->i == tmp + 1)
		{
			s->a->ip_status = 0;
			tmp = s->a->i;
		}
		else
			s->a->ip_status = 1;
		s->a = s->a->next;
		if (!s->a)
			s->a = tmp1;
	}
	s->a = tmp1;
}

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
//	t_list *ptr_start;

//	ptr_start = gt_find_start(s);
	gt_set_statuses(s, gt_find_start(s));
	do_magic(s);

}
