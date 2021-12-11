/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:41:09 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/10 16:03:35 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long_b.h"

static void	zero_map(t_map *map)
{
	map->width = 0;
	map->length = 0;
	map->count_entries = 0;
	map->count_exits = 0;
	map->count_coins = 0;
	map->count_enemies = 0;
	map->moves_count = 0;
	map->close_state = 0;
}

static int	check_map_name(char *file_name)
{
	if (ft_strlen(file_name) < 10)
		return (0);
	if (!ft_strnstr(file_name + ft_strlen(file_name) - 4, ".ber", 4))
		return (0);
	return (1);
}

static void	do_actual_setting(int i, int j, char ch, t_map *map)
{
	static int	c = 1;
	static int	x = 1;
	static int	e = 1;

	if (c == 1)
		map->coin = NULL;
	if (x == 1)
		map->enem = NULL;
	if (e == 1)
		map->exit = NULL;
	if (ch == 'P')
	{
		map->hero->x = j;
		map->hero->y = i;
	}
	else if (ch == 'E')
		ft_lstadd_back(&map->exit, ft_lstnew(e++, j, i));
	else if (ch == 'C')
		ft_lstadd_back(&map->coin, ft_lstnew(c++, j, i));
	else if (ch == 'X')
	{
		if (!BONUS)
			exit(printf("Try to launch Bonus for playing with enemies\n"));
		ft_lstadd_back(&map->enem, ft_lstnew(x++, j, i));
	}
}

static void	set_objs_pos(t_map *map)
{
	int	i;
	int	j;

	map->hero = malloc(sizeof(t_hero));
	map->exit = malloc(sizeof(t_hero));
	i = -1;
	while (++i < map->length)
	{
		j = -1;
		while (++j < map->width)
			do_actual_setting(i, j, map->data[i][j], map);
	}
}

int	read_map(char *file_name, t_map *map)
{
	zero_map(map);
	if (!check_map_name(file_name) || !count_map_dimensions(file_name, map))
		return (0);
	set_objs_pos(map);
	return (1);
}
