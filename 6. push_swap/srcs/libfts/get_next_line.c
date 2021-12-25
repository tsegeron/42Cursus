/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:27:06 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/25 22:49:44 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/push_swap.h"

static char	*ft_strjoin_for_gnl(char *s1, char *s2)
{
	char	*joint;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *) malloc (1);
		s1[0] = '\0';
	}
	joint = (char *) malloc ((ft_strlen(s1)
				+ ft_strlen(s2)) * sizeof(char) + 1);
	if (!joint)
		return (NULL);
	while (s1[++i] != '\0')
		joint[i] = s1[i];
	while (s2[j] != '\0')
		joint[i++] = s2[j++];
	joint[i] = '\0';
	free (s1);
	return (joint);
}

char	*get_left_str(char *full)
{
	char	*left;
	int		i;
	int		j;

	i = 0;
	while (full[i] != '\n' && full[i])
		i++;
	if (full[i] == '\0')
	{
		free (full);
		return (NULL);
	}
	i++;
	left = (char *) malloc (sizeof(char) * ft_strlen(&full[i]) + 1);
	if (!left)
		return (NULL);
	j = 0;
	while (full[i])
		left[j++] = full[i++];
	left[j] = '\0';
	free (full);
	return (left);
}

char	*get_ret_str(char *full)
{
	char	*ret;
	int		i;

	if (full[0] == '\0')
		return (NULL);
	i = 0;
	while (full[i] != '\n' && full[i])
		i++;
	ret = (char *) malloc (sizeof(char) * i + 2);
	if (!ret)
		return (NULL);
	i = 0;
	while (full[i] != '\n' && full[i])
	{
		ret[i] = full[i];
		i++;
	}
	if (full[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*get_full_str(char *left, int fd, int buf_size)
{
	char	*tmp;
	int		bytes_check;

	tmp = (char *)malloc(buf_size + 1);
	if (!tmp)
		return (NULL);
	bytes_check = 1;
	while (bytes_check != 0 && !ft_strchr(left, '\n'))
	{
		bytes_check = read(fd, tmp, buf_size);
		if (bytes_check < 0)
		{
			free (tmp);
			return (NULL);
		}
		tmp[bytes_check] = '\0';
		left = ft_strjoin_for_gnl(left, tmp);
	}
	free (tmp);
	return (left);
}

char	*get_next_line(int fd, int buf_size)
{
	static char	*left;
	char		*ret;

	if (fd < 0 || buf_size < 1)
		return (NULL);
	left = get_full_str(left, fd, buf_size);
	if (!left)
		return (left);
	ret = get_ret_str(left);
	left = get_left_str(left);
	return (ret);
}
/*
int main(void)
{
	int		fd;
	int		rep = 2;
	//	char	*res;

	fd = open("test_text", O_RDONLY);
	while (rep--)
		printf("%s", get_next_line(fd));

	printf("\n");

	rep = 2;
	fd = open("test_empty", O_RDONLY);
	while (rep--)
		printf("%s", get_next_line(fd));

	printf("\n");

	rep = 2;
	fd = open("test_rights", O_RDONLY);
	while (rep--)
		printf("%s", get_next_line(fd));



	//	while (rep--)
	//	{
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//		printf("%s", get_next_line(fd));
	//		printf("%s", get_next_line(fd));
	//		printf("%s", get_next_line(fd));
	//		printf("%s", get_next_line(fd));
	//	}
	close(fd);
	//	while (1);

}
*/