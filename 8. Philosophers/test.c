#include "hdrs/philo.h"

void foo(long long **res)
{
	**res += 100;
}

int main()
{
	long long *res;

	res = ft_calloc(1, sizeof(long long));
	foo(&res);
	printf("%lld", *res);
	return (0);
}