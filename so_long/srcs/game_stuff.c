/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:46:31 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/06 22:46:45 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	close_win(void)
{
	sleep(1);
	exit(0);
}

void	game_won(t_map *map)
{
	map->close_state = 1;
	close_win();
}

void	game_lost(t_map *map)
{
	t_list	*tmp;

	tmp = map->enem;
	while (map->enem != NULL)
	{
		if (map->enem->x == map->hero->x && map->enem->y == map->hero->y)
		{
			map->close_state = 2;
			close_win();
		}
		map->enem = map->enem->next;
	}
	map->enem = tmp;
}

void	del_coin(t_map *map)
{
	t_list	*tmp;

	tmp = map->coin;
	map->data[map->hero->y][map->hero->x] = '0';
	map->count_coins--;
	while (map->coin != NULL)
	{
		if (map->coin->x == map->hero->x && map->coin->y == map->hero->y)
		{
			map->coin->x = 0;
			map->coin->y = 0;
			break ;
		}
		map->coin = map->coin->next;
	}
	map->coin = tmp;
}

void	show_move_count(t_map *map)
{
	char	*steps;

	if (BONUS)
	{
		steps = ft_itoa(map->moves_count);
		mlx_string_put(map->mlx->mlx, map->mlx->win,
			(map->width - 1) * 50 + 20, 30, 0xFFFFFF, steps);
		free (steps);
	}
	else
		printf("%d\n", map->moves_count);
}
