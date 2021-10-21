/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:27:04 by gernesto          #+#    #+#             */
/*   Updated: 2021/07/28 14:27:07 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	num;

	num = 1;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	while (num * num <= (unsigned int) nb)
		ft_sqrt(num++);
	num--;
	if ((num * num) == ((unsigned int) nb))
		return (num);
	else
		return (0);
}
