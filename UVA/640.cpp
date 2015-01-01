#include<cstdio>
#define MAX 1000001

long digit[MAX+100];
void init()
{
	long mod=0;
	long sum, hold, in, i, k;

	k=0;

	for(i=1; i<=MAX; i++)
	{
		in=i;
		hold=i;

		sum=0;
		while(1)
		{
			if(in==0)
				break;

			mod=in%10;
			in=in/10;
			sum+=mod;
		}
		sum=hold+sum;
		digit[sum]=1;
		k++;
	}
}

int main()
{
	long j;

	init();
	for(j=1; j<MAX; j++)
	{
		if(digit[j]==0)
			printf("%ld\n", j);
	}

	
	return 0;
}
