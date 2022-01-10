/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:34:13 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/10 22:37:28 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	init_philos_and_mutexes(t_s *s)
{
	int	i;

	s->die_status = 0;
	s->philo = ft_calloc(s->philos_count, sizeof(t_philo));
	if (!s->philo)
		return (printf("Error: malloc\n"));
	i = 0;
	while (i < s->philos_count)
	{
		s->philo[i].philo_num = i + 1;
		if (pthread_mutex_init(&s->philo[i++].fork, NULL))
			return (printf("Error: mutex: init\n"));
	}
	if (pthread_mutex_init(&s->death_stat, NULL))
		return (printf("Error: mutex: init\n"));
	if (pthread_mutex_init(&s->stdout_stat, NULL))
		return (printf("Error: mutex: init\n"));
	return (0);
}

int	init_threads(t_s *s)
{
	unsigned long	*res;
	int				i;

	if (s->philos_count == 1)
	{
		smart_sleep(s, s->t2die);
		return (write_action(s, 1, 'd'));
	}
	s->thread = ft_calloc(s->philos_count, sizeof(pthread_t));
	s->i = 0;
	while (s->i < s->philos_count)
	{
		if (pthread_create(&s->thread[s->i], NULL, &philo_routine, s))
			return (printf("Error: thread: init\n"));
		s->i++;
//		smart_sleep(s, 10);
	}
	i = 0;
	while (i < s->philos_count)
	{
		if (pthread_join(s->thread[i++], NULL))
			return (printf("Error: thread: join\n"));
//		if (*res)
//		{
//			printf("Error occurred in thread %lu\n", *res / 100);
//			free (res);
//			return (-1);
//		}
//		free (res);
	}
	return (0);
}
