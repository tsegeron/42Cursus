#include "../so_long.h"

int	check_map()
{
	char	**lines;
	int		count;
	int		fd;
	int		i;
	char	c;


	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		write (2, "map error\n", 10);

	i = -1;
	count = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			count++;
	}
	lines = (char **) malloc(sizeof(char *) * count);
	if (!lines)
		return (-1);
	while (++i < count)
		lines[i] = get_next_line(fd);


}
