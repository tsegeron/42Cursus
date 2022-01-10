/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:18:18 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/10 22:41:40 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static int	get_num_len(int num)
{
	int	len;

	len = 1;
	while (num / 10)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*get_num_in_char(int num)
{
	char	*res;
	int		end;
	int		i;

	end = get_num_len(num);
	i = end;
	res = (char *) malloc((end + 1) * sizeof(char));
	while (end-- != 0)
	{
		res[end] = num % 10 + 48;
		num /= 10;
	}
	res[i] = '\0';
	return (res);
}

int	write_action(t_s *s, unsigned long philo, char c)
{
	char	*str_to_print;
	int		timestamp;

	timestamp = get_time_passed(s);
	if (timestamp < 0)
		return (-1);
	str_to_print = NULL;
	str_to_print = ft_strjoin(str_to_print, get_num_in_char(timestamp));
	str_to_print = ft_strjoin(str_to_print, " ");
	str_to_print = ft_strjoin(str_to_print, get_num_in_char((int )philo));
	if (c == 'f')
		str_to_print = ft_strjoin(str_to_print, MSG_FORK);
	else if (c == 'e')
		str_to_print = ft_strjoin(str_to_print, MSG_EAT);
	else if (c == 's')
		str_to_print = ft_strjoin(str_to_print, MSG_SLEEP);
	else if (c == 't')
		str_to_print = ft_strjoin(str_to_print, MSG_THINK);
	else if (c == 'd')
		str_to_print = ft_strjoin(str_to_print, MSG_DIE);
	pthread_mutex_lock(&s->stdout_stat);
	write(STDOUT_FILENO, str_to_print, ft_strlen(str_to_print));
	free(str_to_print);
	pthread_mutex_unlock(&s->stdout_stat);
	return (0);
}
