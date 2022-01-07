/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:07:29 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/07 20:17:24 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/pipex.h"

void	error_exit(char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	else
		perror("Error");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av, char **envp)
{
	int	i;

	g_s.ac = ac;
	if (ac < 3)
		error_exit("Usage: ./pipex infile "
			"\"cmd1\" \"cmd2\" ... \"cmdn\" outfile\n");
	retrieve_path(&envp);
	open_files(&ac, &av);
	if (!ft_strcmp(av[1], "here_doc"))
		read_std_input(av[2]);
	parse_commands(&av);
	i = -1;
	while (++i < g_s.count_cmds)
		fork_and_exec(i, envp);
	while (i--)
		wait(NULL);
	if (g_s.open_status == 1)
		unlink("here_doc");
	else if (g_s.open_status == 2)
		unlink("her_doc");
	return (0);
}
