unsigned int	ft_strlen(char *dest)
{
	unsigned int	l;

	l = 0;
	while (dest[l] != '\0')
		l++;
	return (l);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	return (dest);
}
