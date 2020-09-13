#include<stdio.h>

int main()
{
	long n, m , k;

	while(scanf("%ld %ld %ld", &n, &m, &k), n, m, k)
	{
		if (m%2==0) 
			printf("Gared\n"); 
		else 
			printf("Keka\n");
	}

	return 0;
}