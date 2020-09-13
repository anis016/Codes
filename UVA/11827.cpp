#include<stdio.h>
#include<string.h>
#define MAX 1000

int store[MAX];

int GCD(int a,int b)
{
	int t;
	while(a % b)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return b;
}

int main()
{
	int a, b, N, M, i, gcd, j, max;
	char xx[MAX], *p;

	gets(xx);
	sscanf(xx, "%d", &N);

	while(N--)
	{
		M = 0;
		gets(xx);

		p = strtok(xx, " ");
		while(p != NULL)
		{
			sscanf(p, "%d", &store[M++]);		
			p = strtok(NULL, " ");
		}

		max = -1;
		for(i = 0; i < M; i++)
			for(j = i + 1; j < M; j++)
			{
				a = store[i];
				b = store[j];
				
				gcd = GCD(a, b);
				if(gcd > max)
					max = gcd;
			}

		printf("%d\n", max);
	}
	return 0;
}
