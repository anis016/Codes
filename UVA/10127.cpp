#include<stdio.h>
typedef long tall;

int main()
{
	tall N, k, hold;
	tall count;

	while(scanf("%lld", &N)==1)
	{
		hold=0;
		count=1;
		k=1;

		while(1)
		{
			if(N>k)
			{
				k=k*10+1;
			}
			hold=k%N;
			k=hold;
			count++;
			if(hold==0)
				break;
		}
		printf("%lld\n", count);
	}
	return 0;
}