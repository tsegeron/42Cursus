/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:43:46 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/02 06:44:29 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long_b.h"

int	clean_map(t_map *map)
{
	while (map->length > -1)
	{
		free(map->data[map->length]);
		map->data[map->length--] = NULL;
	}
	free(map->data);
	map->data = NULL;
	return (0);
}

static int	check_sym(char c, t_map *map)
{
	if (c == '1' || c == '0')
		return (1);
	if (c == 'P' || c == 'E' || c == 'C' || c == 'X')
	{
		if (c == 'P')
			map->count_entries++;
		if (c == 'E')
			map->count_exits++;
		if (c == 'C')
			map->count_coins++;
		if (c == 'X')
			map->count_enemies++;
		return (1);
	}
	return (0);
}

int	check_symbols(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (++j < map->length - 1)
	{
		i = 0;
		while (++i < map->width - 1)
			if (!check_sym(map->data[j][i], map))
				return (0);
	}
	if (map->count_entries != 1 || !map->count_exits || !map->count_coins)
		return (0);
	return (1);
}
