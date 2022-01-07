/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:07:29 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/07 11:30:36 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	size_t	i;

	g_s.ac = ac;
	if (ac < 5)
		return ((int )write(2, "Usage: ./pipex infile"
				"\"cmd1\" \"cmd2\" ... \"cmdn\" outfile\n", 55));
	open_stuff(&ac, &av);
	retrieve_path(&envp);
	if (!ft_strcmp(av[1], "here_doc"))
		read_input(av[2]);
	parse_commands(&av);
	i = -1;
	while (++i < g_s.count_cmds)
		do_pipex_stuff(i, envp);
	if (g_s.open_status == 1)
		unlink("here_doc");
	else if (g_s.open_status == 2)
		unlink("her_doc");
	return (0);
}
