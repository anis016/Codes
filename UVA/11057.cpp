#include<stdio.h>
#include<stdlib.h>
#define MAX 200010
#define INF 10000000

long num[MAX];

int fun_name(  const void *a, const void *b )
{
	long *p = (long *)a;  
	long *q = (long *)b;  

	
	return *q - *p ;   
}

int main()
{
	long i, sum, res, min, N, k, diff, f, s;
	while(scanf("%ld", &N)==1)
	{
		for(i=0; i<N; i++)
			scanf("%ld", &num[i]);
		
		scanf("%ld", &res);

		min = INF;
		qsort(num, N, sizeof(long), fun_name );

		for(i=0, k=N-1; i<N; k=N-1, i++)
		{
			sum = 0;
			while(k>i)
			{
				sum = num[i] + num[k];
				if(sum == res)
				{
					diff = num[i] - num[k];
					if(diff < min)
					{
						min = diff;
						f = num[i];
						s = num[k];
					}
					break;
				}
				else if(sum > res)
					break;
				k--;
			}
		}
		printf("Peter should buy books whose prices are %ld and %ld.\n\n", s, f);
	}
	return 0;
}