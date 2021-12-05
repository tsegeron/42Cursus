#include "../hdrs/so_long.h"

//void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = map->mlx->entr->addr + (y * map->mlx->entr->line_length + x * (map->mlx->entr->bits_per_pixel / 8));
//	*(unsigned int *)dst = color;
//}

int	close_win(void)
{
	exit(0);
}

/*
 * start_x, start_y
 * end_x, end_y
 * should be sent as x-1, y-1
 */
//void	draw_area(t_mlx *mlx, int color)
//{
//	int	s_y;
//	int	x=map->mlx->entr->start_x;
//	int	xe=map->mlx->entr->end_x;
//	int	y=map->mlx->entr->start_y;
//	int	ye=map->mlx->entr->end_y;
//
//	s_y = y;
//	while (++x < xe)
//	{
//		y = s_y;
//		while (++y < ye)
//			my_mlx_pixel_put(mlx, x, y, color);
//	}
//}
void	do_actual_painting(int i, int j, char c, t_map *map)
{
	if (c != '1' && (i + j) % 2 == 0)
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->back1->img, j * 50, i * 50);
	if (c != '1' && (i + j) % 2 != 0)
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->back2->img, j * 50, i * 50);
	if (c == '1')
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->wall->img, j * 50, i * 50);
	else if (c == 'P')
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->entr->img, j * 50, i * 50);
	else if (c == 'E')
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->exit->img, j * 50, i * 50);
//	else if (c == 'C')
//		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->coin1->img, j * 50, i * 50);
//	else if (c == 'C' && (i + j) % 2 != 0)
//		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->coin2->img, j * 50, i * 50);
	else
		return ;

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

void	init_images(t_map *map)
{
	map->mlx->wall = malloc(sizeof(t_img));
	map->mlx->back1 = malloc(sizeof(t_img));
	map->mlx->back2 = malloc(sizeof(t_img));
	map->mlx->entr = malloc(sizeof(t_img));
	map->mlx->exit = malloc(sizeof(t_img));
	map->mlx->hero1 = malloc(sizeof(t_img));
	map->mlx->hero2 = malloc(sizeof(t_img));
	map->mlx->enem1 = malloc(sizeof(t_img));
	map->mlx->enem2 = malloc(sizeof(t_img));
	map->mlx->coin1 = malloc(sizeof(t_img));
	map->mlx->coin2 = malloc(sizeof(t_img));

	map->mlx->wall->path = "imgs/wall_1.xpm";
	map->mlx->back1->path = "imgs/back_1.xpm";
	map->mlx->back2->path = "imgs/back_2.xpm";
	map->mlx->entr->path = "imgs/entr_1.xpm";
	map->mlx->exit->path = "imgs/exit_1.xpm";
	map->mlx->hero1->path = "imgs/hero_1.xpm";
	map->mlx->hero2->path = "imgs/hero_2.xpm";
	map->mlx->enem1->path = "imgs/enem_1.xpm";
	map->mlx->enem2->path = "imgs/enem_2.xpm";
	map->mlx->coin1->path = "imgs/coin_1.xpm";
	map->mlx->coin2->path = "imgs/coin_2.xpm";

	map->mlx->wall->img = mlx_xpm_file_to_image(map->mlx->mlx, map->mlx->wall->path, &map->mlx->wall->width, &map->mlx->wall->height);
	map->mlx->back1->img = mlx_xpm_file_to_image(map->mlx->mlx, map->mlx->back1->path, &map->mlx->back1->width, &map->mlx->back1->height);
	map->mlx->back2->img = mlx_xpm_file_to_image(map->mlx->mlx, map->mlx->back2->path, &map->mlx->back2->width, &map->mlx->back2->height);
	map->mlx->entr->img = mlx_xpm_file_to_image(map->mlx->mlx, map->mlx->entr->path, &map->mlx->entr->width, &map->mlx->entr->height);
	map->mlx->exit->img = mlx_xpm_file_to_image(map->mlx->mlx, map->mlx->exit->path, &map->mlx->exit->width, &map->mlx->exit->height);
	map->mlx->hero1->img = mlx_xpm_file_to_image(map->mlx->mlx, map->mlx->hero1->path, &map->mlx->hero1->width, &map->mlx->hero1->height);
	map->mlx->hero2->img = mlx_xpm_file_to_image(map->mlx->mlx, map->mlx->hero2->path, &map->mlx->hero2->width, &map->mlx->hero2->height);
	map->mlx->enem1->img = mlx_xpm_file_to_image(map->mlx->mlx, map->mlx->enem1->path, &map->mlx->enem1->width, &map->mlx->enem1->height);
	map->mlx->enem2->img = mlx_xpm_file_to_image(map->mlx->mlx, map->mlx->enem2->path, &map->mlx->enem2->width, &map->mlx->enem2->height);
	map->mlx->coin1->img = mlx_xpm_file_to_image(map->mlx->mlx, map->mlx->coin1->path, &map->mlx->coin1->width, &map->mlx->coin1->height);
	map->mlx->coin2->img = mlx_xpm_file_to_image(map->mlx->mlx, map->mlx->coin2->path, &map->mlx->coin2->width, &map->mlx->coin2->height);


//	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->wall->img, 0, 0);
//	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->back1->img, 50, 0);
//	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->back2->img, 100, 0);
//	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->entr->img, 150, 0);
//	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->exit->img, 200, 0);
//	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->hero1->img, 250, 0);
//	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->hero2->img, 300, 0);
//	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->enem1->img, 350, 0);
//	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->enem2->img, 400, 0);
//	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->coin1->img, 450, 0);
//	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->coin2->img, 500, 0);

}

int	render_frame(t_map *map)
{
	static int random = 3;

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
//	random++;
	map->random = random++;
//	printf("%d\n",random);
	return (0);
}

//int	randomizer(t_map *map)
//{
//	static int random = 3;
//
//	random++;
//	if (random > 1000)
//		random = 3;
//	map->random = random;
//	return (0);
//}

int	mlx_stuff(t_map *map)
{
	int	win_size_x;
	int	win_size_y;

	win_size_x = 1900;
	win_size_y = 1100;

	map->mlx->mlx = mlx_init();

	if (win_size_x > map->width * 50)
		win_size_x = map->width * 50;
	if (win_size_y > map->length * 50)
		win_size_y = map->length * 50;

	map->mlx->win = mlx_new_window(map->mlx->mlx, win_size_x, win_size_y, "Dollar bills!");
//	game_won(map);

	init_images(map);
	draw_map(map);
//	printf("%d,%d, %c\n", map->width, map->length, map->data[1][1]);

	start_game(map);



	mlx_loop_hook(map->mlx->mlx, render_frame, map);
//	mlx_loop_hook(map->mlx->mlx, randomizer, map);


//	mlx_key_hook(map->mlx->win, key_hook, mlx);
//	mlx_mouse_hook(map->mlx->win, mouse_hook, mlx);

	mlx_hook(map->mlx->win, 17, 1L<<0, close_win, map); // exit
//	mlx_hook(map->mlx->win, 2, 1L<<1, do_keys, mlx); // exit



	return (1);
}











//int	mouse_hook(int keycode, t_mlx *mlx)
//{
//	int	x;
//	int	y;
//
////	printf("%d!\n", keycode);
////	if (keycode == 1 && ((x > 7 && y > -19) && (x < 20 && y <-4)))
//	if (keycode == 2)
//	{
////		mlx_mouse_get_pos(map->mlx->win, &x, &y);
////		printf("%d,%d\n",x,y);
////		printf("here\n");
//		mlx_destroy_window(map->mlx->mlx, map->mlx->win);
//		exit(0);
//	}
//	return (0);
//}

//int	mouse_pos()
//{
//	int x,xo;
//	int y,yo;
//	mlx_mouse_get_pos(map->mlx->win, &xo,&yo);
//	while (!mlx_mouse_get_pos(map->mlx->win, &x,&y))
//	{
//		if (xo != x || yo != y)
//			printf("%d,%d\n", x, y);
//		xo = x;
//		yo = y;
//	}
//}
