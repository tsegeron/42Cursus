/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:37:27 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/11 21:12:06 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_b/philo.h"

static void	philo_eats(t_list *tmp)
{
	if (tmp->philo_num % 2)
	{
		pthread_mutex_lock(&tmp->fork);
		write_action(tmp->s, tmp->philo_num, 'f');
		pthread_mutex_lock(&tmp->next->fork);
	}
	else
	{
		pthread_mutex_lock(&tmp->next->fork);
		write_action(tmp->s, tmp->philo_num, 'f');
		pthread_mutex_lock(&tmp->fork);
	}
	write_action(tmp->s, tmp->philo_num, 'f');
	write_action(tmp->s, tmp->philo_num, 'e');
	smart_sleep(tmp->s, tmp->s->t2eat);
	if (tmp->philo_num % 2)
	{
		pthread_mutex_unlock(&tmp->next->fork);
		pthread_mutex_unlock(&tmp->fork);
	}
	else
	{
		pthread_mutex_unlock(&tmp->fork);
		pthread_mutex_unlock(&tmp->next->fork);
	}
}

void	*philo_routine(void *philo)
{
	t_list			*tmp;

	tmp = (t_list *)philo;
	if (!(tmp->philo_num % 2))
		usleep(1000);
	while (!tmp->s->die_status)
	{
		philo_eats(tmp);
		tmp->last_meal = get_time_passed(tmp->s);
		tmp->eat_num += 1;
		if ((long long)tmp->eat_num == tmp->s->num_eat)
			return (NULL);
		write_action(tmp->s, tmp->philo_num, 's');
		smart_sleep(tmp->s, tmp->s->t2sleep);
		write_action(tmp->s, tmp->philo_num, 't');
	}
	return (NULL);
}