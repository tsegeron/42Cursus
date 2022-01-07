/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:28:31 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/07 19:28:31 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

static void	init_stuff(int *ac, char ***av)
{
	g_s.ac = *ac;
	g_s.count_cmds = (*ac) - 3;
	g_s.open_status = 0;
	g_s.count_status = 0;
	if (!ft_strcmp((*av)[1], "here_doc"))
	{
		g_s.count_cmds--;
		g_s.open_status++;
	}
	if (g_s.count_cmds == 0)
	{
		g_s.count_cmds = 1;
		g_s.count_status = 1;
	}
	g_s.cmds = ft_calloc(sizeof(t_cmds), g_s.count_cmds);
	if (!g_s.cmds)
		error_exit("Error: malloc\n");
}

void	open_files(int *ac, char ***av)
{
	init_stuff(ac, av);
	if (!g_s.open_status)
	{
		g_s.cmds[0].in = open((*av)[1], O_RDONLY);
		if (g_s.cmds[0].in < 0)
			error_exit(NULL);
		g_s.cmds[g_s.count_cmds - 1].out = open((*av)[g_s.ac - 1],
				O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	else
	{
		if (ft_strcmp("here_doc", (*av)[g_s.ac - 1]))
			g_s.cmds[0].in = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
		else
		{
			g_s.cmds[0].in = open("her_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
			g_s.open_status++;
		}
		if (g_s.cmds[0].in < 0)
			error_exit(NULL);
		g_s.cmds[g_s.count_cmds - 1].out = open((*av)[g_s.ac - 1],
				O_CREAT | O_RDWR | O_APPEND, 0644);
	}
	if (g_s.cmds[g_s.count_cmds - 1].out < 0)
		error_exit(NULL);
}
