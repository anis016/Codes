#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define _min(a,b) a > b ? b : a
#define MAX 102
#define INF 0xfffffff

int mat[MAX][MAX];
int N;

void Flyod_Warshall() 
{
	int i, j, k;
	for(k = 1; k <= N; k ++)
		for(i = 1; i <= N; i++)
			for(j = 1; j <= N; j++)
				mat[i][j] = _min(mat[i][j],mat[i][k]+mat[k][j]);
}

void Cal() 
{
	int i, min = 0;

	Flyod_Warshall();
	for(i = 1; i <= N; i++ ) 
	{
		if(mat[1][i] > min)
			min = mat[1][i];
	}
	printf("%d\n",min);

}

void Ini() 
{
	int i;
	for(i = 1; i<=N; i++)
		mat[i][i] = 0;
}

int main() 
{
	int i, j;
	char dummy[MAX];

	while(scanf("%d",&N) == 1) 
	{
		Ini();
		for(i = 2; i <= N; i++) 
		{
			for(j = 1; j < i; j++) 
			{
				scanf("%s",dummy);
				if(strcmp(dummy,"x") == 0)
					mat[j][i] = mat[i][j] = INF;
				else
					mat[i][j] = mat[j][i] = atoi(dummy);
			}
		}
		if(N == 1) 
		{
			printf("0\n");
			continue;
		}
		Cal();
	}
	return 0;
}
