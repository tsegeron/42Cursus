/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:55:45 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/08 21:54:45 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/philo.h"

void	*philo_routine(void *s)
{
	unsigned long	i;
	unsigned long	j;
	t_s				*tmp;

	tmp = (t_s *)s;
	i = tmp->i;
	if (i == 0)
		j = tmp->philos_count - 1;
	else
		j = i - 1;
	pthread_mutex_lock(&tmp->philo[i].fork);
	pthread_mutex_lock(&tmp->philo[j].fork);




	pthread_mutex_unlock(&tmp->philo[i].fork);
	pthread_mutex_unlock(&tmp->philo[j].fork);
	return (NULL);
}

int	init_threads(t_s *s)
{
	s->thread = ft_calloc(s->philos_count, sizeof(pthread_t));
//	if (pthread_mutex_init(&s->mutex, NULL))
//		return (printf("Error: mutex: init\n"));
	s->i = -1;
	while (++s->i < s->philos_count)
		if (pthread_create(&s->thread[s->i], NULL, philo_routine, s))
			return (printf("Error: thread: init\n"));
	s->i = -1;
	while (++s->i < s->philos_count)
		if (pthread_join(s->thread[s->i], NULL))
			return (printf("Error: thread: join\n"));


	return (0);
}

int main(int ac, char **av)
{
	t_s	s;

	if (parse_input(ac, &av, &s))
		return (-1);
//	printf("%lu %lu %lu %lu %lld\n", s.philos_count, s.t2die, s.t2eat, s.t2sleep, s.num_eat);

//	if (gettimeofday(&s.time, NULL))
//		return (printf("Error: gettime\n"));
//	s.ms = s.time.tv_sec;

//	for(int i = 0; i < s.philos_count; i++)
//		printf("%d %d %d\n", s.philo[i].philo_num, s.philo[i].eat_num, s.philo[i].fork_status);

//	if (init_threads(&s))
//		return (-1);
//
//
//
//
//
//
//	if (destroy_theads(&s))
//		return (-1);

	return (0);
}




/*


 if (pthread_mutex_destroy(&s->mutex))
		return (printf("Error: mutex: destroy\n"));
 */
