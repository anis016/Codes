#include<cstdio>
#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 2000

long c[MAX][MAX], N;
long sorted[MAX], unsort[MAX];
long hold[MAX];

long LCS_LENGTH()
{
	long i, j;

	for(i=0; i<=N; i++)
		c[i][0]=0;
	for(j=0; j<=N; j++)
		c[0][j]=0;

	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
			if(sorted[i-1]==unsort[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
			}
			else
			{
				c[i][j]=c[i][j-1];
			}

	return c[N][N];
}

long print()
{
	long i, j, k;

	for(k=0, i=N, j=N; i>=1 && j>=1; )
	{
		if(sorted[i-1]==unsort[j-1])
		{
			hold[k]=sorted[i-1];
			k++;
			i--;
			j--;
		}
		else if(c[i-1][j]>c[i][j-1])
			i--;
		else
			j--;
	}

	return k;
}

int fun_name(  const void *a, const void *b )
{
	long *p = (long *)a;  
	long *q = (long *)b;  
	
	return *p - *q ;   // 1st - 2nd if Increasing
}

int main()
{
	long n, ii, i, out, k;
	char temp[MAX];

	gets(temp);
	sscanf(temp, "%ld", &n);
	gets(temp);
	while(n--)
	{
		ii=0;
		while(gets(temp))
		{
			if(strcmp(temp, "")==0)
				break;

			unsort[ii]=atoi(temp);
			sorted[ii]=unsort[ii];
			ii++;
		}

		N=ii;

		qsort( sorted, N, sizeof(long), fun_name );
		out=LCS_LENGTH();
		k=print();

		printf("Max hits: %ld\n", out);

		for(i=k-1; i>=0; i--)
		{
			printf("%ld\n", hold[i]);
		}

		if(n!=0)
            printf("\n");
	}
	return 0;
}