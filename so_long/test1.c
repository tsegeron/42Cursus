//# include <stdio.h>		/* printf, perror, strerror	*/
//# include <stdlib.h>	/* malloc, free, exit		*/
//# include <unistd.h>	/* close, write, read		*/
//# include <stddef.h>	/* size_t					*/
//# include <fcntl.h>		/* open						*/

#include "hdrs/so_long.h"

//void do_stuff(int i)
//{
//}

int ran(void) {
	static int i = 0;

	if (i)
		i--;
	else
		i++;
	int *m = malloc(4);

	int u = ((int)m) + i;

	printf("%d\n", u % 10);
	free(m);
	return (u);
}

int	main(int ac, char *av[])
{
//	int i = 1;
//	printf("%d\n", 4001/2000%2);


//	int random = open("/dev/random", O_RDONLY);
//
//	char buf[1 * 4];
//
//	read(random, buf, 4);
//
//	unsigned int *r = (unsigned int *)buf;
//
//	int i = 0;
////	while(i < 10)
//		printf("%u ", r[i] % 10);
//	printf("\n");

	return (0);
}
