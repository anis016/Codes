#include<stdio.h>

#define MAX 1100

long c[MAX][MAX];
long X[MAX], Y[MAX];

long LCS_LENGTH(long n)
{
	long i, j;

	for(i=0; i<=n; i++)
		c[i][0]=0;
	for(j=0; j<=n; j++)
		c[0][j]=0;

	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
		{
			if(X[i-1]==Y[j-1])
				c[i][j]=c[i-1][j-1]+1;

			else if(c[i-1][j]>=c[i][j-1])
				c[i][j]=c[i-1][j];
			
			else
				c[i][j]=c[i][j-1];
		}

	return c[n][n];
}

long kept[MAX], hold[MAX], in1[MAX], in2[MAX];

int main()
{
	long ii, jj, n;

	scanf("%ld", &n);
		
		for(ii=1, jj=0; ii<=n; jj++, ii++)		
			kept[jj]=ii;
		
		for(ii=0; ii<n; ii++)
			scanf("%ld", &in1[ii]);

		for(ii=0, jj=1; ii<n; jj++, ii++)
		{
			X[in1[jj-1]-1]=kept[ii];
		}

		while(scanf("%ld", &in2[0])==1)
		{
			for(ii=1; ii<n; ii++)
				scanf("%ld", &in2[ii]);
			
			for(ii=0, jj=1; ii<n; jj++, ii++)
			{
				Y[in2[jj-1]-1]=kept[ii];
			}
			
			printf("%ld\n", LCS_LENGTH(n) );
		}
	
	return 0;
}

/*
                            0 1 2 3 4 5 6  7 8 9
1  2 3 4 5 6 7  8 9 10      1 2 3 4 5 6 7  8 9 10
3  1 2 4 9 5 10 6 8 7  ===> 2 3 1 4 6 8 10 9 5 7
2 10 1 3 8 4 9  5 7 6  ===> 3 1 4 6 8 10 9 5 7 2
*/
