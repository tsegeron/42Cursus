int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(str);
	while (str [i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			break ;
	}
	if (i == l)
		return (1);
	else
		return (0);
}
