#ifndef SO_LONG_H
#define SO_LONG_H

# include "mlx.h"
# include "../libft/libft.h"

//# define WALL
//# define SPACE
//# define COIN
//# define ENEMY
//# define HERO
//# define EXIT

typedef struct s_map
{
	char	**data;
	int 	width;
	int 	length;
	int 	count_entries;
	int 	count_exits;
	int 	count_coins;
	int 	count_enemies;
}	t_map;



typedef struct s_img
{
	void	*img;
	void	*img1;
	char	*path;
	int		width;
	int		height;

	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int 	start_x;
	int 	start_y;
	int 	end_x;
	int 	end_y;
}	t_img;



typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*entr;
	t_img	*exit;
	t_img	*hero;
	t_img	*enem;
	t_img	*coin;
}	t_mlx;




int		read_map(char *file_name, t_map *map);
int		count_map_dimensions(char *file_name, t_map *map);
int		check_symbols(t_map *map);
int		clean_map(t_map *map);
int		mlx_stuff(t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
int		close_win(void);
void	draw_area(t_mlx *mlx, int color);






#endif //SO_LONG_H
