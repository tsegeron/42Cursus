/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_std_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:28:41 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/07 19:28:41 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

void	read_std_input(char *limiter)
{
	char	*line;
	char	*lim;

	lim = malloc(sizeof(char) * (ft_strlen(limiter) + 2));
	if (!lim)
		error_exit(NULL);
	ft_memmove(lim, limiter, ft_strlen(limiter));
	lim[ft_strlen(limiter)] = '\n';
	lim[ft_strlen(limiter) + 1] = '\0';
	line = NULL;
	while (ft_strcmp(line, lim))
	{
		if (line)
			free(line);
		line = get_next_line(0, 1);
		if (!line)
			break ;
		if (ft_strcmp(line, lim))
			write(g_s.cmds[0].in, line, ft_strlen(line));
	}
	if (line)
		free(line);
	free(lim);
	close(g_s.cmds[0].in);
}
