#include<stdio.h>
#define MAX 1001

long C[MAX][MAX], Vi[MAX], Wi[MAX];

long max(long a, long b)
{
	if(a>b)
		return a;
	else
		return b;
}


long knapsack(long N, long MW)
{
	long i, w, a, b;

	for (i=0;i<=N ;i++) 
		C[i][0] = 0;

	for (w=0;w<=MW;w++) 
		C[0][w] = 0;
	
	for (i=1;i<=N;i++)
		for (w=1;w<=MW;w++) 
		{  
			if (Wi[i] > w) 
				C[i][w] = C[i-1][w];
			else
			{
				a=C[i-1][w];
				b=C[i-1][w-Wi[i]]+Vi[i];
				
				C[i][w] = max(a, b);
			}
		}
		return (C[N][MW]);
}

int main()
{
	long i;
	long test, N, G, MW, max, sum;

	scanf("%ld", &test);
	while(test--)
	{
		scanf("%ld", &N);
		for(i=1; i<=N; i++)
			scanf("%ld %ld", &Vi[i], &Wi[i]);

		scanf("%ld", &G);

		max=sum=0;
		for(i=0; i<G; i++)
		{
			scanf("%ld", &MW);
			max=knapsack(N, MW);

			sum+=max;
		}
		
		printf("%ld\n", sum);
	}

	return 0;
}