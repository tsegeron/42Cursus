#include "get_next_line.h"

void	rec_left()
{
	static char	*left =

}

char	*get_next_line(int fd)
{
	char		*s;
	char		*buf;
	char		*ret;
	static char	*left = NULL;
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
		n = ft_strchr(buf, '\n');
		if (n != -1)
		{
			ret = ft_substr(buf, 0, n + 1); // CORRECT
			left = ft_substr(buf, n + 1, ft_strlen(buf) - n); // CORRECT
			break ;
		}
	}
	printf("RET  >%s", ret);
	printf("LEFT >%s", left);
//	printf("len  >%d\n", ft_strlen(buf));
//	printf("n  >%d\n", n);
	return (ret);
}

int main(void)
{
	int fd;

	fd = open("test1", O_RDONLY);
	get_next_line(fd);
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
	close(fd);
}