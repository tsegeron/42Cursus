#include "../hdrs/so_long.h"

void	do_key_w(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->entr->img);
	mlx->entr->img = mlx_new_image(mlx->mlx, 1900, 1100);
	mlx->entr->addr = mlx_get_data_addr(mlx->entr->img, &mlx->entr->bits_per_pixel,
									   &mlx->entr->line_length, &mlx->entr->endian);
//
//	mlx->entr->addr = mlx_get_data_addr(mlx->entr->img, &mlx->entr->bits_per_pixel,
//									   &mlx->entr->line_length, &mlx->entr->endian);
	mlx->entr->end_y -= 50;
	mlx->entr->start_y -= 50;
	if (mlx->entr->start_y < 0)
	{
		mlx->entr->end_y = 1100;
		mlx->entr->start_y = 1050;
	}
	draw_area(mlx, 0x9900FF00);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->entr->img, 0, 0);
}

void	do_key_a(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->entr->img);
	mlx->entr->img = mlx_new_image(mlx->mlx, 1900, 1100);
	mlx->entr->addr = mlx_get_data_addr(mlx->entr->img, &mlx->entr->bits_per_pixel,
									   &mlx->entr->line_length, &mlx->entr->endian);
//	mlx->entr->addr = mlx_get_data_addr(mlx->entr->img, &mlx->entr->bits_per_pixel,
//									   &mlx->entr->line_length, &mlx->entr->endian);
	mlx->entr->end_x -= 50;
	mlx->entr->start_x -= 50;
	if (mlx->entr->start_x < 0)
	{
		mlx->entr->end_x = 1900;
		mlx->entr->start_x = 1850;
	}
	draw_area(mlx, 0x9900FF00);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->entr->img, 0, 0);
}

void	do_key_s(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->entr->img);
	mlx->entr->img = mlx_new_image(mlx->mlx, 1900, 1100);
	mlx->entr->addr = mlx_get_data_addr(mlx->entr->img, &mlx->entr->bits_per_pixel,
									   &mlx->entr->line_length, &mlx->entr->endian);
//	mlx->entr->addr = mlx_get_data_addr(mlx->entr->img, &mlx->entr->bits_per_pixel,
//									   &mlx->entr->line_length, &mlx->entr->endian);
	mlx->entr->end_y += 50;
	mlx->entr->start_y += 50;
	if (mlx->entr->end_y > 1100)
	{
		mlx->entr->end_y = 50;
		mlx->entr->start_y = 0;
	}
	draw_area(mlx, 0x9900FF00);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->entr->img, 0, 0);
}

void	do_key_d(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->entr->img);
	mlx->entr->img = mlx_new_image(mlx->mlx, 1900, 1100);
	mlx->entr->addr = mlx_get_data_addr(mlx->entr->img, &mlx->entr->bits_per_pixel,
									   &mlx->entr->line_length, &mlx->entr->endian);
//	mlx->entr->addr = mlx_get_data_addr(mlx->entr->img, &mlx->entr->bits_per_pixel,
//									   &mlx->entr->line_length, &mlx->entr->endian);
	mlx->entr->end_x += 50;
	mlx->entr->start_x += 50;
	if (mlx->entr->end_x > 1900)
	{
		mlx->entr->end_x = 50;
		mlx->entr->start_x = 0;
	}
	draw_area(mlx, 0x9900FF00);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->entr->img, 0, 0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
//	printf("HERE\n");
//	printf("%d!\n", keycode);
//	mlx_clear_window(mlx->mlx, mlx->win);
	printf("%d,%d,%d,%d\n",mlx->entr->start_x, mlx->entr->start_y, mlx->entr->end_x, mlx->entr->end_y);
	if (keycode == 53)
		close_win();
//	if (keycode == 13)
//		do_key_w(mlx);
//	if (keycode == 0)
//		do_key_a(mlx);
//	if (keycode == 1)
//		do_key_s(mlx);
//	if (keycode == 2)
//		do_key_d(mlx);

	return (0);
}



/*
void	do_key_d(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->entr->img);
	mlx->entr->img = mlx_new_image(mlx->mlx, 1900, 1100);
	mlx->entr->addr = mlx_get_data_addr(mlx->entr->img, &mlx->entr->bits_per_pixel,
									   &mlx->entr->line_length, &mlx->entr->endian);
//	mlx->entr->addr = mlx_get_data_addr(mlx->entr->img, &mlx->entr->bits_per_pixel,
//									   &mlx->entr->line_length, &mlx->entr->endian);
	mlx->entr->end_x += 50;
	mlx->entr->start_x += 50;
	if (mlx->entr->end_x > 1900)
	{
		mlx->entr->end_x = 50;
		mlx->entr->start_x = 0;
	}
	draw_area(mlx, 0x9900FF00);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->entr->img, 0, 0);
}
 */