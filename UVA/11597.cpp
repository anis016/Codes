#include<stdio.h>

int main()
{
	long n, i;

	i=0;
	while(scanf("%ld", &n), n)
	{
		printf("Case %ld: %ld\n", ++i, (n/2));
	}

	return 0;
}
