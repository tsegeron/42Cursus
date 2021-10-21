int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	l;
	insigned int	ls;

	i = 0;
	l = ft_strlen(dest);
	ls = ft_strlen(src);
	while (n <= ls ? i != n : i != ls)
	{
		dest[i] = src[i];
		i++;
	}
	if (ls < l && ls < n)
	{
		while (i != l)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}
