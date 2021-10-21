#include <unistd.h>

void	ft_is_negative(int n)
{
	char	a[2];

	a[0] = 'N';
	a[1] = 'P';
	if (n < 0)
	{
		write (1, &a[0], 1);
	}
	else if (n >= 0)
	{
		write (1, &a[1], 1);
	}
}
