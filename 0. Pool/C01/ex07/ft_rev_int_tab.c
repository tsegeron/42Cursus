void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = size - 1;
	while (tab[i] != j)
	{
		c = tab[i];
		tab[i] = tab[j];
		tab[j] = c;
		i++;
		j--;
	}
}
