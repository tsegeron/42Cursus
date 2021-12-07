/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:13:26 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/06 22:55:09 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

static void	init_other_images(t_map *map,
							void *(*f)(void *, char *, int *, int *))
{
	map->mlx->entr = malloc(sizeof(t_img));
	map->mlx->exit = malloc(sizeof(t_img));
	map->mlx->enem1 = malloc(sizeof(t_img));
	map->mlx->enem2 = malloc(sizeof(t_img));
	map->mlx->coin1 = malloc(sizeof(t_img));
	map->mlx->coin2 = malloc(sizeof(t_img));
	map->mlx->entr->img = f(map->mlx->mlx, "imgs/entr1.xpm",
			&map->mlx->entr->width, &map->mlx->entr->height);
	map->mlx->exit->img = f(map->mlx->mlx, "imgs/exit1.xpm",
			&map->mlx->exit->width, &map->mlx->exit->height);
	map->mlx->enem1->img = f(map->mlx->mlx, "imgs/enem1.xpm",
			&map->mlx->enem1->width, &map->mlx->enem1->height);
	map->mlx->enem2->img = f(map->mlx->mlx, "imgs/enem2.xpm",
			&map->mlx->enem2->width, &map->mlx->enem2->height);
	map->mlx->coin1->img = f(map->mlx->mlx, "imgs/coin1.xpm",
			&map->mlx->coin1->width, &map->mlx->coin1->height);
	map->mlx->coin2->img = f(map->mlx->mlx, "imgs/coin2.xpm",
			&map->mlx->coin2->width, &map->mlx->coin2->height);
}

static void	init_images(t_map *map)
{
	void	*(*f)(void *, char *, int *, int *);

	f = mlx_xpm_file_to_image;
	map->mlx->wall = malloc(sizeof(t_img));
	map->mlx->back1 = malloc(sizeof(t_img));
	map->mlx->back2 = malloc(sizeof(t_img));
	map->mlx->hero1 = malloc(sizeof(t_img));
	map->mlx->hero2 = malloc(sizeof(t_img));
	map->mlx->wall->img = f(map->mlx->mlx, "imgs/wall1.xpm",
			&map->mlx->wall->width, &map->mlx->wall->height);
	map->mlx->back1->img = f(map->mlx->mlx, "imgs/back1.xpm",
			&map->mlx->back1->width, &map->mlx->back1->height);
	map->mlx->back2->img = f(map->mlx->mlx, "imgs/back2.xpm",
			&map->mlx->back2->width, &map->mlx->back2->height);
	map->mlx->hero1->img = f(map->mlx->mlx, "imgs/hero1.xpm",
			&map->mlx->hero1->width, &map->mlx->hero1->height);
	map->mlx->hero2->img = f(map->mlx->mlx, "imgs/hero2.xpm",
			&map->mlx->hero2->width, &map->mlx->hero2->height);
	init_other_images(map, f);
}

static int	render_frame(t_map *map)
{
	static int	random = 3;

	if (random == 4)
	{
		map->mlx->anim_state = 0;
		draw_objects(map);
	}
	else if (random == 3002)
	{
		map->mlx->anim_state = 1;
		draw_objects(map);
	}
	if (random > 6000)
	{
		make_enem_move(map);
		random = 3;
	}
	map->random = random++;
	return (0);
}

static void	set_up_window(t_map *map)
{
	int	win_size_x;
	int	win_size_y;

	win_size_x = 2560;
	win_size_y = 1418;
	if (win_size_x > map->width * 50)
		win_size_x = map->width * 50;
	else
		exit(printf("Too large input map\n"));
	if (win_size_y > map->length * 50)
		win_size_y = map->length * 50;
	else
		exit(printf("Too large input map\n"));
	map->mlx->win = mlx_new_window(map->mlx->mlx, win_size_x,
			win_size_y, "Dollar bills!");
}

int	mlx_stuff(t_map *map)
{
	map->mlx->mlx = mlx_init();
	set_up_window(map);
	init_images(map);
	start_game(map);
	mlx_loop_hook(map->mlx->mlx, render_frame, map);
	mlx_hook(map->mlx->win, 17, 1L << 0, close_win, map);
	return (1);
}

/*
//	mlx_clear_window(map->mlx->mlx, map->mlx->win);
//	draw_map(map);
//	if (map->close_state == 1)
//		mlx_string_put(map->mlx->mlx, map->mlx->win, (map->width / 2) * 50,
//					   (map->length / 2) * 50, 0x00FF00, "YOU WON!");
//	else if (map->close_state == 2)
//		mlx_string_put(map->mlx->mlx, map->mlx->win, (map->width / 2) * 50,
//					   (map->length / 2) * 50, 0x00FF00, "YOU LOST!");
//	else
//		mlx_string_put(map->mlx->mlx, map->mlx->win, (map->width / 2) * 50,
//					   (map->length / 2) * 50, 0x00FF00, "THX FOR PLAYING!");
 */