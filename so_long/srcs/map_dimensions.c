/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 06:42:51 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/02 06:43:33 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

/*
 * 	counts the number of symbols
 * 	in the 1 line to use then as
 * 	buf_size for get_next_line
 */
static int	count_width(char *file_name, t_map *map)
{
	char	c;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		map->width++;
	}
	if (map->width < 3)
		return (0);
	close (fd);
	return (1);
}

/*
 * 	counts the number of lines,
 * 	parses the map
 */
static int	parse_map(char *file_name, t_map *map)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	map->data = malloc(sizeof (char *) * (map->length + 1));
	map->data[map->length] = get_next_line(fd, map->width);
	while (map->data[map->length])
	{
		(map->length)++;
		map->data = ft_realloc((void *)&map->data,
				sizeof(char *) * (map->length + 1));
		map->data[map->length] = get_next_line(fd, map->width);
	}
	close(fd);
	if (map->length < 3)
	{
		clean_map(map);
		return (0);
	}
	return (1);
}

static int	check_lines_len(t_map *map)
{
	size_t	line_len;
	int		i;

	i = 0;
	line_len = ft_strlen(map->data[i]);
	while (i < map->length - 2)
		if (line_len != ft_strlen(map->data[++i]))
			return (0);
	if (line_len - 1 != ft_strlen(map->data[++i]))
		return (0);
	return (1);
}

static int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < map->width)
		if (map->data[0][i] != '1')
			return (0);
	i = -1;
	while (++i < map->width)
		if (map->data[map->length - 1][i] != '1')
			return (0);
	while (++j < map->length - 1)
		if (map->data[j][0] != '1' || map->data[j][map->width - 1] != '1')
			return (0);
	return (1);
}

int	count_map_dimensions(char *file_name, t_map *map)
{
	if (!count_width(file_name, map))
		return (0);
	if (!parse_map(file_name, map))
		return (0);
	if (!check_lines_len(map) || !check_walls(map) || !check_symbols(map))
		return (clean_map(map));
	return (1);
}
