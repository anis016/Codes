#include<stdio.h>
#include<math.h>

int main()
{
	double res;
	long n, L;
	
	while(scanf("%ld", &n), n)
	{
		L = ceil(log(n) - log(2.0));
		res = 1 - exp(log(n) - L);

		printf("%ld %0.8lf\n", L, res);
	}

	return 0;
}