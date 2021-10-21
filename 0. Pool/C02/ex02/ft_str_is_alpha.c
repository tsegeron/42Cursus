int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(str);
	while (str [i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			i++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			i++;
		else
			break ;
	}
	if (i == l)
		return (1);
	else
		return (0);
}