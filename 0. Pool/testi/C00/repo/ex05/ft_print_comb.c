#include <unistd.h>

void	ft_putchar (char c)
{
	write (1, &c, 1);
}

void	shownums (char a, char b, char c)
{
	ft_putchar (a);
	ft_putchar (b);
	ft_putchar (c);
	if (!(a == '7' && b == '8' && c == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
		write (1, "\n", 1);
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				shownums (a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
