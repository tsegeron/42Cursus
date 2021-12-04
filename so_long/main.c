/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:40:18 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/03 23:14:27 by gernesto         ###   ########.fr       */
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
	t_mlx	mlx;


	if (ac != 2 || !read_map(av[1], &map))
		return (print_map_error());
	mlx_stuff(&mlx);

	mlx_loop(mlx.mlx);





	return (0);
}
/*
	for(int i = 0; map.data[i]; i++)
		printf("%s", map.data[i]);


	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "Ducksuck!");
	mlx.img->img = mlx_new_image(mlx.mlx, 1920, 1080);
	mlx.img->addr = mlx_get_data_addr(mlx.img->img, &mlx.img->bits_per_pixel, &mlx.img->line_length,
									   &mlx.img->endian);
	my_mlx_pixel_put(&mlx, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img->img, 0, 0);
	mlx_loop(mlx.mlx);
*/
