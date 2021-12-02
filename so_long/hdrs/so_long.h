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
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;



typedef struct s_mlx
{
	t_img	*img;
	void	*mlx;
	void	*win;
}	t_mlx;




//int		ft_strlen(const char *str);
//char	*ft_substr(char *s, int start, int len);
//char	*ft_strjoin(char *s1, char *s2);
//char	*ft_strdup(char *src);
//char	*ft_strchr(char *s, char c);
//char	*get_next_line(int fd, int buf_size);

int		read_map(char *file_name, t_map *map);
int		count_map_dimensions(char *file_name, t_map *map);
int		check_symbols(t_map *map);
int		clean_map(t_map *map);
int		mlx_stuff(t_mlx *mlx);







#endif //SO_LONG_H
