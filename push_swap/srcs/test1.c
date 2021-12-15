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


//	pb(&s, 0);
//	printf("actions : %d\n", s.count_actions);
//	printf("shifts  : %d\n", s.count_true1);
//	printf("shifts  : %d\n", s.count_true2);

	printf("\nStuck a\n");
			while (s.a)
			{
				printf("%d-%d >> A:%d, S:%d, M:%d\n", s.a->i, s.a->num, s.a->stay_a, s.a->gt_status, s.a->actions_num_a);
//				printf("%d-%d >> %d\n", s.a->i, s.a->num, s.a->status2);
//				printf("%d ", s.a->num);
				s.a = s.a->next;
			}

				printf("\n\nStuck b\n");
			while (s.b)
			{
				printf("%d ", s.b->num);
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
