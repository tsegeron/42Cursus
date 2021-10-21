/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:16:13 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/04 17:36:30 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int	check_operator(char *operator)
{
	if (ft_strlen(operator) > 1)
		return (0);
	if (operator[0] == '+')
		return (1);
	if (operator[0] == '-')
		return (2);
	if (operator[0] == '/')
		return (3);
	if (operator[0] == '*')
		return (4);
	if (operator[0] == '%')
		return (5);
	else
		return (0);
}
