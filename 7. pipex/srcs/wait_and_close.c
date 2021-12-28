#include "../hdrs/pipex.h"

static t_cmds	*find_executed(pid_t proccess)
{
	int	i;

	i = -1;
	while (++i < s.count_cmds)
		if (proccess == s.family[i])
			return (&s.cmds[i]);
	return (NULL);
}

void	wait_and_close(void)
{
	t_cmds	*executed;
	pid_t	process;
	int		i;

	i = -1;
	while (++i < s.count_cmds)
	{
		process = wait(NULL);
		if (process == -1)
			exit(1);
		executed = find_executed(process);
		if (executed->in != 0)
			close(executed->in);
		if (executed->out != 1)
			close(executed->out);
	}

}
