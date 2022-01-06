/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:47:23 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/06 22:47:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

void	parse_commands(char ***av)
{
	int	i;

	g_s.i = 0;
	i = 1;
	if (g_s.open_status)
	{
		if (g_s.open_status == 1)
			g_s.cmds[0].in = open((*av)[1], O_RDONLY);
		else
			g_s.cmds[0].in = open("her_doc", O_RDONLY);
		i++;
	}
	while (++g_s.i < g_s.count_cmds)
	{
		if (pipe(g_s.end) < 0)
			exit(4);
		g_s.cmds[g_s.i - 1].cmd = ft_split((*av)[i++ + 1], ' ');
		if (!g_s.cmds[g_s.i - 1].cmd)
			exit(4);
		g_s.cmds[g_s.i - 1].out = g_s.end[1];
		g_s.cmds[g_s.i].in = g_s.end[0];
	}
	g_s.cmds[g_s.i - 1].cmd = ft_split((*av)[i + 1], ' ');
	if (!g_s.cmds[g_s.i - 1].cmd || g_s.cmds[0].in < 0)
		exit(4);
}
