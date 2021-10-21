/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:22:07 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/04 17:23:37 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_do_op.h"

int	main(int ac, char **av)
{
	int	(*f)(char	*);
	int	(*ft)(char	*);
    int a;
	int	operator;
	int	b;

	f = &check_operator;
	ft = &ft_atoi;
	if (ac != 4)
		return (0);
	operator = f(av[2]);
    a = ft(av[1]);
	b = ft(av[3]);
	if (operator == 0)
	{
		write (1, "0\n", 2);
		return (0);
	}
	if (check_divmod_0(operator, b) == 1)
		return (0);
	print_result(a, operator, b);
	return (0);
}
