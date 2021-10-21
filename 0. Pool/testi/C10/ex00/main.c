/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 05:08:16 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/03 05:08:20 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "ft_display_file.h"

void	ft_putstr(int a, char *str)
{
	while (*str)
	{
		write (a, str, 1);
		str++;
	}
}

int	check_ac(int ac)
{
	if (ac < 2)
	{
		ft_putstr(2, MSG_NO);
		return (1);
	}
	else if (ac > 2)
	{
		ft_putstr(2, MSG_MANY);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	fd;
	int	ret;

	if (check_ac(ac) == 1)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(2, MSG_READ);
		return (1);
	}
	ret = read(fd, av[1], BUF_SIZE);
	if (ret == 1)
		return (1);
	if (ret == -1)
	{
		ft_putstr(2, MSG_READ);
		return (1);
	}
	write(1, av[1], ret);
	close(fd);
	return (0);
}
