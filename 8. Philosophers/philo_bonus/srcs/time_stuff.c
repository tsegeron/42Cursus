/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:03:39 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/14 17:36:11 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

int	get_time_passed(t_s *s)
{
	struct timeval	cur_time;
	int				res;

	if (gettimeofday(&cur_time, NULL))
		return (error_write("Error: gettime\n"));
	res = ((int )(cur_time.tv_sec - s->start_time.tv_sec)) * 1000;
	res += ((int )cur_time.tv_usec - (int )s->start_time.tv_usec) / 1000;
	return (res);
}

void	smart_sleep(t_s *s, unsigned long t2do)
{
	unsigned long	end_time;

	if (s->die_status)
		return ;
	end_time = get_time_passed(s) + t2do;
	while ((unsigned long )get_time_passed(s) < end_time)
		usleep(100);
}
