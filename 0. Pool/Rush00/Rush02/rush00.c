void	ft_putchar (char c);

void	rush51 (unsigned int l)
{
	ft_putchar('o');
	while (l > 2)
	{
		ft_putchar('-');
		l--;
	}
	ft_putchar('o');
}

void	rush15 (int h)
{
	ft_putchar('o');
	ft_putchar('\n');
	while (h > 2)
	{
		ft_putchar('|');
		ft_putchar('\n');
		h--;
	}
	ft_putchar('o');
}

void	rush1__1 (unsigned int l, unsigned int h, unsigned int x)
{
	while (h > 2)
	{
		ft_putchar('|');
		while (l > 2)
		{
			ft_putchar(' ');
			l--;
		}
		ft_putchar('|');
		ft_putchar('\n');
		l = x;
		h--;
	}
}

void	rush(unsigned int x, unsigned int y)
{
	unsigned int	l;
	unsigned int	h;

	l = x;
	h = y;
	if ((l == 1) && (h == 1))
		ft_putchar('o');
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
		rush51 (l);
	}
}
