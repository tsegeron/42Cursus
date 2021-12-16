#include "../hdrs/push_swap.h"

int	main(int ac, char *av[])
{
	sts	s;

	if (ac < 2)
		return (0);
	s.a = NULL;
	s.b = NULL;
	s.sorted = NULL;
	s.count_actions = 0;
	fill_stack_a(&s, ++av);
	fill_stack_sorted(&s, ac);
	put_indexes(&s);
	do_stuff(&s);

//	printf("%d", s.count_true);


//	ra(&s, 0);
//	pb(&s, 0);
//	pb(&s, 0);
//	sa(&s, 0);
//	ra(&s, 0);
//	ra(&s, 0);
//	rb(&s, 0);
//	rra(&s, 0);
//	printf("actions : %d\n", s.count_actions);
//	printf("shifts  : %d\n", s.count_true1);
//	printf("shifts  : %d\n", s.count_true2);

	printf("\nStuck a\n");
			while (s.a)
			{
				printf("%d-%d >> Ra:%d\n", s.a->i, s.a->num, s.a->actions_num_a);
//				printf("%d ", s.a->i);
//				printf("%d-%d >> ", s.a->i, s.a->num);
				s.a = s.a->next;
			}

				printf("\n\nStuck b\n");
			while (s.b)
			{
//				printf("%d-%d >> S:%d, M:%d\n", s.b->i, s.b->num, s.b->gt_status, s.b->actions_num_b);
				printf("%d-%d >> Pa:%d\n", s.b->i, s.b->num, s.b->actions_to_pa);
//				printf("%d ", s.b->i);
//				printf("%d-%d  ", s.b->i, s.b->num);
				s.b = s.b->next;
			}
//
//				printf("\n\nSorted\n");
//			while (s.sorted)
//			{
//				printf("%d ", s.sorted->num);
//				s.sorted = s.sorted->next;
//			}

	return (0);
}
