#include "../hdrs/so_long.h"

void	game_won(t_map *map)
{
//	printf("PRINTED");
	mlx_string_put(map->mlx->mlx, map->mlx->win, (map->width/2)*50, (map->length/2)*50, 0x00FF0000, "YOU WON!");
//	exit (0);
}

void	game_lost(t_map *map)
{
	t_list	*tmp;

	tmp = map->enem;
	while (map->enem != NULL)
	{
		if (map->enem->x == map->hero->x && map->enem->y == map->hero->y)
			close_win();
		map->enem = map->enem->next;
	}
	map->enem = tmp;
}

void	show_move_count(t_map *map)
{
//	if (BONUS)
//	{
//
//	}
//	else
		printf("%d\n", ++map->moves_count);
}
//(map->length-1) * 50, (map->width-1) * 50;


void	draw_objects(t_map *map)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = map->coin;
	tmp2 = map->enem;
	while (map->coin != NULL)
	{
		if (map->coin->x != 0 && map->mlx->anim_state == 0)
			mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->coin1->img, map->coin->x * 50, map->coin->y * 50);
		else if (map->coin->x != 0 && map->mlx->anim_state == 1)
			mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->coin2->img, map->coin->x * 50, map->coin->y * 50);
		map->coin = map->coin->next;
	}
	while (map->enem != NULL)
	{
		if (map->enem->x != 0 && map->mlx->anim_state == 0)
			mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->enem1->img, map->enem->x * 50, map->enem->y * 50);
		else if (map->enem->x != 0 && map->mlx->anim_state == 1)
			mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->enem2->img, map->enem->x * 50, map->enem->y * 50);
		map->enem = map->enem->next;
	}
	if ((map->hero->x + map->hero->y) % 2 == 1)
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->hero1->img, map->hero->x * 50, map->hero->y * 50);
	else if ((map->hero->x + map->hero->y) % 2 == 0)
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->hero2->img, map->hero->x * 50, map->hero->y * 50);
	map->coin = tmp1;
	map->enem = tmp2;
//	game_won(map);
}

void	start_game(t_map *map)
{
	draw_objects(map);
//	printf("\n%d,%d\n", map->hero->x, map->hero->y);
//	printf("\n");
	mlx_hook(map->mlx->win, 2, 1L<<1, do_keys, map);
	make_enem_move(map);

}
//	mlx_clear_window(map->mlx->mlx, map->mlx->win);
//	mlx_destroy_image(map->mlx->mlx, map->mlx->entr->img);

//		if (map->mlx->anim_state == 0)
//			mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->coin1->img, map->coin->x * 50, map->coin->y * 50);
//		else if (map->mlx->anim_state == 1)