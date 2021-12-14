#include "../hdrs/push_swap.h"

static void	find_index_0(sts *s, int *tmp, t_list **tmp1)
{
	*tmp1 = s->a;
	while (s->a->i != 0)
		s->a = s->a->next;
	*tmp = s->a->i;
	s->a->status2 = 0;
	s->count_true2 = 0;
	s->a = s->a->next;
	if (!s->a)
		s->a = *tmp1;
}

void	set_statuses_plus_one_index_order(sts *s)
{
	int		tmp;
	t_list	*tmp1;

	find_index_0(s, &tmp, &tmp1);

	while (s->a->i != 0)
	{
		if (s->a->i == tmp + 1)
		{
			s->a->status2 = 0;
			tmp = s->a->i;
		}
		else
			s->a->status2 = 1;
		s->a = s->a->next;
		if (!s->a)
			s->a = tmp1;
	}













	s->a = tmp1;
}
