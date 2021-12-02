#include "../hdrs/so_long.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img->addr + (y * mlx->img->line_length + x * (mlx->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mlx_stuff(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "Ducksuck!");
	mlx->img = malloc(sizeof(t_img));
	mlx->img->img = mlx_new_image(mlx->mlx, 1920, 1080);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->bits_per_pixel, &mlx->img->line_length,
									   &mlx->img->endian);
	my_mlx_pixel_put(mlx, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);

	return (1);
}
