#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
#define MAX 1001

long c[MAX][MAX];
char b[MAX][MAX];
char X[MAX], Y[MAX];
long m, n;

void init()
{
	int i, j;
	for(i=0; i<=m; i++)
		c[i][0]=0;
	for(j=0; j<=n; j++)
		c[0][j]=0;
}

void LCS()
{
	int i, j;

	for(i=1; i<=m; i++)
		for(j=1; j<=n; j++)
			if(X[i-1]==Y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='c';
			}

			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]='u';
			}

			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]='h';
			}
}


int main()
{
	long test=0;
	while(gets(X))
	{
		gets(Y);
			
		m=strlen(X);
		n=strlen(Y);
		init();

		LCS();
		printf("%ld\n", c[m][n]);
	}
	return 0;
}
