#include<stdio.h>

int main()
{
	long long n=0 ,k=0, k_1=0, n_1;
	long long hold=0;

	while(scanf("%lld %lld", &n, &k)!=EOF)
	{
		k_1=k-1;
		n_1=n-1;
		hold = n+(n_1/k_1);
		printf("%lld\n", hold);
	}
	return 0;
}