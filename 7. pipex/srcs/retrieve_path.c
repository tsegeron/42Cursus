/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:10:34 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/07 16:05:32 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

static void	find_path_index(int *j, char ***envp)
{
	if (!(*envp))
		error_exit("Error: env not found\n");
	*j = -1;
	while ((*envp)[++(*j)] && ft_strncmp((*envp)[*j], "PATH", 4))
		;
	if (!(*envp)[*j])
		error_exit("Error: PATH not found\n");
}

void	retrieve_path(char ***envp)
{
	int	i;
	int	j;

	find_path_index(&j, envp);
	g_s.path = ft_split((*envp)[j] + 5, ':');
	if (!g_s.path)
		error_exit("Error: malloc\n");
	i = -1;
	while (g_s.path[++i])
	{
		g_s.path[i] = ft_strjoin(g_s.path[i], "/");
		if (!g_s.path[i])
			error_exit("Error: malloc\n");
	}
}
