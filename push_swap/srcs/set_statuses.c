#include "../hdrs/push_swap.h"

void	set_statuses(sts *s)
{
	int		tmp;
	t_list	*tmp1;

	tmp1 = s->a;
	while (s->a->i != 0)
		s->a = s->a->next;
	tmp = s->a->i;
	s->a->status1 = 0;
	s->count_true1 = 1;
	s->a = s->a->next;
	if (!s->a)
		s->a = tmp1;
	
	while (s->a->i != 0)
	{
		if (s->a->i > tmp)
		{
			if (s->a->next && s->a->i > s->a->next->i)
			{
				s->a->status1 = 1;
				if (s->a->next->i > tmp)
				{
					tmp = s->a->next->i;
					s->a->next->status1 = 0;
					s->count_true1++;
					s->a = s->a->next->next;
					continue ;
				}
			}
			else if (!s->a->next && s->a->i > tmp1->i)
			{
				s->a->status1 = 1;
//				if (s->a->i == s->len_a - 1 && tmp1->i == 0)
//					s->a->status1 = 0;
				if (tmp1->i > tmp)
				{
					tmp = tmp1->i;
					tmp1->status1 = 0;
					s->count_true1++;
					s->a = tmp1->next;
					continue ;
				}
			}
			else
			{
				s->a->status1 = 0;
				tmp = s->a->i;
				s->count_true1++;
			}
		}
		else
			s->a->status1 = 1;
		s->a = s->a->next;
		if (!s->a)
			s->a = tmp1;
	}
	s->a = tmp1;
}
