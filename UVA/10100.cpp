#include<cstdio>
#include<string.h>
#include<cstring>
#include<iostream>
using namespace std;

#define MAX 1500

long c[MAX][MAX], b[MAX][MAX], i, j;

struct List
{
	char X[MAX];
	char Y[MAX];
}list[MAX];


long LCS_LENGTH(long m, long n)
{
	for(i=0; i<=m; i++)
		c[i][0]=0;
	for(j=0; j<=n; j++)
		c[0][j]=0;

	for(i=1; i<=m; i++)
		for(j=1; j<=n; j++)
			if(strcmp(list[i-1].X, list[j-1].Y)==0)
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

char *delms = " ~!@#$%^&*()_+`-=[]{}|;\':,.<>/?\\\"\n\t";

int main()
{
	long ff, N, M, con;
	char in1[MAX], in2[MAX], *ch;

	
	con=1;
	while(gets(in1))
	{
		gets(in2);
		
		if(strcmp(in1, "")==0 || strcmp(in2, "")==0)
		{
			printf("%2ld. Blank!\n", con++);
			continue;
		}

		M=0;
		ch=strtok(in1, delms);
		while(ch)
		{
			strcpy(list[M].X, ch);
			ch=strtok(NULL, delms);
			M++;
		}
		
		N=0;
		ch=strtok(in2, delms);
		while(ch)
		{
			strcpy(list[N].Y, ch);
			ch=strtok(NULL, delms);
			N++;
		}
		
		ff=LCS_LENGTH(M, N);
		printf("%2ld. Length of longest match: %ld\n",con++, ff);
	}
	return 0;
}
