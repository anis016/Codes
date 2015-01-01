#include<stdio.h>
#include<math.h>

long divisors(long in)
{
	long M, i, j, k, countm, countd;

	countm=countd=0;
	M=sqrt(in);
	for(i=1; i<=M; i++)
	{
		j=in%i;
		k=in/i;

		if(j==0)
		{
			countm=(countm+2);
		}
	    if(j==0 && k==i)
		{
			countd=countm-1;
		}
		else
			countd=countm;
	}
	return countd;
}

int main()
{
	long max, min;
	long i, count, L, U, test;

	scanf("%ld", &test);

	while(test--)		
	{
		scanf("%ld %ld", &L, &U);

		count=0;
		max=0;
		min=0;
		for(i=L; i<=U; i++)
		{
			count=divisors(i);
			if(count>max)
			{
				max=count;
				min=i;
			}
		}
		printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n", L, U, min, max);
	}

	return 0;
}