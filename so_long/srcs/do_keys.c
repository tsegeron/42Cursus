#include "../hdrs/so_long.h"

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

void	do_key_w(t_map *map)
{
	if (map->data[map->hero->y - 1][map->hero->x] != '1')
	{
		map->hero->y--;
		printf("%d\n", ++map->moves_count);
		if (map->data[map->hero->y][map->hero->x] == 'C')
			del_coin(map);
	}
}

void	do_key_a(t_map *map)
{
	if (map->data[map->hero->y][map->hero->x - 1] != '1')
	{
		map->hero->x--;
		printf("%d\n", ++map->moves_count);
		if (map->data[map->hero->y][map->hero->x] == 'C')
			del_coin(map);
	}
}

void	do_key_s(t_map *map)
{
	if (map->data[map->hero->y + 1][map->hero->x] != '1')
	{
		map->hero->y++;
		printf("%d\n", ++map->moves_count);
		if (map->data[map->hero->y][map->hero->x] == 'C')
			del_coin(map);
	}
}

void	do_key_d(t_map *map)
{
	if (map->data[map->hero->y][map->hero->x + 1] != '1')
	{
		map->hero->x++;
		printf("%d\n", ++map->moves_count);
		if (map->data[map->hero->y][map->hero->x] == 'C')
			del_coin(map);
	}
}

int	do_keys(int keycode, t_map *map)
{
//	printf("HERE\n");
//	printf("%d!\n", keycode);
//	mlx_clear_window(map->mlx->mlx, map->mlx->win);
//	printf("%d,%d,%d,%d\n",map->mlx->entr->start_x, map->mlx->entr->start_y, map->mlx->entr->end_x, map->mlx->entr->end_y);
	if (keycode == 53)
		close_win();
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
	if (map->hero->x == map->exit->x && map->hero->y == map->exit->y && map->count_coins == 0)
		close_win();
//		game_won(map);

	return (0);
}
