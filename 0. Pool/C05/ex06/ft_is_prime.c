/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:55:08 by gernesto          #+#    #+#             */
/*   Updated: 2021/07/28 16:55:10 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	num;

	num = nb - 1;
	if (nb <= 1)
		return (0);
	while (nb / num != (unsigned int) nb)
	{
		if ((nb / num * num) == ((unsigned int) nb))
			return (0);
		else
			num--;
	}
	return (1);
}
