#include "../hdrs/pipex.h"

static void	find_path(char *act_cmd, char **cmd)
{
	int		i;

	i = -1;
	while (s.path[++i])
	{
		*cmd = ft_strjoin(s.path[i], act_cmd);
		if (!*cmd)
			exit((int )write(2, "Malloc error\n", 13));
		if (!access(*cmd, F_OK))
			return ;
		free (*cmd);
	}
	*cmd = NULL;
	if (!s.path[i])
		exit((int )write(2, "No such cmd\n", 12));
}

static void	close_fds(void)
{
	int	i;

	i = -1;
	while (++i < s.count_cmds)
	{
		if (s.cmds[i].in != STDIN_FILENO)
			close(s.cmds[i].in);
		if (s.cmds[i].out != STDOUT_FILENO)
			close(s.cmds[i].out);
	}
}

static void	execute_cmd(t_cmds *cmds, char **envp)
{
	char	*cmd_path;

	if (dup2(cmds->in, STDIN_FILENO) < 0 || dup2(cmds->out, STDOUT_FILENO) < 0)
		exit((int )write(2, "Dup2 error\n", 11));
	close_fds();
	find_path(cmds->cmd[0], &cmd_path);
	execve(cmd_path, cmds->cmd, envp);
	free (cmd_path);
}

void	fork_and_exec(char *envp[])
{
	int		i;

	s.family = (pid_t *) malloc (sizeof(pid_t) * s.count_cmds);

	i = -1;
	while (++i < s.count_cmds)
	{
		s.family[i] = fork();
		if (s.family[i] == -1)
			exit((int )write(2, "Fork1 error\n", 12));
		if (s.family[i] == 0)
		{
			if (!s.cmds[i].cmd)
				exit(0);
			execute_cmd(&s.cmds[i], envp);
		}
	}
}
