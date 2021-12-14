#include "../hdrs/push_swap.h"

static int	count_stay_a(sts *s, t_list *tmp1)
{
	int		end;
	int		max;
	int		count;
	t_list	*tmp;

	tmp = s->a;
	end = s->a->i;
	max = s->a->i;
	count = 1;
	s->a = s->a->next;
	if (!s->a)
		s->a = tmp1;
	while (s->a->i != end)
	{
		if (s->a->i > max)
		{
			max = s->a->i;
			count++;
		}
		s->a = s->a->next;
		if (!s->a)
			s->a = tmp1;
	}
	s->a = tmp;
	return (count);
}

t_list *gt_find_start(sts *s)
{
	int		max;
	t_list	*ptr_max;
	t_list	*tmp1;

	tmp1 = s->a;
	max = 0;
	while (s->a)
	{
		s->a->stay_a = count_stay_a(s, tmp1);
		if (s->a->stay_a > max)
		{
			max = s->a->stay_a;
			ptr_max = s->a;
		}
		s->a = s->a->next;
	}
	s->a = tmp1;
	return (ptr_max);
}
