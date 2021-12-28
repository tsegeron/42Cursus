/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:19:43 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/28 10:45:49 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>	/* waitpid */
# include <stdio.h>

typedef struct s_list
{
	char			**cmd;
	int				in;
	int				out;
}	t_cmds;

typedef struct s
{
	char	**path;
	t_cmds	*cmds;
	pid_t	*family;
	int		count_cmds;
}	t_s;

t_s	s;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);

void	free_path(void);
void	retrieve_path(char ***av, char ***envp);
void	parse_commands(int ac, char ***av);
void	fork_and_exec(char *envp[]);
void	wait_and_close(void);

#endif //PIPEX_H
