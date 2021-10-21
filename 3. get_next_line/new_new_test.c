#include "get_next_line.h"

char	*get_left_str(char *full)
{
	char	*left;
	int		n;
//	int		i;
//	int		j;
//	int		end;
//
//	i = 0;
	n = ft_strchr(full);
//	j = ft_strlen(full) - n - 1;
	left = ft_substr(full, n + 1, ft_strlen(full) - n);

//	while (j != ft_strlen(full) - 1)
//		left[i++] = full[j++];

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
	tmp = (char *)malloc (BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	check = 0;
	while (read(fd, tmp, BUFFER_SIZE) > 0)
	{
		bytes_check = 1;
		if (!check++)
			full = ft_strdup(tmp);
		else
		{
//			free (full);
			full = ft_strjoin(full, tmp);
		}
//			free (tmp);
		if (ft_strchr(full) != -1)
			break ;
	}
	if (!bytes_check)
	{
//		free(tmp);
		return (NULL);
	}
	if (left && ft_strchr(left) == -1)
		full = ft_strjoin(left, full);
	return (full);
}

char	*get_next_line(int fd)
{
	char		*ret;
	char		*full;
	static char	*left;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	full = get_full_str(left, fd);
	if (!full)
		return (NULL);
	ret = get_ret_str(full);
	left = get_left_str(full);
	free (full);
	//	printf("RET  :>%s", ret);
	//	printf("LEFT :>%s", left);

	return (ret);
}

int main(void)
{
	int fd;

	fd = open("test1", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	//	printf("%s", get_next_line(fd));
	//	printf("%s", get_next_line(fd));
	close(fd);
	while (1);

}