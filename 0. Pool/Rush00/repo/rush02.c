void	ft_putchar (char c);

void	rush51 (unsigned int l)
{
	ft_putchar('A');
	while (l > 2)
	{
		ft_putchar('B');
		l--;
	}
	ft_putchar('A');
}

void	rush15 (unsigned int h)
{
	ft_putchar('A');
	ft_putchar('\n');
	while (h > 2)
	{
		ft_putchar('B');
		ft_putchar('\n');
		h--;
	}
	ft_putchar('C');
}

void	rush1__1 (unsigned int l, unsigned int h, unsigned int x)
{
	while (h > 2)
	{
		ft_putchar('B');
		while (l > 2)
		{
			ft_putchar(' ');
			l--;
		}
		ft_putchar('B');
		ft_putchar('\n');
		l = x;
		h--;
	}
}

void	rushLastStr (unsigned int l)
{
	ft_putchar('C');
	while (l > 2)
	{
		ft_putchar('B');
		l--;
	}
	ft_putchar('C');
}

void	rush(unsigned int x, unsigned int y)
{
	unsigned int	l;
	unsigned int	h;

	l = x;
	h = y;
	if ((l == 1) && (h == 1))
		ft_putchar('A');
	else if ((l > 1) && (h == 1))
		rush51(l);
	else if ((l == 1) && (h > 1))
		rush15(h);
	else if ((l > 1) && (h > 1))
	{
		rush51(l);
		ft_putchar('\n');
		l = x;
		rush1__1(l, h, x);
		l = x;
		h = y;
		rushLastStr (l);
	}
}
