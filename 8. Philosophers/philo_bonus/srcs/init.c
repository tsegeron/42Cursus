/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:34:13 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/11 21:18:45 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	philos_and_mutexes_init(t_s **s, t_list **philo)
{
	t_list			*lst_start;
	t_list			*lst_last;
	unsigned long	i;

	(*s)->die_status = 0;
	i = -1;
	while (++i < (*s)->philos_count)
		ft_lstadd_back(&(*philo), ft_lstnew(i + 1, (*s)));
	lst_start = (*philo);
	lst_last = ft_lstlast((*philo));
	lst_last->next = (*philo);
	(*philo)->prev = lst_last;
	(*philo) = lst_start;
	i = -1;
	while (++i < (*s)->philos_count)
	{
		if (pthread_mutex_init(&(*philo)->fork, NULL))
			return (error_write("Error: mutex: init\n"));
		(*philo) = (*philo)->next;
	}
	(*philo) = lst_start;
	if (pthread_mutex_init(&(*s)->stdout_stat, NULL))
		return (error_write("Error: mutex: init\n"));
	return (0);
}

int	threads_init(t_s *s, t_list *philo)
{
	unsigned int	i;

	s->thread = ft_calloc(s->philos_count, sizeof(pthread_t));
	i = 0;
	while (i < s->philos_count)
	{
		if (pthread_create(&s->thread[i], NULL, &philo_routine, philo))
			return (error_write("Error: thread: init\n"));
		philo = philo->next;
		if (pthread_detach(s->thread[i]))
			return (error_write("Error: thread: init\n"));
		i++;
	}
	return (0);
}
