/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/09 11:25:17 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

static void	do_key_w(t_map *map)
{
	if (map->data[map->hero->y - 1][map->hero->x] != '1')
	{
		map->hero->y--;
		map->moves_count++;
		if (!BONUS)
			show_move_count(map);
		if (map->data[map->hero->y][map->hero->x] == 'C')
			del_coin(map);
	}
}

static void	do_key_a(t_map *map)
{
	if (map->data[map->hero->y][map->hero->x - 1] != '1')
	{
		map->hero->x--;
		map->moves_count++;
		if (!BONUS)
			show_move_count(map);
		if (map->data[map->hero->y][map->hero->x] == 'C')
			del_coin(map);
	}
}

static void	do_key_s(t_map *map)
{
	if (map->data[map->hero->y + 1][map->hero->x] != '1')
	{
		map->hero->y++;
		map->moves_count++;
		if (!BONUS)
			show_move_count(map);
		if (map->data[map->hero->y][map->hero->x] == 'C')
			del_coin(map);
	}
}

static void	do_key_d(t_map *map)
{
	if (map->data[map->hero->y][map->hero->x + 1] != '1')
	{
		map->hero->x++;
		map->moves_count++;
		if (!BONUS)
			show_move_count(map);
		if (map->data[map->hero->y][map->hero->x] == 'C')
			del_coin(map);
	}
}

int	do_keys(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		map->close_state = 3;
		close_win();
	}
	if (keycode == 13)
		do_key_w(map);
	else if (keycode == 0)
		do_key_a(map);
	else if (keycode == 1)
		do_key_s(map);
	else if (keycode == 2)
		do_key_d(map);
	mlx_clear_window(map->mlx->mlx, map->mlx->win);
	draw_map(map);
	draw_objects(map);
	game_lost(map);
	game_won(map);
	return (0);
}
