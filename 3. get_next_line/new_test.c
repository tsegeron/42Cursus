#include "get_next_line.h"

char	*get_left_str(char *full)
{
	char	*left;
	int		n;

	n = ft_strchr(full);
	left = ft_substr(full, n + 1, ft_strlen(full) - n);
	return (left);
}

char	*get_ret_str(char *full)
{
	char	*ret;

	ret = ft_substr(full, 0, ft_strchr(full) + 1);
	return (ret);
}

char	*get_full_str(char *left ,int fd)
{
	char	*full;
	char	*tmp;
	int 	check;
	int 	bytes_check;

	if (left && ft_strchr(left) != -1)
		return (left);
	bytes_check = 0;
	tmp = (char *)malloc (BUFFER_SIZE  + 1); /* ::::::::MALLOC:::::::: */
	if (!tmp)
		return (NULL);
	check = 0;
	while (read(fd, tmp, BUFFER_SIZE) > 0)
	{
		bytes_check = 1;
		if (!check++)
			full = ft_strdup(tmp);
		else
			full = ft_strjoin(full, tmp);
		if (ft_strchr(full) != -1)
			break ;
	}
		free (tmp);
	if (!bytes_check)
		return (NULL);
	if (left && ft_strchr(left) == -1)
		full = ft_strjoin(left, full);
	return (full);
}

char	*get_next_line(int fd)
{
//	char		*ret;
//	char		*full;
	static char	*left;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	left = get_full_str(left, fd);
	if (!left)
		return (left);
//	ret = get_ret_str(full);
//	left = get_left_str(full);
//	free (full);
//	printf("RET  :>%s", ret);
//	printf("LEFT :>%s", left);

	return (left);
}

int main(void)
{
	int fd;

	fd = open("test1", O_RDONLY);
	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
	//	printf("%s", get_next_line(fd));
	//	printf("%s", get_next_line(fd));
	close(fd);
	while (1);

}