/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_divmod_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:07:38 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/04 17:14:58 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_divmod_0(int operator, long long int b)
{
	if (operator == 3 && b == 0)
	{
		write (1, "Stop : division by zero\n", 24);
		return (1);
	}
	if (operator == 5 && b == 0)
	{
		write (1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	else
		return (0);
}
