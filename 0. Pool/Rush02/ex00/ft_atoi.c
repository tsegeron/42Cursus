long long int	ft_atoi(char *str)
{
	long long int	res;
	int				m;
	int				i;

	res = 0;
	m = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') || \
		   (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			m = -1 * m;
		i++;
	}
	while ((str[i] < 58) && (str[i] > 47))
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * m);
}
