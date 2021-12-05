#include "../hdrs/so_long.h"

void	go_bot(t_map *map);
void	go_top(t_map *map);

void	go_right(t_map *map)
{
	if (map->data[map->enem->y][map->enem->x + 1] != '1')
		map->enem->x++;
	else
		go_bot(map);
}

void	go_left(t_map *map)
{
	if (map->data[map->enem->y][map->enem->x - 1] != '1')
		map->enem->x--;
	else
		go_top(map);
}

void	go_bot(t_map *map)
{
	if (map->data[map->enem->y + 1][map->enem->x] != '1')
		map->enem->y++;
	else
		go_left(map);
}

void	go_top(t_map *map)
{
	if (map->data[map->enem->y - 1][map->enem->x] != '1')
		map->enem->y--;
	else
		go_right(map);
}

void	make_enem_move(t_map *map)
{
	t_list	*tmp;
	int		dir;

	tmp = map->enem;
	while (map->enem != NULL)
	{
		dir = (map->random + map->moves_count) % 10;
		dir = (map->random - map->count_coins + dir - map->enem->list_position) % 4;
		if (dir == 3)
			go_top(map);
		else if (dir == 1)
			go_left(map);
		else if (dir == 2)
			go_bot(map);
		else if (dir == 0)
			go_right(map);
		game_lost(map);
		map->enem = map->enem->next;
	}
	map->enem = tmp;
	mlx_clear_window(map->mlx->mlx, map->mlx->win);
	draw_map(map);
	draw_objects(map);
}
