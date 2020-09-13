#include<stdio.h>

int main()
{
	long N, TB, RB, count;

	while(scanf("%ld", &N)==1)
	{
		if(N==1)
		{
			printf("1\n");
			continue;
		}

		RB = TB = 999999999;
		count = N;
		N = N + 1;

		while( N >= 3)
		{
			count += TB = N / 3;
			RB = N % 3;
			N = RB + TB;
		}
		printf("%ld\n", count);
	}
	return 0;
}