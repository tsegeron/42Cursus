/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:26:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/09 14:24:42 by gernesto         ###   ########.fr       */
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

static void	find_path(char *act_cmd, char **cmd)
{
	int		i;

	i = -1;
	while (g_s.path[++i])
	{
		if (!act_cmd)
			break ;
		*cmd = ft_strjoin(g_s.path[i], act_cmd);
		if (!*cmd)
			exit((int )write(2, "Malloc error\n", 13));
		if (!access(*cmd, F_OK))
			return ;
		free (*cmd);
	}
	*cmd = NULL;
	if (!g_s.path[i] || !act_cmd)
		exit((int )write(2, "No such cmd\n", 12));
}

static void	execute_cmd(char **cmd, char **envp)
{
	char	*cmd_path;

	find_path(cmd[0], &cmd_path);
	execve(cmd_path, cmd, envp);
	free (cmd_path);
	exit(99);
}

static void	child_one(size_t i, char **envp)
{
	if (dup2(g_s.cmds[i].in, STDIN_FILENO) < 0
		|| dup2(g_s.cmds[i].out, STDOUT_FILENO) < 0)
		error_exit(NULL);
	close_fds(i, 0);
	execute_cmd(g_s.cmds[i].cmd, envp);
}

void	fork_and_exec(size_t i, char **envp)
{
	g_s.child1 = fork();
	if (g_s.child1 < 0)
		exit(5);
	if (!g_s.child1)
		child_one(i, envp);
	close_fds(i, 1);
}
