#include "../hdrs/push_swap.h"

static void	find_index(sts *s, int tmp_i, t_list **tmp)
{
	*tmp = s->a;
	while ((*tmp)->i != tmp_i)
		(*tmp) = (*tmp)->next;
	if (*tmp_i == 0)
	{
//	*tmp_i = s->a->i;
	s->a->status1 = 0;
	s->count_true1 = 0;
	s->a->sublen = 1;
	}
//	s->a = s->a->next;
//	if (!s->a)
//		s->a = *tmp1;
}

void	set_statuses_in_ascending_index_order(sts *s) {
	int tmp_i;        // текущий индекс, с которым сравниваем другие
	int tmp_next;    // следующий индекс, с которого ищем субпоследовательность
	int tmp_num;
	t_list *tmp1;        // начало списка c 0 элемента
	t_list *tmp2;        // начало с tmp_i элемента списка
//	t_list	*tmp3;		// начало с tmp_i элемента списка

//	tmp1 = s->a;
//	tmp2 = s->a;
//	tmp_i = 0;
	find_index(s, 0, &tmp1);
	while (--s->len_a)
	{
		find_index(s, 1, &tmp2);
		while (tmp2->i != 0)
		{
			if (tmp2->i >)
				tmp2 = tmp2->next;
			if (!tmp2)
				tmp2 = s->a;
		}
	}















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
