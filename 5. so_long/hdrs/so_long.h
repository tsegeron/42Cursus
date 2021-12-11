/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:56:14 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/09 11:22:24 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "libft.h"

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_hero
{
	int	x;
	int	y;
}	t_hero;

typedef struct s_img
{
	void	*img;
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
	t_list	*exit;
	t_list	*coin;
	t_list	*enem;
	t_mlx	*mlx;
	char	**data;
	int		width;
	int		length;
	int		random;
	int		count_entries;
	int		count_exits;
	int		count_coins;
	int		count_enemies;
	int		moves_count;
	int		close_state;
}	t_map;

int		read_map(char *file_name, t_map *map);
int		count_map_dimensions(char *file_name, t_map *map);
int		check_symbols(t_map *map);
int		clean_map(t_map *map);
int		mlx_stuff(t_map *map);
int		do_keys(int keycode, t_map *map);
int		close_win(void);
int		check_pos(t_map *map, int pos, int x, int y);
void	start_game(t_map *map);
void	draw_map(t_map *map);
void	draw_objects(t_map *map);
void	make_enem_move(t_map *map);
void	game_won(t_map *map);
void	game_lost(t_map *map);
void	show_move_count(t_map *map);
void	del_coin(t_map *map);

#endif //SO_LONG_H
