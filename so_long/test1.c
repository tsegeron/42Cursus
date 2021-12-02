//# include <stdio.h>		/* printf, perror, strerror	*/
//# include <stdlib.h>	/* malloc, free, exit		*/
//# include <unistd.h>	/* close, write, read		*/
//# include <stddef.h>	/* size_t					*/
//# include <fcntl.h>		/* open						*/

#include "hdrs/so_long.h"


int	main(int ac, char *av[])
{
	printf("%c\n", 010 << 1);

	return (0);
}
