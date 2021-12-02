/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:41:09 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/02 06:41:09 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

static void	zero_map(t_map *map)
{
	map->width = 0;
	map->length = 0;
	map->count_entries = 0;
	map->count_exits = 0;
	map->count_coins = 0;
	map->count_enemies = 0;
}

static int	check_map_name(char *file_name)
{
	if (!ft_strnstr(file_name, ".ber", ft_strlen(file_name)))
		return (0);
	return (1);
}

int	read_map(char *file_name, t_map *map)
{
	zero_map(map);
	if (!check_map_name(file_name) || !count_map_dimensions(file_name, map))
		return (0);
	return (1);
}
