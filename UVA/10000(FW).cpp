#include<stdio.h>
#include<iostream>
using namespace std;

#define MAX 110
#define INF -100000000

long A[MAX][MAX];

void init(void)
{
	long i, j;

	for(i=0; i<=MAX; i++)
		for(j=0; j<=MAX; j++)
			A[i][j]=INF;

	return ;
}

long max(long st, long nd)
{
	if(st<nd)
		return nd;
	else
		return st;
}

void warshall(long n)
{
	long i, k, j, st, nd;

    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
			{
				st=A[i][j];
				nd=A[i][k] + A[k][j];
				
				A[i][j]=max(st, nd);
			}
	return ;
}

int main()
{
	long vertex, j, counter=0, x, y, path, max, start;
	
	while(scanf("%ld", &vertex), vertex)
	{
		scanf("%ld", &start);
		
		init();
		while(1)
		{
			scanf("%ld %ld", &x, &y);
			if(x==0 && y==0)
				break;

			A[x][y]=1;
		}

		warshall(vertex);

		max=-1;
		path=-1;
		for(j=0; j<=vertex; j++)
			if(A[start][j]>max)
			{
				max=A[start][j];
				path=j;
			}

			printf("Case %ld: The longest path from %ld has length %ld, finishing at %ld.\n", ++counter, start,  max, path);
			printf("\n");
	}
	return 0;
}