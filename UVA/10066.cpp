#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;

#define MAX 110

long c[MAX][MAX], b[MAX][MAX], m, n, i, j;
long X[MAX], Y[MAX];

long LCS_LENGTH()
{
	for(i=0; i<=m; i++)
		c[i][0]=0;
	for(j=0; j<=n; j++)
		c[0][j]=0;

	for(i=1; i<=m; i++)
		for(j=1; j<=n; j++)
			if(X[i-1]==Y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;   /// corner
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=2;  /// up
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=3;  /// horizontal
			}
	return c[m][n];
}

int main()
{
	long test=0, ff, ss;
	while(scanf("%ld %ld", &m, &n), m, n)
	{
		for(ff=0; ff<m; ff++)
			scanf("%ld", &X[ff]);

		for(ss=0; ss<n; ss++)
			scanf("%ld", &Y[ss]);

		printf("Twin Towers #%ld\n", ++test);
		printf("Number of Tiles : %ld\n", LCS_LENGTH());	
		printf("\n");
	}	
	return 0;
}
