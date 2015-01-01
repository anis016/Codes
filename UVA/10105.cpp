#include<stdio.h>
#define MAX 100

long fact(long x)
{
	long i;
	long result = 1;

	for(i=2; i<=x; i++)
		result=result*i;
	
	return result;
}

int main()
{
	long i, j, n, k, res, res1, hold[MAX], fin;

	while(scanf("%ld %ld", &n, &k)==2)
	{
		res=fin=0;
		res1=1;

		for(i=0 ;i<k ;i++)
			scanf("%ld", &hold[i]);
	
		res=fact(n);

		for(j=0; j<k; j++)
			res1=res1*fact(hold[j]);

		fin=res/res1;
		printf("%ld\n", fin);
	}
	return 0;
}