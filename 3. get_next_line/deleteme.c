#include "get_next_line.h"

char *fttest(void)
{
	static char	*s;

	return (s);
}

int main()
{
	printf("%s\n", fttest());
}
