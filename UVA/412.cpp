#include<stdio.h>
#include<math.h>

long gcd(long a, long b)
{
    return ((b == 0)? a : gcd(b, a%b));
}

int main()
{
	long a, b, kase, hold[1000];
	long i, count, l, j, nat;


	while(scanf("%ld", &kase), kase)
	{
		nat=0;
		for(i=0; i<kase; i++)
		{
			hold[i]=0;
			scanf("%ld", &hold[i]);
		}

		count=0;
		for(i=0, l=0, j=0; l<kase-1; i++)
		{
			a=hold[i];
			while(l<(kase-1))
			{
				b=hold[l+1];
				if(gcd(a, b)==1)
					count++;
				l++;
			}
			l=++j;
		}
		if(count==0)
		{
			printf("No estimate for this data set.\n");
			continue;
		}
	
		printf("%.6f\n", sqrt(6.0 * (double)(kase * (kase - 1) / 2) / (double)count));
	}
	return 0;
}