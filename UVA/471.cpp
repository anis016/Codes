#include<stdio.h>

typedef long long LL;

#define MAX 9876543210

LL check(LL N)
{
	LL b, a, st;

	a = 0;
	while(N)
	{
		st = N % 10;
		b = 1 << st;
		if(a & b)
			return 0;
		a = a | b;

		N = N /10;
	}
	return 1;
}

int main()
{
	LL N, i, res, Case;

	scanf("%lld", &Case);
	while(Case--)
	{
		scanf("%lld", &N);
		for(i=1;  i<=MAX/N; i++)
		{
			res = i * N;
			
			if(res > MAX) 
				break; 

			if(check(res)==1 && check(i)==1)
				printf("%lld / %lld = %lld\n", res, i, N);
		}
		if(Case>0)
			printf("\n");
	}
	return 0;
}
