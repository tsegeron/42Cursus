/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:40:18 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/06 23:33:34 by gernesto         ###   ########.fr       */
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

	map.mlx = malloc(sizeof(t_mlx));
	if (ac != 2 || !read_map(av[1], &map))
		return (print_map_error());
	mlx_stuff(&map);
	mlx_loop(map.mlx->mlx);
	return (0);
}
/*
	for(int i = 0; map.data[i]; i++)
		printf("%s", map.data[i]);

	free images

 */