/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:54:30 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/06 22:05:49 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long_b.h"

/*
 *
 */
static void	do_actual_painting(int i, int j, char c, t_map *map)
{
	if (c != '1' && (i + j) % 2 == 0)
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win,
			map->mlx->back1->img, j * 50, i * 50);
	if (c != '1' && (i + j) % 2 != 0)
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win,
			map->mlx->back2->img, j * 50, i * 50);
	if (c == '1')
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win,
			map->mlx->wall->img, j * 50, i * 50);
	else if (c == 'P')
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win,
			map->mlx->entr->img, j * 50, i * 50);
	else if (c == 'E')
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win,
			map->mlx->exit->img, j * 50, i * 50);
}

void	draw_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->length)
	{
		j = -1;
		while (++j < map->width)
			do_actual_painting(i, j, map->data[i][j], map);
	}
}

static void	draw_coin(t_map *map)
{
	while (map->coin != NULL)
	{
		if (map->coin->x != 0 && map->mlx->anim_state == 0)
			mlx_put_image_to_window(map->mlx->mlx, map->mlx->win,
				map->mlx->coin1->img, map->coin->x * 50, map->coin->y * 50);
		else if (map->coin->x != 0 && map->mlx->anim_state == 1)
			mlx_put_image_to_window(map->mlx->mlx, map->mlx->win,
				map->mlx->coin2->img, map->coin->x * 50, map->coin->y * 50);
		map->coin = map->coin->next;
	}
}

static void	draw_enem(t_map *map)
{
	while (map->enem != NULL)
	{
		if (map->enem->x != 0 && map->mlx->anim_state == 0)
			mlx_put_image_to_window(map->mlx->mlx, map->mlx->win,
				map->mlx->enem1->img, map->enem->x * 50, map->enem->y * 50);
		else if (map->enem->x != 0 && map->mlx->anim_state == 1)
			mlx_put_image_to_window(map->mlx->mlx, map->mlx->win,
				map->mlx->enem2->img, map->enem->x * 50, map->enem->y * 50);
		map->enem = map->enem->next;
	}
}

void	draw_objects(t_map *map)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = map->coin;
	tmp2 = map->enem;
	draw_coin(map);
	if (BONUS)
		draw_enem(map);
	if ((map->hero->x + map->hero->y) % 2 == 1)
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win,
			map->mlx->hero1->img, map->hero->x * 50, map->hero->y * 50);
	else if ((map->hero->x + map->hero->y) % 2 == 0)
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win,
			map->mlx->hero2->img, map->hero->x * 50, map->hero->y * 50);
	map->coin = tmp1;
	map->enem = tmp2;
	if (BONUS)
		show_move_count(map);
}
