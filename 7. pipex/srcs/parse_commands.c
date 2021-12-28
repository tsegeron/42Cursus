#include "../hdrs/pipex.h"

void	parse_commands(int ac, char ***av)
{
	int	i;
	int	ends[2];

	s.cmds = ft_calloc(sizeof(t_cmds), s.count_cmds);
	s.cmds[0].in = open((*av)[1], O_RDONLY); // DEF
	s.cmds[s.count_cmds - 1].out = open((*av)[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644); // DEF

	i = 0;
	while (++i < s.count_cmds)
	{
		if (pipe(ends) < 0)
			return (perror("Error")); // RETURN
		s.cmds[i - 1].cmd = ft_split((*av)[i + 1], ' '); // DEF
		s.cmds[i - 1].out = ends[1];
		s.cmds[i].in = ends[0];
	}
}
