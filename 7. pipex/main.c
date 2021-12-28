#include "hdrs/pipex.h"

void	free_cmd(char ***cmd)
{
	int	i;

	i = 0;
	while ((*cmd)[i])
		i++;
	while (i--)
		free((*cmd)[i]);
	free(*cmd);
	*cmd = NULL;
}

void	free_everything(void)
{
	int i;

	free_path();
	i = -1;
	if (s.cmds)
	{
		while (++i < s.count_cmds)
		{
			if (s.cmds[i].cmd)
				free_cmd(&s.cmds[i].cmd);
			if (s.cmds[i].in != 0 && s.cmds[i].in != 1)
				close(s.cmds[i].in);
			if (s.cmds[i].out != 0 && s.cmds[i].out != 1)
				close(s.cmds[i].out);
		}
		free(s.cmds);
		s.cmds = NULL;
	}
	if (s.family)
	{
		free(s.family);
		s.family = NULL;
	}
}

int main(int ac, char *av[], char *envp[])
{
	if (ac < 5)
		return ((int )write(2, "Usage: ./pipex infile \"cmd1\" \"cmd2\" ... \"cmdn\" outfile\n", 55));

	s.count_cmds = ac - 3;
	if (!ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")))
	{
		if (ac < 6)
			return ((int )write(2, "Usage: ./pipex here_doc LIMITER \"cmd1\" \"cmd2\" ... \"cmdn\" outfile\n", 65));

		s.count_cmds--;
	}
	retrieve_path(&av, &envp);
	parse_commands(ac, &av);
//	printf("%s",s.cmds[1].cmd[0]);
	printf("%d ",s.cmds[3].in);
	printf("%d ",s.cmds[3].out);
//	fork_and_exec(envp);
//	wait_and_close();
	free_everything();
	return (0);
}
