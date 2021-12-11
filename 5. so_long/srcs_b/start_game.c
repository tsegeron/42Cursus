/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:45:07 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/09 11:06:26 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long_b.h"

int	check_pos(t_map *map, int pos, int x, int y)
{
	t_list	*tmp;

	tmp = map->enem;
	while (map->enem != NULL)
	{
		if (pos != map->enem->list_position
			&& x == map->enem->x && y == map->enem->y)
			return (0);
		map->enem = map->enem->next;
	}
	map->enem = tmp;
	return (1);
}

void	start_game(t_map *map)
{
	draw_map(map);
	draw_objects(map);
	mlx_hook(map->mlx->win, 2, 1L << 1, do_keys, map);
}
