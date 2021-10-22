#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		*s = (char *)malloc (sizeof(char) * BUFFER_SIZE + 1);

	read(fd, s, BUFFER_SIZE);
	return (s);
}

int main(void)
{
	int fd;

	fd = open("test1", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
}