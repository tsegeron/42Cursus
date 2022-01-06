/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:10:34 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/06 23:03:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

void	free_path(void)
{
	int	i;

	i = 0;
	while (g_s.path[i])
		i++;
	while (i--)
		free(g_s.path[i]);
	free(g_s.path);
	g_s.path = NULL;
	exit(2);
}

int	find_path_index(char ***envp)
{
	int	i;

	i = -1;
	while (ft_strncmp((*envp)[++i], "PATH", 4))
		;
	return (i);
}

void	retrieve_path(char ***envp)
{
	int	i;

	g_s.path = ft_split((*envp)[find_path_index(envp)] + 5, ':');
	if (!g_s.path)
		exit (2);
	i = -1;
	while (g_s.path[++i])
	{
		g_s.path[i] = ft_strjoin(g_s.path[i], "/");
		if (!g_s.path[i])
			return (free_path());
	}
}
