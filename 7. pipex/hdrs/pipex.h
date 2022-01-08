/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:19:43 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/08 20:16:11 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
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
	int		open_status;
	int		count_cmds;
	int		count_status;
	int		i;
	int		ac;
	int		end[2];
	pid_t	child1;
}	t_s;

t_s	g_s;

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void    ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void **src, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char *s, char c);
char	*get_next_line(int fd, int buf_size);

void	retrieve_path(char ***envp);
void	open_files(int *ac, char ***av);
void	read_std_input(char *limiter);
void	parse_commands(char ***av);
void	fork_and_exec(size_t i, char **envp);
void	error_exit(char *msg);

#endif //PIPEX_H
