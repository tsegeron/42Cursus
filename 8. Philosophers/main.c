#include "hdrs/philo.h"

int	parse_input(int *ac, char ***av, t_s *s)
{
	int	i;
	int	status1;
	int	status2;
	int	status3;
	int	status4;
	int	status5;


	if (*ac < 5)
		return (printf("Error: lack of arguments\n"));
	else if (*ac > 6)
		return (printf("Error: arguments: more than needed\n"));
	i = 0;
	s->num_eat = -1;
	s->num_philos = ft_atoi((*av)[++i], &status1);
	s->t2die = ft_atoi((*av)[++i], &status2);
	s->t2eat = ft_atoi((*av)[++i], &status3);
	s->t2sleep = ft_atoi((*av)[++i], &status4);
	if (*ac == 6)
		s->num_eat = ft_atoi((*av)[++i], &status5);
	if (s->num_philos < )
	return (0);
}

int main(int ac, char **av)
{
	t_s	s;

	if (parse_input(&ac, &av, &s))
		return (1);




	return (0);
}
