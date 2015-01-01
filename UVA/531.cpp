#include<stdio.h>
#include<string.h>

#define MAX 1000

long c[MAX][MAX], b[MAX][MAX], N, M;
char X[MAX][MAX], Y[MAX][MAX];
char hold[MAX][MAX];

void LCS_LENGTH()
{
	long i, j, k;
	for(i=0; i<=M; i++)
		c[i][0]=0;
	for(j=0; j<=N; j++)
		c[0][j]=0;

	for(i=1; i<=M; i++)
		for(j=1; j<=N; j++)
			if(strcmp(X[i-1], Y[j-1])==0)
			{
				c[i][j]=c[i-1][j-1]+1;
			}
			else if(c[i-1][j]>c[i][j-1])
			{
				c[i][j]=c[i-1][j];
			}
			else
			{
				c[i][j]=c[i][j-1];
			}
}

long print()
{
	long i, j, k;

	for(k=0, i=M, j=N; i>=1 && j>=1; )
	{
		if(strcmp(X[i-1], Y[j-1])==0)
		{
			strcpy(hold[k], X[i-1]);
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

int main()
{
	long con, i, k;
	
	con=0;
	while(scanf("%s", X[0])!=EOF)
	{
		con=1;
		while(scanf("%s", X[con]) && X[con][0]!='#')
			con++;
		M=con;

		con=0;
		while(scanf("%s", Y[con]) && Y[con][0]!='#')
			con++;
		N=con;
		
		LCS_LENGTH();
		k=print();
	
		for(i=k-1; i>=1; i--)
		{
			printf("%s ", hold[i]);
		}
		printf("%s\n", hold[0]);
	}
	return 0;
}
