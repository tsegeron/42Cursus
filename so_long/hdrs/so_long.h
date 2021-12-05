#ifndef SO_LONG_H
#define SO_LONG_H

# include "mlx.h"
# include "libft.h"

//# define WALL
//# define SPACE
//# define COIN
//# define ENEMY
//# define HERO
//# define EXIT

typedef struct s_hero
{
	int		x; // hero_x coordinates
	int		y; // hero_y coordinates
}	t_hero;

typedef struct s_img
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_img;

typedef struct s_mlx
{
	t_img	*wall;
	t_img	*back1;
	t_img	*back2;
	t_img	*entr;
	t_img	*exit;
	t_img	*hero1;
	t_img	*hero2;
	t_img	*enem1;
	t_img	*enem2;
	t_img	*coin1;
	t_img	*coin2;
	void	*mlx;
	void	*win;
	int		anim_state;

}	t_mlx;

typedef struct s_map
{
	t_hero	*hero;
	t_hero	*exit;
	t_list	*coin;
	t_list	*enem;
	t_mlx	*mlx;
	char	**data;
	int 	width;
	int 	length;
	int 	random;
	int 	count_entries;
	int 	count_exits;
	int 	count_coins;
	int 	count_enemies;
	int		moves_count;
}	t_map;








int		read_map(char *file_name, t_map *map);
int		count_map_dimensions(char *file_name, t_map *map);
int		check_symbols(t_map *map);
int		clean_map(t_map *map);
int		mlx_stuff(t_map *map);
int		do_keys(int keycode, t_map *map);
int		close_win(void);
void	draw_map(t_map *map);
void	draw_objects(t_map *map);
void	start_game(t_map *map);
void	make_enem_move(t_map *map);
void	game_lost(t_map *map);
void	game_won(t_map *map);





#endif //SO_LONG_H
