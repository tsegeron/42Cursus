/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:08:29 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/06 22:08:29 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

static void	find_path(char *act_cmd, char **cmd)
{
	int		i;

	i = -1;
	while (g_s.path[++i])
	{
		*cmd = ft_strjoin(g_s.path[i], act_cmd);
		if (!*cmd)
			exit((int )write(2, "Malloc error\n", 13));
		if (!access(*cmd, F_OK))
			return ;
		free (*cmd);
	}
	*cmd = NULL;
	if (!g_s.path[i])
		exit((int )write(2, "No such cmd\n", 12));
}

void	execute_cmd(char **cmd, char **envp)
{
	char	*cmd_path;

	find_path(cmd[0], &cmd_path);
	execve(cmd_path, cmd, envp);
	free (cmd_path);
	exit(99);
}
