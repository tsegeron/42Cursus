/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:55:45 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/10 22:33:34 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/philo.h"

void	death_check_loop(t_s *s)
{
	unsigned long	cur_time;
	int				i;

	while (!s->die_status)
	{
		if (s->die_status)
			return ;
	}
}

int	destroy_mutexes(t_s *s)
{
	int	i;

	i = 0;
	while (i < s->philos_count)
		if (pthread_mutex_destroy(&s->philo[i++].fork))
			return (printf("Error: mutex: destroy\n"));
	if (pthread_mutex_destroy(&s->stdout_stat))
		return (printf("Error: mutex: destroy\n"));
	if (pthread_mutex_destroy(&s->death_stat))
		return (printf("Error: mutex: destroy\n"));
	return (0);
}

int main(int ac, char **av)
{
	t_s	s;

	if (parse_input(ac, &av, &s))
		return (-1);
//	printf("%lu %lu %lu %lu %lld", s.philos_count, s.t2die, s.t2eat, s.t2sleep, s.num_eat);
	if (init_philos_and_mutexes(&s))
		return (-1);
	if (gettimeofday(&s.start_time, NULL))
		return (printf("Error: gettime\n"));
	if (init_threads(&s))
		return (-1);
	death_check_loop(&s);
	if (destroy_mutexes(&s))
		return (-1);
	return (0);
}
