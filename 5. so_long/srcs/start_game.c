/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:45:07 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/09 10:51:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

void	start_game(t_map *map)
{
	draw_map(map);
	draw_objects(map);
	mlx_hook(map->mlx->win, 2, 1L << 1, do_keys, map);
}
