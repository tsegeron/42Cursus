#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s
{
	int			num_philos;
	int			num_eat;
	useconds_t	t2die;
	useconds_t	t2eat;
	useconds_t	t2sleep;
}	t_s;

int	ft_atoi(const char *str, int *check_zero);

#endif
