#include "../hdrs/so_long.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->entr->addr + (y * mlx->entr->line_length + x * (mlx->entr->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_win(void)
{
	exit(0);
}
/*
 * start_x, start_y
 * end_x, end_y
 * should be sent as x-1, y-1
 */
void	draw_area(t_mlx *mlx, int color)
{
	int	s_y;
	int	x=mlx->entr->start_x;
	int	xe=mlx->entr->end_x;
	int	y=mlx->entr->start_y;
	int	ye=mlx->entr->end_y;

	s_y = y;
	while (++x < xe)
	{
		y = s_y;
		while (++y < ye)
			my_mlx_pixel_put(mlx, x, y, color);
	}
}


int	render_frame(t_mlx *mlx)
{
	static int	random = 10;
	random++;
	printf("%d\n",random);


	return (0);
}

void	init_images(t_mlx *mlx)
{
	mlx->entr = malloc(sizeof(t_img));
//	mlx->exit = malloc(sizeof(t_img));
//	mlx->hero = malloc(sizeof(t_img));
//	mlx->enem = malloc(sizeof(t_img));
//	mlx->coin = malloc(sizeof(t_img));

//	mlx->entr->img = mlx_new_image(mlx->mlx, 1900, 1100);
//	mlx->entr->addr = mlx_get_data_addr(mlx->entr->img, &mlx->entr->bits_per_pixel,
//									   &mlx->entr->line_length, &mlx->entr->endian);
//	mlx->exit->img = mlx_new_image(mlx->mlx, 1900, 1100);
//	mlx->hero->img = mlx_new_image(mlx->mlx, 1900, 1100);
//	mlx->enem->img = mlx_new_image(mlx->mlx, 1900, 1100);
//	mlx->coin->img = mlx_new_image(mlx->mlx, 1900, 1100);

	mlx->entr->path = "../imgs/entr_1.xpm";
//	mlx->exit->path = "../imgs/exit_1.xpm";
//	mlx->hero->path = "../imgs/hero_1.xpm";
//	mlx->enem->path = "../imgs/enem_1.xpm";
//	mlx->coin->path = "../imgs/coin_1.xpm";

	mlx->entr->img = mlx_xpm_file_to_image(mlx->mlx, mlx->entr->path, &mlx->entr->width, &mlx->entr->height);
//	mlx->exit->img = mlx_xpm_file_to_image(mlx->mlx, mlx->exit->path, &mlx->exit->width, &mlx->exit->height);
//	mlx->hero->img = mlx_xpm_file_to_image(mlx->mlx, mlx->hero->path, &mlx->hero->width, &mlx->hero->height);
//	mlx->enem->img = mlx_xpm_file_to_image(mlx->mlx, mlx->enem->path, &mlx->enem->width, &mlx->enem->height);
//	mlx->coin->img = mlx_xpm_file_to_image(mlx->mlx, mlx->coin->path, &mlx->coin->width, &mlx->coin->height);

	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->entr->img, 50, 50);

}

int	mlx_stuff(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1900, 1100, "Dollar bills!");



	init_images(mlx);

//	mlx->entr->end_x = 850;
//	mlx->entr->end_y = 850;
//	mlx->entr->start_x = 800;
//	mlx->entr->start_y = 800;
//	mlx->entr->addr = mlx_get_data_addr(mlx->entr->img, &mlx->entr->bits_per_pixel,
//									   &mlx->entr->line_length, &mlx->entr->endian);
//	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->entr->img, 50, 50);
//	draw_area(mlx, 0x99FF0000);

//	mlx_key_hook(mlx->win, key_hook, mlx);
//	mlx_mouse_hook(mlx->win, mouse_hook, mlx);


	mlx_hook(mlx->win, 17, 1L<<0, close_win, mlx); // exit
	mlx_hook(mlx->win, 2, 1L<<1, key_hook, mlx); // exit



	//	mlx_loop_hook(mlx->mlx, render_frame, mlx);


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
////		mlx_mouse_get_pos(mlx->win, &x, &y);
////		printf("%d,%d\n",x,y);
////		printf("here\n");
//		mlx_destroy_window(mlx->mlx, mlx->win);
//		exit(0);
//	}
//	return (0);
//}

//int	mouse_pos()
//{
//	int x,xo;
//	int y,yo;
//	mlx_mouse_get_pos(mlx->win, &xo,&yo);
//	while (!mlx_mouse_get_pos(mlx->win, &x,&y))
//	{
//		if (xo != x || yo != y)
//			printf("%d,%d\n", x, y);
//		xo = x;
//		yo = y;
//	}
//}
