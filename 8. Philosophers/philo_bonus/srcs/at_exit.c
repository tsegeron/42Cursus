/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:16:34 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/12 00:29:54 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static int	check_all_eat_count(t_s *s, t_list *philo)
{
	unsigned long	i;
	unsigned long	fed;
	t_list			*tmp;

	tmp = philo;
	i = -1;
	fed = 0;
	while (++i < s->philos_count)
	{
		if (tmp->eat_num == (unsigned long )s->num_eat)
			fed++;
		if (fed == s->philos_count)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	loop_at_exit(t_s *s, t_list *philo)
{
	t_list			*lst_start;
	unsigned long	cur_time;

	lst_start = philo;
	while (philo)
	{
		cur_time = get_time_passed(philo->s);
		if (cur_time > philo->last_meal + philo->s->t2die
			&& philo->eat_num < (unsigned long )s->num_eat)
		{
			philo->s->die_status = 1;
			write_action(s, philo->philo_num, 'd');
			pthread_mutex_lock(&s->stdout_stat);
			return ;
		}
		if (check_all_eat_count(s, lst_start))
			return ;
		philo = philo->next;
	}
}

int	destroy_mutexes_at_exit(t_s **s, t_list **philo)
{
	unsigned long	i;

	i = -1;
	while (++i < (*s)->philos_count)
	{
		pthread_mutex_unlock(&(*philo)->fork);
		if (pthread_mutex_destroy(&(*philo)->fork))
		{
			pthread_mutex_unlock(&(*philo)->fork);
			if (pthread_mutex_destroy(&(*philo)->fork))
				return (error_write("Error: mutex: destroy fork\n"));
		}
		*philo = (*philo)->next;
	}
	pthread_mutex_unlock(&(*s)->stdout_stat);
	if (pthread_mutex_destroy(&(*s)->stdout_stat))
		return (error_write("Error: mutex: destroy stdout\n"));
	return (0);
}
