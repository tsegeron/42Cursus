long long int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

long long int	check_operator(char *operator)
{
	if (ft_strlen(operator) > 1)
		return (0);
	if (operator[0] == '+')
		return (1);
	if (operator[0] == '-')
		return (2);
	if (operator[0] == '/')
		return (3);
	if (operator[0] == '*')
		return (4);
	if (operator[0] == '%')
		return (5);
	else
		return (0);
}
