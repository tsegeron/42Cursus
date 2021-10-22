#include "get_next_line.h"

void	rec_lines(st *lst)
{

}

char	*get_next_line(int fd)
{
	static st	lst;
	char		*s;
	char		*buf;
	char		*ret;
	static int	st = 0;
	int 		check;
	int 		n;

	check = 0;
	s = (char *)malloc (sizeof(char) * BUFFER_SIZE + 1);
	ret = NULL;
	while (read(fd, s, BUFFER_SIZE))
	{
		if (!check++)
			buf = ft_strdup(s);
		else
			buf = ft_strjoin(buf, s);
		st++;
		n = ft_strchr(buf, '\n');
		if (n != -1)
		{
			ret = ft_substr(buf, 0, n + 1);
			break ;
		}
	}

	rec_lines(&lst);


	return (ret);
}

int main(void)
{
	int fd;

	fd = open("test1", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}