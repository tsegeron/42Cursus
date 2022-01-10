/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:37:27 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/10 22:01:44 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	death_check(t_s *s, unsigned long i)
{
	unsigned long	cur_time;

	cur_time = get_time_passed(s);
	if (cur_time - s->t2die > s->philo[i].last_meal)
	{
		s->die_status = 1;
		write_action(s, i + 1, 'd');
		return (1);
	}
	return (0);
}

void	*philo_routine(void *s)
{
	unsigned long	i;
	unsigned long	j;
//	unsigned long	*res;
	t_s				*tmp;

//	tmp = (t_s *)s;
	i = ((t_s *)s)->i;
	if (i == 0)
		j = ((t_s *)s)->philos_count - 1;
	else
		j = i - 1;
	((t_s *)s)->philo[i].last_meal = 0;
	while (!((t_s *)s)->die_status)
	{
//		if (death_check(s, i))
//			break ;
		pthread_mutex_lock(&((t_s *)s)->philo[i].fork);
//		if (death_check(s, i))
//			break ;
		write_action(s, i + 1, 'f');
		pthread_mutex_lock(&((t_s *)s)->philo[j].fork);
		if (death_check(s, i))
			break ;
		write_action(s, i + 1, 'f');
		write_action(s, i + 1, 'e');
		smart_sleep(((t_s *)s), ((t_s *)s)->t2eat);
		((t_s *)s)->philo[i].last_meal = get_time_passed(s);
		((t_s *)s)->philo[i].eat_num += 1;
		if (((t_s *)s)->philo[i].eat_num == ((t_s *)s)->num_eat)
			break ;
		write_action(s, i + 1, 's');
		smart_sleep(((t_s *)s), ((t_s *)s)->t2sleep);
		write_action(s, i + 1, 't');
		pthread_mutex_unlock(&((t_s *)s)->philo[i].fork);
		pthread_mutex_unlock(&((t_s *)s)->philo[j].fork);
	}
	return (NULL);
}
