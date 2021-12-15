#include "../hdrs/push_swap.h"
/*
 *
 */
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

t_list	*gt_find_start(sts *s)
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


/* Method #1
 * расставляет статусы для переноса в стек В
 * в порядке возрастания индекса на 1
 * 0 - оставить в А
 * 1 - перенос в В
 */
void	ip_set_statuses(sts *s)
{
	int		tmp;
	t_list	*tmp1;

	find_index_0(s, &tmp, &tmp1); // находит элемент с 0 индексом

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
/* Method #2
 * расставляет статусы для переноса в стек В
 * в порядке возрастания индекса в принципе
 * (не обязательно на 1)
 * 0 - оставить в А
 * 1 - перенос в В
 *
 * статусы ставятся исходя из start-элемента.
 * start-элемент выбирается в зависимости от
 * количества элементов, которые останутся в
 * stack_a(наибольшее количество - наш случай)
 */
void	gt_set_statuses(sts *s)
{
	t_list	*start;
	int		i_end;
	int		i_tmp;

	start = gt_find_start(s);
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
	gt_set_statuses(s);
	do_magic(s);

}
