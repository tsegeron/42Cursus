/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:10:34 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/28 10:32:07 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

void	free_path(void)
{
	int	i;

	i = 0;
	while (s.path[i])
		i++;
	while (i--)
		free(s.path[i]);
	free(s.path);
	s.path = NULL;
}

void	retrieve_path(char ***av, char ***envp)
{
	int	i;

	s.path = ft_split((*envp)[0] + 5, ':');
	if (!s.path)
		return (perror("Error"));
	i = -1;
	while (s.path[++i])
	{
		s.path[i] = ft_strjoin(s.path[i], "/");
		if (!s.path[i])
			return (free_path());
	}
}
