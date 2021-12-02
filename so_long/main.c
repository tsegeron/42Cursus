/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:40:18 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/02 06:40:19 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/so_long.h"

static int	print_map_error(void)
{
	write (2, "Map error\n", 10);
	return (0);
}

int	main(int ac, char *av[])
{
	t_map	map;

	if (ac != 2 || !read_map(av[1], &map))
		return (print_map_error());
	
	return (0);
}
