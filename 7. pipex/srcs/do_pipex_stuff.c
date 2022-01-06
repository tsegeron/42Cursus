/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipex_stuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:07:56 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/06 22:07:56 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

static void	close_fds(size_t i, int status)
{
	if (!status)
	{
		while (i--)
		{
			close(g_s.cmds[i].in);
			close(g_s.cmds[i].out);
		}
	}
	else
	{
		close(g_s.cmds[i].in);
		close(g_s.cmds[i].out);
	}
}

static void	child_one(size_t i, char **envp)
{
	if (dup2(g_s.cmds[i].in, STDIN_FILENO) < 0
		|| dup2(g_s.cmds[i].out, STDOUT_FILENO) < 0)
		exit(5);
	close_fds(i, 0);
	execute_cmd(g_s.cmds[i].cmd, envp);
}

void	do_pipex_stuff(size_t i, char **envp)
{
	g_s.child1 = fork();
	if (g_s.child1 < 0)
		exit(5);
	if (!g_s.child1)
		child_one(i, envp);
	close_fds(i, 1);
	waitpid(g_s.child1, NULL, 0);
}
