/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:49:57 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/10 20:45:20 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs_b/philo.h"

int	parse_input(int ac, char ***av, t_s **s)
{
	int	i;
	int	status[5];

	if (ac < 5)
		return (printf("Error: lack of arguments\n"));
	else if (ac > 6)
		return (printf("Error: arguments: more than needed\n"));
	i = 0;
	(*s)->num_eat = -1;
	(*s)->philos_count = ft_atoi((*av)[++i], &status[0]);
	(*s)->t2die = ft_atoi((*av)[++i], &status[1]);
	(*s)->t2eat = ft_atoi((*av)[++i], &status[2]);
	(*s)->t2sleep = ft_atoi((*av)[++i], &status[3]);
	status[4] = -1;
	if (ac == 6)
		(*s)->num_eat = ft_atoi((*av)[++i], &status[4]);
	if (!status[0] || !status[1] || !status[2] || !status[3] || !status[4] || \
	(*s)->t2die > MAX || (*s)->t2eat > MAX || (*s)->t2sleep > MAX)
		return (printf("Error: invalid arguments\n"));
	return (0);
}
