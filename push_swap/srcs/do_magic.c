#include "../hdrs/push_swap.h"

void	do_magic(sts *s)
{
	int size_a;
//	t_list *tmp1;

	size_a = ft_lstsize(s->a);
//	tmp1 = s->a;

// algorithm to move from A to B
	while (size_a)
	{
		if (s->a->next && s->a->i > s->a->next->i)
		{
			sa(s, 0);
			gt_set_statuses(s, gt_find_start(s));
		}
		else if (s->a->gt_status)
			pb(s, 0);
		else
			ra(s, 0);
		size_a--;
	}

// algorithm to move from A to B
	while (s->b)
	{

	}



}


//}
/*
 * 1. найти наименьшее число
 * 2. обозначить статус переноса для последующих
 * по алгоритму возрастания индекса относительно предыдущего
 * числа, при этом смотря на число шагом наперед;
 * если оно меньше предыдущего, чей статус мы проверяем,
 * то статус предыдущего автоматически = 1 (перенос),
 * и так до конца #ДОРАБОТАТЬ
 * 3.
 *
 */