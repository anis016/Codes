#include<stdio.h>
#define MAX 31

long A[MAX][MAX];
long n;

void init(void )
{
	long i, j;

	for(i=0; i<=MAX; i++)
		for(j=0; j<=MAX; j++)
			A[i][j] = 0;
	return ;
}

void remove_cycle(void )
{
	long i, j, k;

	for(k=0; k<n; k++)
	{
		if(A[k][k] > 0)
		{
			for(i=0; i<n; i++)
				for(j=0; j<n; j++)
				{
					if(A[i][k] != 0 && A[k][j] != 0)
						A[i][j] = -1;
				}
		}
	}
	return ;
}

void transitive_clousure(void )
{
	long i, j, k;

	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				A[i][j] = A[i][j] + (A[i][k] * A[k][j]) ;
	return ;
}

void print(void )
{
	long i, j;

	for(i=0; i<n; i++)
	{
		for(j=0; j<n-1; j++)
			printf("%ld ", A[i][j]);
		printf("%ld", A[i][j]);
		printf("\n");
	}

	init();
	return ;
}

int main()
{
//	freopen("125.txt", "r", stdin);
	long i, m, t, x, y;

	t=0;
	while(scanf("%ld", &m)==1)
	{
		n=0;
		printf("matrix for city %ld\n", t++);

		n=-1;
		for(i=0; i<m; i++)
		{
			scanf("%ld %ld", &x, &y);
			A[x][y] = 1;
			if(x > n) 
				n = x;
			if(y > n) 
				n = y;
		}
		n++;
		
		transitive_clousure();
		remove_cycle();
		print();	
	}

	return 0;
}