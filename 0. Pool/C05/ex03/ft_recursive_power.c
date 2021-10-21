/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:51:13 by gernesto          #+#    #+#             */
/*   Updated: 2021/07/28 21:51:35 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0 && power % 2 == 0 && (nb == 1 || nb == -1))
		return (1);
	if (power < 0 && power % 2 != 0 && nb == -1)
		return (-1);
	if (power < 0 && nb != 1 && nb != -1)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
