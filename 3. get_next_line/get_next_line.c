#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*s1;
	char	*s2;
	int		i;
	int		buf = BUFFER_SIZE;
	size_t	len;
	static int	pr = 0;
//	char	c;

	i = 0;
	if (fd < 0 || buf <= 0)
		return (NULL);
	s1 = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!s1)
		return (NULL);
	read(fd, s1, BUFFER_SIZE);
	s1[BUFFER_SIZE] = '\0';
	len = ft_strlen(s1);
	while (i != len && s1[i] != '\n')
		i++;

	if (i == len)
	{
		s2 = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
		if (!s2)
			return (NULL);
		read(fd, s2, BUFFER_SIZE);
		s2[BUFFER_SIZE] = '\0';
		ft_strjoin(s1, s2);
	}
//	else
//	{
//
//	}









//	while (read(fd, s1, BUFFER_SIZE))
//	{
//
//	}

//	pr = ft_strlen(s1);
	printf("%s1\n", s1);
	printf("%s2\n", s2);

	return (s1);
}
