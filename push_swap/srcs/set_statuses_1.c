#include "../hdrs/push_swap.h"

static void	find_index_0(sts *s, int *tmp, t_list **tmp1)
{
	*tmp1 = s->a;
	while (s->a->i != 0)
		s->a = s->a->next;
	*tmp = s->a->i;
	s->a->status1 = 0;
	s->count_true1 = 0;
	s->a = s->a->next;
	if (!s->a)
		s->a = *tmp1;
}

void	set_statuses_in_ascending_index_order(sts *s)
{
	int		tmp_i;
//	int		tmp_next;
	t_list	*tmp1;

	find_index_0(s, &tmp_i, &tmp1);

	while (s->a->i != 0)
	{
		if (s->a->i > tmp_i)
		{
			s->a->status1 = 0;
			tmp_i = s->a->i;
		}
		else
		{
			s->a->status1 = 1;
			s->count_true1++;
		}
		s->a = s->a->next;
		if (!s->a)
			s->a = tmp1;
	}










	s->a = tmp1;
}
